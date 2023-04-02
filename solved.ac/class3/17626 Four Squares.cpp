#include <bits/stdc++.h>
using namespace std;

int N;
int ans = 0x7f7f7f7f;

int dp[50010]; // dp[i]: 숫자 i를 만들기 위해 필요한 개수. dp[i] = 1 + dp[i - X], X + i-X = i
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    fill(dp, dp + N + 1, 100000);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= N; i++) {
        for (int j = 1; j <= sqrt(i); j++) {
            dp[i] = min(dp[i], dp[i - j*j] + 1);
        }
    }
    cout << dp[N];
}