#include <bits/stdc++.h>
using namespace std;

int M, N;
int board[500][500];
// dp[i][j]: (i,j)에서 (M-1,N-1)까지 갈 수 있는 경로의 개수.
int dp[500][500];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

long long dfs(int x, int y) {
  // (M - 1, N - 1)에 도달했으면 dp[x][y] = 1;
  if (x == M - 1 && y == N - 1) return 1;

  // 이미 dp에 캐시되어 있으면 dp값 반환.
  if (dp[x][y] != -1) return dp[x][y];

  // 일단 들어왔으면 dp = 0.
  dp[x][y] = 0;

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    // 보드 내에 있고, 다음 높이가 더 낮으면,
    if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
      if (board[x][y] > board[nx][ny]) {
        // x,y에서 M-1,N-1까지의 경로는 x,y의 상하좌우 중 자신보다 작은 값에서 M-1,N-1로 갈 수 있는 경로의 합이다.
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

  //dfs(i, j): (i, j)에서 (M - 1, N - 1)로 갈 수 있는 경로의 개수.
  cout << dfs(0, 0);
}