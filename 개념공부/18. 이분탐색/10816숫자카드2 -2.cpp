#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[500010];
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    cin >> M;
    
    for (int i = 0; i < M; i++) {
        int n;
        cin >> n;
        
        auto it1 = lower_bound(arr, arr + N, n);
        
        if (*it1 != n) cout << "0 ";
        else {
            auto it2 = upper_bound(arr, arr + N, n);
            cout << it2 - it1 << ' ';
        }
    }
}