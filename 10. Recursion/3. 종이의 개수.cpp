#include <iostream>
using namespace std;

int board[2200][2200];
int minus_one;
int zero;
int plus_one;

bool check(int x, int y, int n) {
  for (int i = x; i < x + n; i++)
  for (int j = y; j < y + n; j++)
    if (board[x][y] != board[i][j])
    return false;
  return true;
}

void recursion(pair<int, int> initPoint, int size) {
  if (check(initPoint.first, initPoint.second, size)) {
    if (board[initPoint.first][initPoint.second] == -1) {
      minus_one += 1;
      return;
    }
    else if (board[initPoint.first][initPoint.second] == 0) {
      zero += 1;
      return;
    }
    else if (board[initPoint.first][initPoint.second] == 1) {
      plus_one += 1;
      return;
    }
  };

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      // size / 3 부분에 내가 원래는 3을 넣었었다. 그런데 3이면 전체 큰 판을 3부분으로 나누는게 아니라 나머지가 0일 때마다 계속 재귀를 수행하게 되므로 size를 3으로 나눈 값으로 i를 나눌때 0이어야 재귀를 수행하도록 해야한다.
      if (i % (size / 3) == 0 && j % (size / 3) == 0) {
        recursion(make_pair(initPoint.first+i, initPoint.second+j), size / 3);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  recursion(make_pair(0, 0), N);
  cout << minus_one << '\n';
  cout << zero << '\n';
  cout << plus_one;
}
