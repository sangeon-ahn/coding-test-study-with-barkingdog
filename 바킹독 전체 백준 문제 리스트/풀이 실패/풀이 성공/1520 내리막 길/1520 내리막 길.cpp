#include <bits/stdc++.h>
using namespace std;
// 1트(16분): 시간초과

int M, N;
int board[501][501];
bool vis[501][501];
long long result;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y) {
  // 도착지에 도달하면 result++ 후 종료.
  if (x == M - 1 && y == N - 1) {
    result++;
    return;
  }

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    // 보드를 벗어나는 경우 패스.
    if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
    
    // 다음 수가 현재 수보다 작고 방문 안한 경우만 로직 실행.
    if (board[x][y] > board[nx][ny] && !vis[nx][ny]) {
      vis[nx][ny] = true;
      dfs(nx, ny);
      vis[nx][ny] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> M >> N;

  // 높이 정보 받기.
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  // dfs 수행.
  vis[0][0] = true;
  dfs(0, 0);

  cout << result;
}