#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[100010];
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
        int st = 0, en = N - 1;
        bool flag = false;
        while (st <= en) {
            int mid = (st + en) / 2;
            
            // mid 이상의 숫자는 모두 n보다 크므로, mid - 1 까지 탐색하면 된다.
            if (arr[mid] > n) {
                en = mid - 1;
            }
            else if (arr[mid] < n) {
                st = mid + 1;
            }
            else {
                cout << "1\n";
                flag = true;
                break;
            }
        }
        
        if (!flag) cout << "0\n";
    }
}

