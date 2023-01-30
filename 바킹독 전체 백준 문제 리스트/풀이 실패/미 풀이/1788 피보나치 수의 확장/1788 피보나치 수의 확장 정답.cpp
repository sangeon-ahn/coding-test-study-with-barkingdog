#include <bits/stdc++.h>
using namespace std;

int N;
int dp[1000010];
int mod = 1000000;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  dp[0] = 0;
  dp[1] = 1;
  
  if (N >= 0) {
    for (int i = 2; i <= N; i++) {
      dp[i] = (dp[i-1] + dp[i-2]) % mod;
    }
  }
  else {
    N = abs(N);
    for (int i = 2; i <= N; i++) {
      dp[i] = (dp[i-2] - dp[i-1]) % mod;
    }
  }

  if (dp[N] > 0) cout << "1\n";
  else if (dp[N] < 0) cout << "-1\n";
  else cout << "0\n";

  cout << abs(dp[N]);
}