#include <bits/stdc++.h>

using namespace std;
int N, M;
int arr[10];
bool vis[10];

void backtracking(int order) {
    if (order == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = 1; i <= N; i++) {
        if (order == 0) {
            arr[order] = i;
            backtracking(order+1);
        }
        else if (arr[order - 1] <= i) {
            arr[order] = i;
            backtracking(order+1);    
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    
    backtracking(0);
}