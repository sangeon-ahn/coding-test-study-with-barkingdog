#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[101];
int snakes[101];
int laddles[101];

int dp[101]; // dp[i]: i번 칸으로 이동시 최소 주사위 횟수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        laddles[b] = a;
    }
    for (int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      snakes[b] = a;
    }
    fill(dp, dp + 101, 0x7f7f7f7f);

    dp[0] = 0, dp[1] = 0, dp[2] = 1, dp[3] = 1, dp[4] = 1, dp[5] = 1, dp[6] = 1, dp[7] = 1;
    
    for (int i = 8; i <= 100; i++) {
        for (int j = 1; j < i; j++) {
            if (laddles[i] == i - j) {
                dp[i] = min(dp[i], dp[i - j]);
            }
            else {
              dp[i] = min(dp[i], dp[i - j] + j / 6 + 1);
            }
        }
        cout << i << ' ' << dp[i] << '\n';
    }
    
    cout << dp[100];
}

// bfs로 풀어보기
