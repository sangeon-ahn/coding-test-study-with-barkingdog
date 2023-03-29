#include <bits/stdc++.h>

using namespace std;
int N, M;
int arr[10];

void backtracking(int order) {
    if (order == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = 0; i < N; i++) {
        arr[order] = i+1;
        backtracking(order+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    
    backtracking(0);
}