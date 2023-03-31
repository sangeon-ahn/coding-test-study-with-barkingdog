#include <bits/stdc++.h>
using namespace std;

int N, M, G, R;
int board[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int visTime[2][51][51];
bool flowers[51][51];
int ans = 0;

vector<pair<int, int>> spots;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> G >> R;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];

      if (board[i][j] == 2) {
        spots.push_back({i, j});
      }
    }
  }

  vector<int> vec(spots.size(), 2);

  for (int i = 0; i < G + R; i++) {
    if (i < G) vec[i] = 0;
    else vec[i] = 1;
  }

  do {
    // 좌표, 색, 시간
    queue<pair<pair<int, int>, pair<int, int>>> q;

    memset(visTime, -1, sizeof(visTime));
    memset(flowers, false, sizeof(flowers));

    for (int i = 0; i < vec.size(); i++) {
      if (vec[i] == 0) {
        visTime[0][spots[i].first][spots[i].second] = 0;
        q.push({spots[i], {0, 0}});
      }
      else if (vec[i] == 1) {
        visTime[1][spots[i].first][spots[i].second] = 0;
        q.push({spots[i], {1, 0}});
      }
    }
  
    int result = 0;

    while (!q.empty()) {
      auto p = q.front(); q.pop();

      auto cur = p.first;
      int color = p.second.first;
      int time = p.second.second;

      // 이 조건을 찾느라 2시간 썼다.
      if (flowers[cur.first][cur.second]) continue;

      if (visTime[0][cur.first][cur.second] > 0 && visTime[0][cur.first][cur.second] == visTime[1][cur.first][cur.second]) {
        result++;
        flowers[cur.first][cur.second] = true;
        continue;
      }


      for (int i = 0; i < 4; i++) {
        int nx = cur.first + dx[i];
        int ny = cur.second + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (board[nx][ny] == 0) continue;
        if (visTime[color][nx][ny] >= 0) continue;
        if (flowers[nx][ny]) continue;
        if (visTime[!color][nx][ny] >= 0 && visTime[!color][nx][ny] != time + 1) continue;

        visTime[color][nx][ny] = time + 1;
        q.push({{nx, ny}, {color, time + 1}});
      }
    }

    ans = max(ans, result);
  } while (next_permutation(vec.begin(), vec.end()));
  cout << ans;
}
