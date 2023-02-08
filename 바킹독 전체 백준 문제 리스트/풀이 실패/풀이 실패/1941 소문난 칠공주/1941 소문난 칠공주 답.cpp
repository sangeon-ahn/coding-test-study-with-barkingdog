#include <bits/stdc++.h>
using namespace std;

bool mask[25];
string board[5];
int ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 5; i++) {
    cin >> board[i];
  }

  // 25명 중 칠공주가 될 사람의 후보 조합을 뽑습니다.
  fill(mask + 7, mask + 25, true);
  do
  {
    queue<pair<int, int>> q;

    // 구성원 중 이다솜파의 수
    int dasom = 0;

    // 가로세로로 인접한 사람의 수
    int adj = 0;

    bool isPrince[5][5] = {};
    bool vis[5][5] = {};

    for (int i = 0; i < 25; i++) {
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
      int x, y;
      tie(x, y) = q.front(); q.pop();
      adj++;
      dasom += board[x][y] == 'S';

      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || vis[nx][ny] || !isPrince[nx][ny]) continue;

        q.push({nx, ny});
        vis[nx][ny] = true;
      }
    }

    ans += (adj >= 7 && dasom >= 4);

  } while (next_permutation(mask, mask + 25));
  cout << ans;
}