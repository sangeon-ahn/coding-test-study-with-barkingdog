#include <bits/stdc++.h>
using namespace std;

int dp[101];
int main() {
  int N, K, W, V;
  cin >> N >> K;
  // 물건을 하나씩 받으면서 본다.
  for (int i = 1; i <= N; i++) {
    cin >> W >> V;

    // 배낭 최대 수용량부터 시작. 방금 도달한 물건의 K ~ W 순회
    // K = 15이고, W = 1이면 
    /*
      dp[14], dp[13], dp[12], dp[11] ... dp[1]까지 갱신됨.
    */
    /*
      다음에 W = 5 나오면,
      dp[10], dp[9], dp[8],...dp[5]까지 갱신됨.
      
    */
    for (int j = K; j >= W; j--) {
      if (dp[j - W] + V > dp[j]) dp[j] = dp[j - W] + V;
    }
  }

  cout << dp[K];
}