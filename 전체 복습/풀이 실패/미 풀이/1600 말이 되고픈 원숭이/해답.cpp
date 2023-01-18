#include <bits/stdc++.h>
using namespace std;

int board[202][202];

// 32는 뭘까. K였다.
// vis[i][j][j]: 
int vis[32][202][202];
int dmx[4] = { 0, 0, 1, -1 };
int dmy[4] = { 1, -1, 0, 0 };
int dkx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dky[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };

// tuple이란게 있었구나.
queue<tuple<int, int, int>> Q;
int bX, bY, Kn;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> Kn >> bY >> bX;

  for (int i = 0; i < bX; i++) {
    for (int j = 0; j < bY; j++) {
      cin >> board[i][j];
    }
  }

  Q.push({0, 0, 0});
  vis[0][0][0] = 1;

  while (!Q.empty()) {
    int vk, vx, vy;
    tie(vk, vx, vy) = Q.front();
    Q.pop();

    // 말 모드
    if (vk < Kn) {
      for (int i = 0; i < 8; i++) {
        int nx = vx + dkx[i], ny = vy + dky[i];

        // 보드 밖이면 패스.
        if (nx < 0 || ny < 0 || bX <= nx || bY <= ny) continue;

        // 장애물 위치면 패스.
        if (board[nx][ny]) continue;

        // 이미 vk + 1번 말모드 사용해서 방문한 곳이면 패스.
        // 같은 곳을 방문했더라도 말모드를 0번 사용했는지, 1번 사용했는지에 따라 다른 경로이기 때문에 x,y에 추가적으로 사용된 말모드의 수를 담는 차원을 추가했다.
        if (vis[vk + 1][nx][ny]) continue;
        
        // 나머지 경우.(vx, vy) 도달하는데 말모드를 vk + 1번 사용해서 도착했다.
        vis[vk + 1][nx][ny] = vis[vk][vx][vy] + 1;
        Q.push({vk + 1, nx, ny});
      }
    }

    // 상하좌우 4방향.
    for (int i = 0; i < 4; i++) {
      int nx = vx + dmx[i], ny = vy + dmy[i];

      if (nx < 0 || ny < 0 || bX <= nx || bY <= ny) continue;
      if (board[nx][ny]) continue;
      if (vis[vk][nx][ny]) continue;
      vis[vk][nx][ny] = vis[vk][vx][vy] + 1;
      Q.push({vk, nx, ny});
    }
  }

  int ans = 0x7f7f7f7f;
  
  for (int i = 0; i < Kn + 1; i++) {
    if (vis[i][bX - 1][bY - 1]) {
      ans = min(ans, vis[i][bX - 1][bY - 1]);
    }
  }

  if (ans != 0x7f7f7f7f) cout << ans - 1;
  else cout << -1;
}