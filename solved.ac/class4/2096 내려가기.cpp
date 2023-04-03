#include <bits/stdc++.h>
using namespace std;

int N;
// int board[100010][3];
// int dp[100010][3][2]; // dp[i][j][0]: i번째 줄 j칸에서 최대값. dp[i][j][1] 최솟값
int b1, b2, b3;
int mxDp1, mxDp2, mxDp3;
int mnDp1, mnDp2, mnDp3;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> b1 >> b2 >> b3;
        if (i == 0) {
          mxDp1 = b1, mxDp2 = b2, mxDp3 = b3;
          mnDp1 = b1, mnDp2 = b2, mnDp3 = b3;
        }
        else {
          int temp1 = mxDp1, temp2 = mxDp2, temp3 = mxDp3, temp4 = mnDp1, temp5 = mnDp2, temp6 = mnDp3;

          mxDp1 = max(temp1, temp2) + b1;
          mxDp2 = max(max(temp1, temp2), mxDp3) + b2;
          mxDp3 = max(temp2, temp3) + b3;

          mnDp1 = min(temp4, temp5) + b1;
          mnDp2 = min(min(temp4, temp5), temp6) + b2;
          mnDp3 = min(temp5, temp6) + b3;
        }
    //     dp[0][0][0] = board[0][0];
    //     dp[0][1][0] = board[0][1];
    //     dp[0][2][0] = board[0][2];

    //     dp[0][0][1] = board[0][0];
    //     dp[0][1][1] = board[0][1];
    //     dp[0][2][1] = board[0][2];
      
    // }
    
    // for (int i = 1; i < N; i++) {
    //     dp[i][0][0] = max(dp[i-1][0][0], dp[i-1][1][0]) + board[i][0];
    //     dp[i][1][0] = max(max(dp[i-1][0][0], dp[i-1][1][0]), dp[i-1][2][0]) + board[i][1];
    //     dp[i][2][0] = max(dp[i-1][1][0], dp[i - 1][2][0]) + board[i][2];

    //     dp[i][0][1] = min(dp[i-1][0][1], dp[i-1][1][1]) + board[i][0];
    //     dp[i][1][1] = min(min(dp[i-1][0][1], dp[i-1][1][1]), dp[i-1][2][1]) + board[i][1];
    //     dp[i][2][1] = min(dp[i-1][1][1], dp[i - 1][2][1]) + board[i][2];


    // }
    int mx = max(max(mxDp1, mxDp2), mxDp3);
    int mn = min(min(mnDp1, mnDp2), mnDp3);
    cout << mn;

    // for (int i = 0; i < 3; i++) {
    //   cout << dp[i][0][0] << " " << dp[i][1][0] << " " << dp[i][2][0] << '\n';
    // }
    }
}