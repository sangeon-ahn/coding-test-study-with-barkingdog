#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[1000][1000];
int vis[1000][1000];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  int ans = 0;
  int count = 0;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      board[i][j] = x;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j] || board[i][j] == 0) continue;
      int sum = 0;
      queue<pair<int, int>> Q;
      vis[i][j] = 1;
      Q.push({i, j});
      count++;
      while (!Q.empty()) {
        pair<int, int> A = Q.front();
        Q.pop();
        sum++;
        for (int i = 0; i < 4; i++) {
          int nx = A.first + dx[i];
          int ny = A.second + dy[i];
          if (n <= nx || 0 > nx || m <= ny || 0 > ny) continue;
          if (vis[nx][ny] || board[nx][ny] == 0) continue;
          vis[nx][ny] = 1;
          Q.push({nx, ny});
        }
      }
      ans = max(ans, sum);
    }
  }
  cout << count << '\n' << ans;
}