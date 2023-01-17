#include <bits/stdc++.h>
using namespace std;

int M, N;
int board[500][500];
int dp[500][500];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

long long dfs(int x, int y) {
  // (M - 1, N - 1)에 도달했으면 dp[x][y] = 1;
  if (x == M - 1 && y == N - 1) {
    dp[x][y] = 1;
    return 1;
  }

  // 일단 들어왔으면 0.
  dp[x][y] = 0;

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
      if (board[x][y] > board[nx][ny]) {
        dp[x][y] += dfs(nx, ny);
      }
    }
  }

  return dp[x][y];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> M >> N;

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < 500; i++) {
    for (int j = 0; j < 500; j++) {
      fill(dp[i], dp[i] + 500, -1);
    }
  }

  cout << dfs(0, 0);
}