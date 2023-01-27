#include <bits/stdc++.h>
using namespace std;
/*
  우선 board 데이터를 받는다.
  이후 dfs를 수행하는데, dfs의 인자로 종이의 시작 지점(맨 왼쪽 맨 위 점), 종이의 길이를 받는다.
  해당 종이에 적힌 모든 숫자가 -1, 0, 1중 하나로 채워져 있으면 전역변수 값에 +1을 해준다.
  모든 dfs가 끝난 후 결과를 출력한다.
*/

int N;
int board[3000][3000];
map<int, int> m;

bool check(int x, int y, int width) {
  int firstValue = board[x][y];
  
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < width; j++) {
      if (firstValue != board[x + i][y + j]) return false;
    }
  }

  return true;
}

void dfs(int x, int y, int width) {
  if (width == 1) {
    m[board[x][y]]++;
    return;
  }

  bool isAllSame = check(x, y, width);

  if (isAllSame) {
    // cout << board[x][y];
    m[board[x][y]]++;
    return;
  }

  // x, x + width / 3, x + x + width / 3 * 2;
  for (int i = 0; i < width; i += width / 3) {
    for (int j = 0; j < width; j += width / 3) {
      dfs(x + i, y + j, width / 3);
    }
  }
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

  dfs(0, 0, N);
  cout << m[-1] << '\n' << m[0] << '\n' << m[1];
}