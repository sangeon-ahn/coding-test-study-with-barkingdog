#include <bits/stdc++.h>
using namespace std;

string board[5];
bool mask[25];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 5; i++) {
    cin >> board[i];
  }

  fill(mask + 7, mask + 25, true);
  do
  {
    queue<pair<int, int>> q;
    int dasom = 0;
    int adj = 0;
    bool isPrince[5][5] = {};
    bool vis[5][5] = {};

    for (int i = 0; i < 25; i++) {
      // 공주자리. 이다솜파면
      if (!mask[i]) {
        int x = i / 5, y = i % 5;
        isPrince[x][y] = true;

        if (q.empty()) {
          q.push({x, y});
          vis[x][y] = true;
        }
      }

    }

    while (!q.empty()) {
      auto p = q.front(); q.pop();
      adj++;
      dasom += board[p.first][p.second] == 'S';
      
      for (int i = 0; i < 4; i++) {
        int nx = p.first + dx[i];
        int ny = p.second + dy[i];

        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || vis[nx][ny] || !isPrince[nx][ny]) continue;
        q.push({nx, ny});
        vis[nx][ny] = true;
      }
    }

    ans += adj >= 7 && dasom >= 4;
  } while (next_permutation(mask, mask + 25));

  cout << ans;
}