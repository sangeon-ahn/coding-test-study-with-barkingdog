#include <bits/stdc++.h>
using namespace std;

int N;
bool yline[20];
bool diagonal1[40];
bool diagonal2[40];
int ans = 0;

void backtracking(int row) {
    if (row == N) {
        ans++;
        return;
    }
    
    for (int column = 0; column < N; column++) {
        if (yline[column] || diagonal1[N-column-1+row] || diagonal2[column+row]) continue;
        yline[column] = true;
        diagonal1[N-column-1+row] = true;
        diagonal2[column+row] = true;
        backtracking(row + 1);
        yline[column] = false;
        diagonal1[N-column-1+row] = false;
        diagonal2[column+row] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    // (x,y, count)
    backtracking(0);
    cout << ans;
}