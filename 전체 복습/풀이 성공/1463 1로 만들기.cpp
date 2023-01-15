#include <bits/stdc++.h>
using namespace std;

int N;
int dp[1000100];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  dp[1] = 0;
  dp[2] = 1;
  dp[3] = 1;

  for (int i = 4; i <= N; i++) {
    
    // 우선 i가 3과 2 둘다 나눠지지 않는 경우를 구한다.
    int a = dp[i - 1] + 1;
    
    // i가 3으로 나누어 떨어지면,
    if (i % 3 == 0) {
      // 3으로 나눈 값의 1로 도달하는 최소값에 + 1과 -1을 뺀 값의 최솟값에 + 1 값을 비교한다.
      a = min(dp[i/3] + 1, a);
    }

    // i가 2로 나누어 떨어지면,
    if (i % 2 == 0) {
      // 2로 나눈 값의 1로 도달하는 최솟값과 기존의 값을 비교한다.
      a = min(a, dp[i/2] + 1);
    }

    // 3가지 경우의 수 중 최솟값인 a를 dp[i]에 넣는다.
    dp[i] = a;
  }
  
  cout << dp[N];
}