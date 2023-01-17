#include <bits/stdc++.h>
using namespace std;

int M, N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dp[500][500];
int board[500][500];

long long dfs(int x, int y) {
  // 만약 (x, y) = (M-1, N-1)이면 1 리턴.
  if (x == M-1 && y == N-1) {
    return 1;
  }

  // 이미 dp가 있다면 dp 리턴.
  if (dp[x][y] != -1) return dp[x][y];

  // 뒤 두개가 아니면 처음 온것.
  dp[x][y] = 0;
  
  // 4방향 판단
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    // 보드 안에 있고, 다음 수가 현재 수보다 작으면 경로에 추가.
    if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
      if (board[x][y] > board[nx][ny]) {
        // dp 업데이트
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
      dp[i][j] = -1;
    }
  }
  // dfs(0, 0): (0, 0)에서 (M-1, N-1)로 가는 경로의 개수.
  cout << dfs(0, 0);
}