#include <bits/stdc++.h>
using namespace std;

int N;
int board[100][100];
string ans;

string dfs(int a, int b, int length) {
  if (length == 1) {
    return to_string(board[a][b]);
  }

  bool flag = true;
  int first = board[a][b];

  for (int i = a; i < length; i++) {
    if (!flag) break;

    for (int j = b; j < length; j++) {
      if (board[i][j] != first) {
        flag = false;
        break;
      }
    }
  }
  
  if (flag) return to_string(board[a][b]);

  return '(' + dfs(a, b, length / 2) + dfs(a + length / 2, b, length / 2) + dfs(a, b + length / 2, length / 2) + dfs(a + length / 2, b + length / 2, length / 2) + ')';
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

  cout << dfs(0, 0, N);
}