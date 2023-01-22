#include <bits/stdc++.h>
using namespace std;

int board[200][200];
int K, W, H;
bool vis[200][200];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

pair<int, int> horse[8] = {{-1, 2}, {-2, 1}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

int answer = 200000000;

pair<int, int> horseMode(int order, pair<int, int> point) {
  int nx = point.first + horse[order].first;
  int ny = point.second + horse[order].second;

  return {nx, ny};
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> K >> W >> H;

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> board[i][j];
    }
  }

  queue<pair<pair<int, int>, int>> q;
  vis[0][0] = true;
  q.push({{0, 0}, 0});

  while (!q.empty()) {
    auto p = q.front(); q.pop();

    for (int i = 0; i < 12; i++) {
      int nx, ny;
      if (i >= 4) {
        if (K > 0) {
          auto a = horseMode(i - 4, p.first);
          nx = a.second;
          ny = a.second;
          K -= 1;
        }
      } else {
        nx = p.first.first + dx[i];
        ny = p.first.second + dy[i];
      }

      if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
      if (board[nx][ny] == 1) continue;
      if (vis[nx][ny]) continue;
      // cout << nx << ' ' << ny << ' ' << p.second + 1 << '\n';
      if (nx == H - 1 && ny == W - 1) {
        answer = min(answer, p.second + 1);
        continue;
      }
      
      vis[nx][ny] = true;
      q.push({{nx, ny}, p.second + 1});
    }
  }

  if (answer == 200000000) {
    answer = -1;
  }

  cout << answer;
}