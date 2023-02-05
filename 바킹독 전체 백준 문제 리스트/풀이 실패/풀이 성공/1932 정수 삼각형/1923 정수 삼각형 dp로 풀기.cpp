#include <bits/stdc++.h>
using namespace std;
// 풀이 성공.
int N;
// dp[i][j]: i층 j번째까지 가는 경로 중 최대값.
int dp[510][510];
vector<int> v[510];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++) {
    int count = 0;

    while (count <= i) {
      int a;
      cin >> a;

      v[i].push_back(a);
      count++;
    }
  }

  dp[0][0] = v[0][0];

  for (int i = 1; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      
      // 맨 왼쪽 수인 경우.
      if (j == 0) {
        dp[i][0] = dp[i- 1][0] + v[i][0];
      }

      // 맨 오른쪽 수인 경우.
      else if (j == i) {
        dp[i][i] = dp[i - 1][j - 1] + v[i][i];
      }

      // 사이에 있는 경우.
      else {
        dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + v[i][j];
      }
    }
  }

  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j <= i; j++) {
  //     cout << dp[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  cout << *max_element(dp[N - 1], dp[N - 1] + N + 1);
}