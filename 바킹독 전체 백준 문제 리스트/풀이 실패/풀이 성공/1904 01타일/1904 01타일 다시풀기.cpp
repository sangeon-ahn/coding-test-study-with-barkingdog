#include <bits/stdc++.h>
using namespace std;

int dp[1000010]; // dp[i]: 크기가 i일 때 만들 수 있는 모든 가짓수
int N;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 3;
  dp[4] = 5;

  for (int i = 4; i <= N; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
  }

  cout << dp[N];
}