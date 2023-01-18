#include <bits/stdc++.h>
using namespace std;
// 테스트케이스O, 제출시 시간초과
/*
  dfs로 풀어보자.
*/

int K, W, H;
int board[200][200];
int vis[200][200];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

pair<int, int> horse[8] = {{-1, 2}, {-2, 1}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

int answer = 200000000;

pair<int, int> horseMode(int order, pair<int, int> point) {
  int nx = point.first + horse[order].first;
  int ny = point.second + horse[order].second;

  return {nx, ny};
}

void dfs(int x, int y, int count, int horse) {
  
  // 도착하면 answer값과 비교 및 리턴.
  if (x == H - 1 && y == W - 1) {
    answer = min(answer, count);
    return;
  }

  // 도착 안했으면 다음 밟을 땅 정하기
  for (int i = 0; i < 12; i++) {
    // i >= 4면 말 모드 실행.
    int nx, ny;
    int temp = horse;

    if (i >= 4) {
      if (temp > 0) {
        auto p = horseMode(i - 4, {x, y});
        nx = p.first;
        ny = p.second;
        temp--;
      }
    }
    else {
      nx = x + dx[i];
      ny = y + dy[i];
    }

    if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
    if (board[nx][ny] == 1) continue;
    if (vis[nx][ny]) continue;

    vis[nx][ny] = true;
    dfs(nx, ny, count + 1, temp);
    vis[nx][ny] = false;
  }
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

  // dfs(0, 0, 0): (0, 0)에서 (H-1, W-1) 까지 가는데 걸리는 최소 횟수;
  vis[0][0] = true;
  dfs(0, 0, 0, K);

  if (answer == 200000000) {
    answer = -1;
  }
  cout << answer;
}