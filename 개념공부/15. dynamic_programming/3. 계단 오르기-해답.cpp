/*
  내 처음 생각은 이전 문제들과 마찬가지로 d[i] = k 해서, i번째 계단일때의 최대점수 이렇게 테이블 짜려고 했다. 근데 이렇게 하면 3번 연속으로 옆 계단을 오를 수 없다고 판단해서 이렇게 풀지 않았는데 바킹독도 이렇게 말하면서 d[i] = k 꼴로는 이 문제를 풀 수 없다고 한다.
  그래서 d[i][j] = k 이렇게 해서, 현재까지 j개의 계단을 연속해서 밟고 i번째 계단까지 올라섰을 때 점수 합의 최댓값, 단 i번째 계단은 반드시 밟아야 함.
  D[i][j]
  D[k][1] = max(D[k-2][1], D[k-2][2]) + s[k]
  D[k][2] = D[k-1][1] + s[k]

  D[1][1] = S[1], D[1][2] = 0
  D[2][1] = S[2], D[2][2] = S[1] + S[2]
  D[3][1] = max(D[1][1], D[1][2]) + s[k]
  D[3][2] = D[1][1] s[3]
*/

#include <iostream>
using namespace std;

int N;
int board[1000][1000];
int stair[1000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> stair[i];
  }

  board[1][1] = stair[1];
  board[1][2] = 0;
  board[2][1] = stair[2];
  board[2][2] = stair[1] + stair[2];

  for (int i = 3; i <= N; i++) {
    board[i][1] = max(board[i-2][1], board[i-2][2]) + stair[i];
    board[i][2] = board[i-1][1] + stair[i];
  }

  cout << max(board[N][1], board[N][2]);
}