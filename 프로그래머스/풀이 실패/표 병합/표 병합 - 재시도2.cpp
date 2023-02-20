#include <bits/stdc++.h>
using namespace std;

vector<string> split(string str, char delimiter) {
  // stream 머시기에 s 넣고 getLine으로 받으면서 벡터에 넣고 리턴.
  string tmp;
  stringstream ss(str);
  vector<string> result;

  while (getline(ss, tmp, delimiter)) {
    result.push_back(tmp);
  }

  return result;
}

int uf[2501];
string values[2501];

int uf_find(int a) {
  // uf[a]에 아직 값이 없으면 a 반환, 있으면 uf_find(a) 반환하면서 uf[a]에 조상 값 넣기.
  return uf[a] == -1 ? a : uf[a] = uf_find(uf[a]);
}

bool uf_union(int a, int b) {
  int A = uf_find(a);
  int B = uf_find(b);

  if (A == B) return false;
  uf[B] = A;

  if (values[A].empty() && values[B].size()) values[A] = values[B];
  else values[B] = values[A];
  return true;
}

vector<string> solution(vector<string> commands) {
  vector<string> answer;
  memset(uf, -1, sizeof(uf));

  for (string command : commands) {
    vector<string> cmd = split(command, ' ');

    if (cmd[0] == "UPDATE") {
      if (cmd.size() == 4) {
        // uf에 추가, values에 추가
        int r = stoi(cmd[1]) - 1, c = stoi(cmd[2]) - 1;
        int pos = uf_find(50 * r + c);
        values[pos] = cmd[3];
      } else {
        // UPDATE korean hansik
        // union find 해서 조상을 찾은 다음, 그 조상이 가지고 있는 값이 korean이면 그 값을 hansik으로 바꾼다.
        for (int i = 0; i < 2500; i++) {
          int pos = uf_find(i);
          if (values[pos] == cmd[1]) values[pos] = cmd[2];
        }
      }
    } else if (cmd[0] == "MERGE") {
      // merge는 union을 한다.
      int r1 = stoi(cmd[1]) - 1, c1 = stoi(cmd[2]) - 1, r2 = stoi(cmd[3]) - 1, c2 = stoi(cmd[4]) -1;
      uf_union(50 * r1 + c1, 50 * r2 + c2);

    } else if (cmd[0] == "UNMERGE") {
      // 조상 재정의 후, 해당 셀을 조상으로 가지는 셀들을 모두 초기화한다. 그리고 처음에 선택된 셀에 그룹값을 넣는다.
      for (int i = 0; i < 2500; i++) {
        uf_find(i);
      }
      
      int idx = 50 * (stoi(cmd[1]) - 1) + stoi(cmd[2]) - 1;
      int pos = uf_find(idx);

      string val = values[pos];

      for (int i = 0; i < 2500; i++) {
        if (uf_find(i) == pos) {
          uf[i] = -1;
          values[i] = "";
        }
      }

      values[idx] = val;
    } else {
      // print r c
      int idx = 50 * (stoi(cmd[1]) - 1) + stoi(cmd[2]) - 1;
      int pos = uf_find(idx);

      if (!values[pos].empty()) answer.push_back(values[pos]);
      else answer.push_back("EMPTY");
    }
  }
  return answer;
}