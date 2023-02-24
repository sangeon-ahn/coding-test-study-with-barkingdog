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

string values[2501]; // (1, 1) 부터 시작
int uf[2501];

int uf_find(int a) { // 선택된 셀의 인덱스를 찾는 함수
    return uf[a] == -1 ? a : uf[a] = uf_find(uf[a]); // 재귀적으로 제일 위 조상이 누군지 찾는다. 부모가 아니라 조상이다.
}

bool uf_union(int a, int b) { // A가 B를 먹는다.
    int A = uf_find(a);
    int B = uf_find(b);

    if (A == B) return false;
    uf[B] = A; // B의 부모가 A이다. B는 b의 최고 조상, A는 a의 최고 조상

    if (values[A].empty() && values[B].size()) values[A] = values[B]; // A는 값이 없고 B는 값이 있으면 A는 B의 값을 가진다.
    else values[B] = values[A]; // 그 외의 경우에는 B가 A의 값을 가진다.
    return true;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    memset(uf, -1, sizeof(uf));

    for (string command : commands) {
        vector<string> cmd = split(command, ' ');
        
        if (cmd[0] == "UPDATE") {
            if (cmd.size() == 4) {
                // uf_find로 최고 조상 찾아서 값 변경
                int r = stoi(cmd[1]) - 1, c = stoi(cmd[2]) - 1;
                int pos = uf_find(50 * r + c);
                values[pos] = cmd[3];
            }
            else {
                // update val1 val2 => val1를 val2로 업데이트한다.
                for (int i = 0; i < 2500; i++) {
                  int pos = uf_find(i);
                  if (values[pos] == cmd[1]) values[pos] = cmd[2];
                }
            }
        }
        else if (cmd[0] == "MERGE") {
            // merge x1 y1 x2 y2 => x2, y2가 x1, y1에 머지된다.
            // x1, y1의 조상을 x2, y2의 조상으로 바꾸고 x2,y2 값 없애기
            // uf_union으로 결합. uf 업데이트
            
            // merge는 union을 한다.
            int r1 = stoi(cmd[1]) - 1, c1 = stoi(cmd[2]) - 1, r2 = stoi(cmd[3]) - 1, c2 = stoi(cmd[4]) -1;
            uf_union(50 * r1 + c1, 50 * r2 + c2);
        }
        else if (cmd[0] == "UNMERGE") {
            // uf_find 해서 조상 찾고 이 셀을 조상으로 가지는 셀들을 전부 초기화
            for (int i = 0; i < 2500; i++) {
              uf_find(i);
            }
            int idx = 50 * (stoi(cmd[1]) - 1) + stoi(cmd[2]) - 1;
            int p = uf_find(idx);

            string val = values[p];
            
            for (int i = 0; i < 2500; i++) {
              if (p == uf_find(i)) {
                  uf[i] = -1;
                  values[i] = "";
              }
            }

            values[idx] = val;
        }
        else {
            // 해당 셀의 조상을 찾아서 값을 answer에 넣기

            // int p = uf_find(50 * (stoi(cmd[1]) - 1) + stoi(cmd[2]) - 1);
            // if (values[p].empty()) answer.push_back("EMPTY");
            // else answer.push_back(values[p]);

            int idx = 50 * (stoi(cmd[1]) - 1) + stoi(cmd[2]) - 1;
            int pos = uf_find(idx);

            if (!values[pos].empty()) answer.push_back(values[pos]);
            else answer.push_back("EMPTY");
        }
    }
    
    return answer;
}