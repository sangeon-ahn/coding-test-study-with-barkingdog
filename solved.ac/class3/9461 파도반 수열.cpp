#include <bits/stdc++.h>
using namespace std;

int T;
int dp[110];

// void solve(int N) {
//     // 1 1 1 2 2 3 4 5 7(-1, -5) 9(-1, -5 ) 12 16 21 28 37 = 28 + 9 49 = 37 + 12, 49 + 16 = 65, 86=65 + 21
//     //  0 0 1 0 1 1 1 2 2 3  4  5  7  
//     dp[i] = dp[i-1] + dp[i-5];
// }
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;
        dp[4] = 2;
        dp[5] = 2;
        
        for (int i = 6; i <= N; i++) {
            dp[i] = dp[i-1] + dp[i-5];
        }
        cout << dp[N];
    }
}