#include <bits/stdc++.h>
using namespace std;

int N;
int board[11][11];
int ans;

void fillOne(pair<int, int> p, int a, int b) {
  int x = p.first;
  int y = p.second;

  // 새로운 위치가 보드 안에 있어야 돈다.
  while (x + a >= 0 && x + a < N && y + b >= 0 && y + b < N) {
    board[x + a][y + b] = 0;
    x += a;
    y += b;
  }
}

void mark(int i, int j) {
  board[i][j] = 1;
  
  fillOne({i, j}, -1, 1);
  fillOne({i, j}, 1, 1);
  fillOne({i, j}, 1, -1);
  fillOne({i, j}, -1, -1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  // 비숍 배치하기
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      // 비숍을 둘 수 있으면 두고 보드에 마킹하기.
      if (board[i][j] == 1) {
        ans++;
        mark(i, j);
      }
    }
  }

  cout << ans;
}
/*
1 1 2 1 1
3 1 3 3 3
1 3 1 3 1
1 2 2 2 2
1 3 1 1 1


*/