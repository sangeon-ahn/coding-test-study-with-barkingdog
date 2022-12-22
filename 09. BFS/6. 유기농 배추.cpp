#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[100][100];
int vis[100][100];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  
  while (T--) {
    int M, N, K;
    cin >> M >> N >> K;
    for (int i = 0; i < 100; i++) {
      fill(board[i], board[i]+99, 0);
      fill(vis[i], vis[i]+99, 0);
    }

    queue<pair<int, int>> Q;
    int ans = 0;
    for (int i = 0; i < K; i++) {
      int X, Y;
      cin >> X >> Y;
      board[Y][X] = 1;
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (vis[i][j] == 0 && board[i][j] == 1) {
          vis[i][j] = 1;
          Q.push({i, j});
          ans++;
          while (!Q.empty()) {
            auto p = Q.front(); Q.pop();
            for (int i = 0; i < 4; i++) {
              int nx = p.first + dx[i];
              int ny = p.second + dy[i];
              if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
              if (vis[nx][ny] == 1 || board[nx][ny] == 0) continue;
              vis[nx][ny] = 1;
              Q.push({nx, ny});
            }
          }
        }
      }
    }
    cout << ans << '\n';
  }
}