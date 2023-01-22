#include <iostream>
#include <string>
#include <queue>
using namespace std;


int board[100][100];
int vis[100][100];
int dist[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;
  queue<pair<int, int>> Q;
  vis[0][0] = 1;
  dist[0][0] = 1;
  Q.push({0, 0});
  for (int i = 0; i < N; i++) {
    string s1;
    cin >> s1;
    for (int j = 0; j < M; j++) {
      board[i][j] = s1[j] - '0';
    }
  }
  while (!Q.empty()) {
    pair<int, int> p = Q.front(); Q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];
      if (N <= nx || 0 > nx || M <= ny || 0 > ny) continue;
      if (vis[nx][ny] == 1 || board[nx][ny] == 0) continue;
      vis[nx][ny] = 1;
      dist[nx][ny] = dist[p.first][p.second] + 1;
      Q.push({nx, ny});
    }
  }
  cout << dist[N - 1][M - 1];
}