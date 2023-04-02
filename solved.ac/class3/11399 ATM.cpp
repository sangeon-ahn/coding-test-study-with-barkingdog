#include <bits/stdc++.h>
using namespace std;

int dp[1010]; // dp[i]: i번째 사람이 인출하는데 걸리는 시간.
int N;
int arr[1010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + N);
    
    dp[0] = arr[0];
    for (int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1] + arr[i];
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += dp[i];
    }
    cout << sum;
}