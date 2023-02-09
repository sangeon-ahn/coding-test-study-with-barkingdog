#include <bits/stdc++.h>
using namespace std;

/*
  board[i][j]: 색 i에 대해 \ 방향 대각선에 포함되는 칸들을 저장하는 vector.
  그러니까 i: 0 or 1이고, 1이면 비숍이 올 수 있는 칸, 0이면 못 오는 칸.
  체스판 최대 크기가 10x10인데 board의 2차원 크기가 20인 이유는 체스판 실제 모습 보면 색이 두개가 있고, 각 색당 \가 있다. 여유롭게 잡은것.
*/
vector<pair<int, int>> board[2][20];
bool used[2][20];
int ans[2];
int N;

void bishop(int idx, int cnt, int color) {

  // 해당 대각선에 1이 없어서 계속 다음 대각선으로 이동하다가 2*n == idx면 cnt랑 ans 랑 비교 후 갱신.
  if (idx == 2 * N) {
    ans[color] = max(ans[color], cnt);
    return;
  }

  for (auto v: board[color][idx]) {
    int x, y;
    tie(x, y) = v;

    // x + y가 같은 칸 = / 대각선에 위치한 칸들이라서 used[color][x+y]를 true로 해주면 /에 있는 칸은 다 패스된다.
    if (used[color][x + y]) continue;
    used[color][x + y] = true;

    // 다음 대각선으로 이동.
    bishop(idx + 1, cnt + 1, color);

    // 백트래킹을 하기 위해 들어갔다 나온 대각선을 다시 false로 해준다.
    used[color][x + y] = false;
  }

  // 대각선에 1이 없는 경우 다음 대각선으로 이동.
  bishop(idx + 1, cnt, color);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  int d;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> d;

      // 칸이 0이면 못둔다.
      if (d != 0) {
        // i + j 값이 홀수일 때: 0, 짝수일 때: 1
        // i = 0, j = 2이면 i+j+1 = 3, 3%2 = 1. 5 + 0 - 2 - 1 = 2 => 세번째 대각선
        board[(i + j + 1) % 2][N + i - j - 1].push_back({i, j});
      }
    }
  }
  // 체스판 색이 0인 경우와 1인 경우 따로 돌림.
  // 4방향 대각선을 다 그려도 색 0인 칸과 색 1인 칸은 서로 만나지 않으므로 독립실행이 가능하다.
  bishop(0, 0, 0);
  bishop(0, 0, 1);

  // 색:0 결과 + 색:1 결과
  cout << ans[0] + ans[1];
}