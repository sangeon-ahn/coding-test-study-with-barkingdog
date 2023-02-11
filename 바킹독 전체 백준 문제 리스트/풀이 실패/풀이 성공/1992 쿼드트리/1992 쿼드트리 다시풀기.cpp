#include <bits/stdc++.h>
using namespace std;

int N;
int board[64][64];

void solve(int length, int x, int y) {
  if (length == 1) {
    cout << board[x][y];
    return;
  }

  bool zero = true;
  bool one = true;

  for (int i = x; i < x + length; i++) {
    for (int j = y; j < y + length; j++) {
      if (!board[i][j]) one = false;
      else zero = false;
    }
  }

  if (one) cout << 1;
  else if (zero) cout << 0;
  else {
    cout << "(";
    solve(length / 2, x, y);
    solve(length / 2, x, y + length / 2);
    solve(length / 2, x + length / 2, y);
    solve(length / 2, x + length / 2, y + length / 2);
    cout << ")";
  }
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;

    for (int j = 0; j < s.size(); j++) {
      board[i][j] = s[j] - '0';
    }
  }

  solve(N, 0, 0);
}