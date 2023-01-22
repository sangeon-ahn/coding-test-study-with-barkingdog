#include <iostream>
#include <string>
#include <queue>
using namespace std;


int board[1000][1000];
int dist[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> M >> N;
  queue<pair<int, int>> Q;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j] == 1) {
        Q.push({i, j});
      }
      if (board[i][j] == 0) {
        dist[i][j] = -1;
      }
    }
  }

  while (!Q.empty()) {
    pair<int, int> p = Q.front(); Q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];
      if (N <= nx || 0 > nx || M <= ny || 0 > ny) continue;
      if (dist[nx][ny] >= 0 || board[nx][ny] == -1) continue;
      dist[nx][ny] = dist[p.first][p.second] + 1;
      Q.push({nx, ny});
    }
  }
  int ans = 0;
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (dist[i][j] == -1) {
        cout << -1;
        return 0;
      }
      ans = max(ans, dist[i][j]);
    }
  }
  cout << ans;
}