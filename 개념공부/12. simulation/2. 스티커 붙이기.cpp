#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
int board[50][50];
vector<int[]> v;

// 풀이 실패
void check(int sticker[][20]) {
  for (int i = 0; i < )
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;

  for (int i = 0; i < K; i++) {
    int x, y;
    cin >> x >> y;
    int sticker[20][20];

    for (int a = 0; a < x; a++) {
      for (int b = 0; b < y; b++) {
        cin >> sticker[a][b];
      }
    }

    int rotate_sticker[20][20];
    int isvalid = true;

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < x; j++) {
        if (!isvalid) break;
        for (int k = 0; k < y; k++) {
          if (sticker[j][k] == 1) {
            if (board[j][k] == 1) {
              isvalid = false;
              break;
            }
          }
        }
      }
      if (isvalid) {
        for (int i = 0; i < x; i++) {
          for (int j = 0; j < y; j++) {
            board[i][j] = sticker[i][j];
          }
        }
      }
    }
  }
}