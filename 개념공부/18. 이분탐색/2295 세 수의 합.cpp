#include <bits/stdc++.h>
using namespace std;
int N;
int arr[1001];
int ans = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    
    vector<int> twoSum;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            twoSum.push_back(arr[i] + arr[j]);
        }
    }

    twoSum.erase(unique(twoSum.begin(), twoSum.end()), twoSum.end());
    
    // binary_search를 하기 위해서는 정렬을 해줘야 한다.
    sort(twoSum.begin(), twoSum.end());
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bool isIn = binary_search(twoSum.begin(), twoSum.end(), arr[j] - arr[i]);
            if (isIn) ans = max(ans, arr[j]);
        }
    }

    
    cout << ans;
}