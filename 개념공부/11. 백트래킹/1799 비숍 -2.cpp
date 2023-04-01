#include <bits/stdc++.h>
using namespace std;

int N;
int board[10][10];
int ans[2];
vector<pair<int, int>> vec[2][20];
bool diagonal[2][20];

void backtracking(int order, int count, int color) {
  if (order == 2 * N - 1) {
    ans[color] = max(ans[color], count);
    return;
  }

  for (auto v : vec[color][order]) {
    if (diagonal[color][v.first + v.second]) continue;
    diagonal[color][v.first + v.second] = true;
    backtracking(order + 1, count + 1, color);
    diagonal[color][v.first + v.second] = false;
  }
  backtracking(order + 1, count, color);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];

      if (board[i][j] == 1) {
        vec[(i + j) % 2][N - j - 1 + i].push_back({i, j});
      }
    }
  }

  backtracking(0, 0, 0);
  backtracking(0, 0, 1);
  cout << ans[0] + ans[1];
}