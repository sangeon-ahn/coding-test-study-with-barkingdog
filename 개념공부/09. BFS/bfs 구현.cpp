#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int board[101][101];
int vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int A;
      cin >> A;
      board[i][j] = A;
    }
  }

  queue<pair<int, int>> Q;
  Q.push({0, 0});
  vis[0][0] = 1;

  while (!Q.empty()) {
    int x = Q.front().first;
    int y = Q.front().second;
    // 이렇게 받아오기 가능
    // pair<int, int> cur = Q.front()
    Q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[0];
      int ny = y + dy[0];
      if (N <= nx || nx < 0 || M <= ny || ny < 0) continue;
      if (vis[nx][ny] == 1) continue;
      vis[nx][ny] = 1;
      Q.push({nx, ny});
    }
  }
}