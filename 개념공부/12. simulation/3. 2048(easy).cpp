#include <iostream>
using namespace std;

int N;
int board[30][30];
int ans = -100000;

void move_and_merge(int dir) {
  if (dir == 0) {
    for (int i = N-1; i >= 0; i--) {
      for (int j = 0; j < N; j++) {
        if (board[i][j] != 0) {
          int tmp = i;

          while (1) {
            if (tmp >= N-1) break;
            else if (board[tmp+1][j] == 0) {
              board[tmp+1][j] = board[tmp][j];
              board[tmp][j] = 0;
              tmp += 1;
              continue;
            }
            else if (board[tmp+1][j] != board[tmp][j]) break;
            else {
              board[tmp+1][j] *= 2;
              board[tmp][j] = 0;
              break;
            }
          }
        }
      }
    }
  } else if (dir == 1) {
    for (int i = 0; i < N; i++) {
      for (int j = N-1; j >= 0; j--) {
        if (board[i][j] != 0) {
          int tmp = j;

          while (1) {
            if (tmp >= N-1) break;
            else if (board[i][tmp+1] == 0) {
              board[i][tmp+1] = board[i][tmp];
              board[i][tmp] = 0;
              tmp += 1;
              continue;
            }
            else if (board[i][tmp+1] != board[i][tmp]) break;
            else {
              board[i][tmp+1] *= 2;
              board[i][tmp] = 0;
              break;
            }
          }
        }
      }
    }
  } else if (dir == 2) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (board[i][j] != 0) {
          int tmp = i;

          while (1) {
            if (tmp <= 0) break;
            else if (board[tmp-1][j] == 0) {
              board[tmp-1][j] = board[tmp][j];
              board[tmp][j] = 0;
              tmp -= 1;
              continue;
            }
            else if (board[tmp-1][j] != board[tmp][j]) break;
            else {
              board[tmp-1][j] *= 2;
              board[tmp][j] = 0;
              break;
            }
          }
        }
      }
    }
  } else if (dir == 3) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (board[i][j] != 0) {
          int tmp = j;

          while (1) {
            if (tmp <= 0) break;
            else if (board[i][tmp-1] == 0) {
              board[i][tmp-1] = board[i][tmp];
              board[i][tmp] = 0;
              tmp -= 1;
              continue;
            }
            else if (board[i][tmp-1] != board[i][tmp]) break;
            else {
              board[i][tmp-1] *= 2;
              board[i][tmp] = 0;
              break;
            }
          }
        }
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  int tmp;
  for (int i = 0; i < (1<<2*5); i++) {
    tmp = i;
    for (int i = 0; i < 5; i++) {
      int dir = tmp % 4;
      tmp /= 4;
      move_and_merge(dir);
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (board[i][j] != 0) {
          ans = max(ans, board[i][j]);
        }
      }
    }
  }
  // move_and_merge(1);
  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < N; j++) {
  //     cout << board[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  // cout << '\n';
  // move_and_merge(2);
  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < N; j++) {
  //     cout << board[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  // cout << '\n';
  // move_and_merge(3);
  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < N; j++) {
  //     cout << board[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  // cout << '\n';
  // move_and_merge(2);
  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < N; j++) {
  //     cout << board[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  // cout << '\n';
  cout << ans;
}