#include <bits/stdc++.h>
using namespace std;
// 풀이 시간: 18분
int N, M;
map<int, string> m1;
map<string, int> m2;

bool checkInput(string s) {
  int temp = s[0] - '0';

  if (0 < temp && temp < 10) return true;
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  // 맵 2개에 포켓몬 정보 넣기.
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    m1[i + 1] = s;
    m2[s] = i + 1;
  }

  // 질문에 대답하기
  for (int i = 0; i < M; i++) {
    string s;
    cin >> s;
    
    bool isInt = checkInput(s);

    if (isInt) {
      cout << m1[stoi(s)] << '\n';
    } else cout << m2[s] << '\n';
  }
}