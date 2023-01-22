#include <iostream>
#include <queue>
#include <string>
using namespace std;

// 풀이 실패.

// char board[1000][1000];
// int vis[1000][1000];
// int jpos[2];
// int fire[2];
// int dx[4] = {1, 0, -1, 0};
// int dy[4] = {0, 1, 0, -1};

// int main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   int R, C;
//   int ans = 100000;
//   cin >> R >> C;
//   queue<pair<int, int>> Q;

//   for (int i = 0; i < R; i++) {
//     for (int j = 0; j < C; j++) {
//       cin >> board[i][j];
//       if (board[i][j] == 'J') {
//         jpos[0] = i;s
//         jpos[1] = j;
//       }
//       if (board[i][j] == 'F') {
//         fire[0] == i;
//         fire[1] == j;
//       }
//     }
//   }
//   Q.push({jpos[0], jpos[1]});
//   Q.push({fire[0], fire[1]});

//   while (!Q.empty()) {
//     auto a = Q.front(); Q.pop();
//     for (int i = 0; i < 4; i++) {
//       int nx = a.first + dx[i];
//       int ny = a.second + dy[i];
//       if (board[nx][ny] == '#') continue;
//       if (board[nx][ny] == 'F') continue;
//       if (board[a.first][a.second] == 'J') {
//         if (nx == R-1 || nx == 0 || ny == C-1 || ny == 0) {
//           ans = min(ans, vis[nx][ny] + 1);
//           continue;
//         }
//         board[a.first][a.second] = '.';
//         vis[nx][ny] = vis[a.first][a.second] + 1;
//         Q.push({nx, ny});
//       }
//       if (board[a.first][a.second] == 'F') {
//         board[nx][ny] = 'F';
//         Q.push({nx, ny});
//       }
//     }
//   }
//   cout << ans;
// }

string board[1002];
int dist1[1002][1002];
int dist2[1002][1002];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    fill(dist1[i], dist1[i]+m, -1);
    fill(dist2[i], dist2[i]+m, -1);
  }
  for (int i = 0; i < n; i++) {
    cin >> board[i];
  }

  queue<pair<int, int>> Q1;
  queue<pair<int, int>> Q2;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 'F') {
        Q1.push({i, j});
        dist1[i][j] = 0;
      }
      if (board[i][j] == 'J') {
        Q2.push({i, j});
        dist2[i][j] = 0;
      }
    }
  }
  // 불 BFS
  while (!Q1.empty()) {
    auto cur = Q1.front(); Q1.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
      dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
      Q1.push({nx, ny});
    }
  }

  // 지훈 BFS
  while (!Q2.empty()) {
    auto cur = Q2.front(); Q2.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
        cout << dist2[cur.first][cur.second] + 1;
        return 0;
      }
      if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
      // 불의 전파 시간을 조건에 추가
      if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.first][cur.second] + 1) continue;
      dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
      Q2.push({nx, ny});
    }
  }
  cout << "IMPOSSIBLE";
}
