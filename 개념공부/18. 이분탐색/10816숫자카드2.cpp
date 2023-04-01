#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[500010];

int checkLeft(int mid, int target) {
    int result = 0;
    int temp = mid - 1;
    
    while (temp >= 0) {
        if (arr[temp] == target) {
            result++;
            temp--;
        }
        else break;
    }
    return result;
}

int checkRight(int mid, int target) {
    int result = 0;
    int temp = mid + 1;
    while (temp < N) {
        if (arr[temp] == target) {
            result++;
            temp++;
        }
        else break;
    }
    return result;
}

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
        int ans = 0;
        cin >> n;
        
        int st = 0, en = N - 1;
        
        while (st <= en) {
            int mid = (st + en) / 2;
            
            if (arr[mid] > n) {
                en = mid - 1;
            } else if (arr[mid] < n) {
                st = mid + 1;
            } else {
                int cnt1 = checkLeft(mid, n);
                int cnt2 = checkRight(mid, n);
                ans += 1 + cnt1 + cnt2;
                break;
            }
        }
        cout << ans << ' ';
    }
}