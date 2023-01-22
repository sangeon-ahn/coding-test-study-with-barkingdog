/*
감시 문제는 cctv가 일단 5개가 있다.
1번은 한방향, 2번은 일자로 두 방향, 3번은 90도로 두 방향, 4번은 3방향, 5번은 4방향이다.
하지만 구현의 단순함을 위해서 4방향이 아닌 경우에도 4방향이라고 보고 모든 cctv에 똑같은 로직을 적용한다.
그리고 cctv의 개수에 따라서 경우의 수가 정해지는데, 만약 cctv가 4개가 있다면 4*4*4*4 = 256가지의 경우의 수가 있다. 각각의 경우의 수에 대해서 사각지대의 수를 구하고 가장 적은 사각지대를 출력해야 한다.
백트래킹으로 저 256가지를 구현해서 1,2,3,4 중 4개의 수를 중복 허용하는 수열로 구할 수 있다.챕터11 n과 m 3번문제 확인
하지만 바킹독은 4진법 기법을 이용해서 해결했다. 4진법 수:0000 ~ 3333 이렇게 있으면, 10진법 수: 3*4^3+3*4^2+3*4^1+3*1 = 3(64+16+4+1) = 3*85 = 240+15 = 255
그래서 4^cctv.size() = 256, 따라서 0부터 <4^cctv.size()를 돌면서 4로 나눈 나머지가 0,1,2,3중 하나가 나올텐데 이거를 4방향으로 삼으면 되고, 4번 나누면 나머지가 4번 나올텐데 이걸 각각의 cctv의 방향으로 적용하면 된다.
*/
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int board[10][10];
int board2[10][10];
int zero_total;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans = 100000;
vector<pair<int, int>> cctv;

void fillToSeven(int x, int y, int dir) {
  // dir이 3보다 큰 값으로 들어올 수 있기 때문에 여기서도 4로 나눈 나머지값을 사용한다.
  int new_dir = dir % 4;
  int nx = x;
  int ny = y;
  while (1) {
    nx += dx[new_dir];
    ny += dy[new_dir];

    if (nx < 0 || nx >= N || ny < 0 || ny >= M) return;
    if (board2[nx][ny] == 6) return;
    if (board2[nx][ny] != 0) continue;

    board2[nx][ny] = 7;
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      // if (board[i][j] == 0) {
      //   zero_total++;
      // }
      if (board[i][j] >= 1 && board[i][j] <= 5) {
        cctv.push_back({i, j});
      }
    }
  }

  // i = 0000 0001 0002 0003 0010 0011 ... 3333.
  for (int i = 0; i < (1<<(2*cctv.size())); i++) {
    for (int a = 0; a < N; a++) {
      for (int b = 0; b < M; b++) {
        board2[a][b] = board[a][b];
      }
    }

    int temp = i;
    for (int j = 0; j < cctv.size(); j++) {
      int dir = temp % 4;
      temp /= 4;
      if (board2[cctv[j].first][cctv[j].second] == 1) {
        fillToSeven(cctv[j].first, cctv[j].second, dir);
      }
      if (board2[cctv[j].first][cctv[j].second] == 2) {
        fillToSeven(cctv[j].first, cctv[j].second, dir);
        fillToSeven(cctv[j].first, cctv[j].second, dir+2);
      }
      if (board2[cctv[j].first][cctv[j].second] == 3) {
        fillToSeven(cctv[j].first, cctv[j].second, dir);
        fillToSeven(cctv[j].first, cctv[j].second, dir+1);

      }
      if (board2[cctv[j].first][cctv[j].second] == 4) {
        fillToSeven(cctv[j].first, cctv[j].second, dir);
        fillToSeven(cctv[j].first, cctv[j].second, dir+1);
        fillToSeven(cctv[j].first, cctv[j].second, dir+2);
      }
      if (board2[cctv[j].first][cctv[j].second] == 5) {
        fillToSeven(cctv[j].first, cctv[j].second, dir);
        fillToSeven(cctv[j].first, cctv[j].second, dir+1);
        fillToSeven(cctv[j].first, cctv[j].second, dir+2);
        fillToSeven(cctv[j].first, cctv[j].second, dir+3);
      }
    }
    int val = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (board2[i][j] == 0) {
          val++;
        }
      }
    }
    ans = min(ans, val);
  }
  cout << ans;

}




