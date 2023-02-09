#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> board[2][20];
bool isUsed[2][20];
int ans[2];

void bishop(int idx, int cnt, int color) {
  // 탈출구문.
  if (idx == 2 * N) {
    ans[color] = max(ans[color], cnt);
    return;
  }

  for (auto p: board[color][idx]) {
    int x, y;
    tie(x, y) = p;

    if (isUsed[color][x + y]) continue;
    isUsed[color][x + y] = true;
    bishop(idx + 1, cnt + 1, color);
    isUsed[color][x + y] = false;
  }

  bishop(idx + 1, cnt, color);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  int d;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <N; j++) {
      cin >> d;

      if (d == 1) {
        board[(i + j) % 2][N + i - j - 1].push_back({i, j});
      }
    }
  }

  bishop(0, 0, 0);
  bishop(0, 0, 1);

  cout << ans[0] + ans[1];
}