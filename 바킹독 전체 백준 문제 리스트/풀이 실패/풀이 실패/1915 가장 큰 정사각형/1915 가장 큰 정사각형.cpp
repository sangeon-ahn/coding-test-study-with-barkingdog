/*
  1. 보드를 순회하다가 1이면 길이가 2인 정사각형을만들 수 있는지 확인, 되면 3 확인, 이런식으로 끝까지 확인
  or 2. 1*1 정사각형부터 max(m, n) * max(m, n) 정사각형까지 확인
*/
// 시간초과.
#include <bits/stdc++.h>
using namespace std;
int N, M;
int board[1010][1010];
int ans;

bool check(int a, int b, int d) {
  for (int i = a; i < a + d; i++) {
    for (int j = b; j < b + d; j++) {
      if (board[i][j] == 0) return false;
    }
  }
  return true;
}

bool canRectangle(int d) {
  for (int i = 0; i < N - d + 1; i++) {
    for (int j = 0; j < M - d + 1; j++) {
      if (check(i, j, d)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < M; j++) {
      board[i][j] = s[j] - '0';
    }
  }

  // 체크
  int maxLength = min(N, M);

  for (int i = 1; i <= maxLength; i++) {
    if (canRectangle(i)) {
      ans = i * i;
    }
  }

  cout << ans;
}