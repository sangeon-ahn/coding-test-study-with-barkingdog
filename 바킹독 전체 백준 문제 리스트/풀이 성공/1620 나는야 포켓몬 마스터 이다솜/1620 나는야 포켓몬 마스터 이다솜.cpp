#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> v;

bool isNumber(char c) {
  if (0 < c - '0' && c - '0' < 10) {
    return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  // 포켓몬 정보 저장.
  for (int i = 0; i < N; i++) {
    string name;
    cin >> name;
    v.push_back(name);
  }

  // 요청 내용 받기
  for (int i = 0; i < M; i++) {
    string s;
    cin >> s;
    
    // 숫자가 입력된 경우
    bool checkNumber = isNumber(s[0]);

    if (checkNumber) {
      cout << v[stoi(s) - 1] << '\n';
    }
    // 포켓몬 이름이 입력된 경우.
    else {
      auto it = find(v.begin(), v.end(), s);
      if (it != v.end()) cout << it - v.begin() + 1 << '\n';
    }
  }
}