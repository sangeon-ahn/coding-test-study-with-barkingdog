#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[510][510];
bool vis[510][510];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans;
int maxSize;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }

  queue<pair<int, int>> q;
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      // 이미 방문했으면 패스.
      if (vis[i][j] || !board[i][j]) continue;

      // 방문 안했으면 시작.
      int paintSize = 1;
      ans++;
      q.push({i, j});
      vis[i][j] = true;

      while (!q.empty()) {
        auto p = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
          int nx = p.first + dx[i];
          int ny = p.second + dy[i];

          if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if (!vis[nx][ny] && board[nx][ny] == 1) {
              vis[nx][ny] = true;
              paintSize++;
              q.push({nx, ny});
            }
          }
        }
      }
      maxSize = max(maxSize, paintSize);
    }
  }
  cout << ans << '\n' << maxSize;
}