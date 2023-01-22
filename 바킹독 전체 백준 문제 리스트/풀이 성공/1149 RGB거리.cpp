#include <bits/stdc++.h>
using namespace std;
// 풀이 소요시간 15분

int N;
int costs[1005][3];

int dp[1005][3]; // dp[i][k]: i번째 집이 k를 칠했을 때의 비용의 최솟값.
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  
  // 집 수만큼 for문 순회.
  for (int i = 1; i <= N; i++) {
    // costs의 r,g,b칸에 비용 입력.
    cin >> costs[i][0] >> costs[i][1] >> costs[i][2];
  }

  // 초기값 설정
  dp[1][0] = costs[1][0];
  dp[1][1] = costs[1][1];
  dp[1][2] = costs[1][2];

  for (int i = 2; i <= N; i++) {
    // red를 칠했을 때는 이전 집은 green 또는 blue를 칠해야 하고 이때 두 경우의 수 중 더 작은 값을 취한다.
    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];

    dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];

    dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
  }

  // dp[N][0], dp[N][1], dp[N][2] 중 최솟값 출력.
  cout << min(dp[N][0], min(dp[N][1], dp[N][2]));
}