#include <iostream>
using namespace std;

int N;

int cost[1002][4];
// D[i][j]: i번째는 j를 칠할 때, i까지의 최솟값
// D[k][1] = min(D[k-1][2], D[k-1][3]) + cost[k][1];
// D[k][2] = min(D[k-1][1], D[k-1][3]) + cost[k][2];
// D[k][3] = min(D[k-1][1], D[k-1][2]) + cost[k][3];

int D[1002][4];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= 3; j++) {
      cin >> cost[i][j];
    }
  }

  D[1][1] = cost[1][1];
  D[1][2] = cost[1][2];
  D[1][3] = cost[1][3];
  
  for (int i = 2; i <= N; i++) {
    D[i][1] = min(D[i-1][2], D[i-1][3]) + cost[i][1];
    D[i][2] = min(D[i-1][1], D[i-1][3]) + cost[i][2];
    D[i][3] = min(D[i-1][1], D[i-1][2]) + cost[i][3];
  }

  cout << min(min(D[N][1], D[N][2]), D[N][3]);
}