#include <bits/stdc++.h>
using namespace std;
// 풀이 소요 시간: 14분

int T; // 테스트 횟수
int dp[100][2]; // dp[N][0]: N 피보나치 결과 0 출력 개수, dp[N][1]: N 피보나치 결과 1 출력 개수
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;

  // 우선 초깃값 N = 1, 2에 대해 설정하기
  dp[0][0] = 1;
  dp[0][1] = 0;
  dp[1][0] = 0;
  dp[1][1] = 1;

  // 테스트 케이스만큼 수행.
  for (int i = 0; i < T; i++) {
    int N;
    cin >> N;
    
    // N == 0이면 그냥 출력
    if (N == 0) {
      cout << "1 0" << '\n';
    }

    // N == 1이어도 그냥 출력
    else if (N == 1) {
      cout << "0 1" << '\n';
    }

    // 나머지 경우에는 바텀업 방식으로 dp 하기
    else {
      for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
      }
      // dp 다했으면 출력.
      cout << dp[N][0] << ' ' << dp[N][1] << '\n';
    }
  }
}