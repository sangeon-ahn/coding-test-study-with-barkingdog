#include <iostream>
using namespace std;

int board[20][20];
int cannotSet[20][20];
int cache_cannotSet[20][20];

int N;
int answer;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void func(int n) {
  if (n == N) {
    cout << answer;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!cannotSet[i][j]) {
        board[i][j] = 1;
        cannotSet[i][j] = 1;
        for (int x = 0; x < N; x++) {
          for (int y = 0; y < N; y++) {
            if (cannotSet[x][y]) continue;
            if (x == i || y == j) cannotSet[x][y] = 1;
            else if (abs(y - j) == abs(x - i)) cannotSet[x][y] = 1;
          }
        }
        for (int i = 0; i < N; i++) {
          for (int j = 0; j < N; j++) {
            cache_cannotSet[i][j] = cannotSet[i][j];
          }
        }
        func(n+1);
        board[i][j] = 0;
        for (int i = 0; i < N; i++) {
          for (int j = 0; j < N; j++) {
            cannotSet[i][j] = cache_cannotSet[i][j];
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
  
  func(0);
}
