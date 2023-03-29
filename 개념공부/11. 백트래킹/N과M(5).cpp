#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int res[10];

bool vis[10];

void backtracking(int order) {
    if (order == M) {
        for (int i = 0; i < M; i++) {
            cout << res[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    // i는 arr[i]와 매핑됨, vis[i] : arr[i]가 사용되었나
    for (int i = 0; i < N; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        res[order] = arr[i];
        backtracking(order + 1);
        vis[i] = false;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    backtracking(0);
}