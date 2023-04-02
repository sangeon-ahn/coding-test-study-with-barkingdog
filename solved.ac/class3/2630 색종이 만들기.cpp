#include <bits/stdc++.h>
using namespace std;


int board[130][130];
int ans[2];

bool allSame(int x, int y, int width) {
    int num = board[x][y];
    for (int i = x; i < x + width; i++) {
        for (int j = y; j < y + width; j++) {
            if (num != board[i][j]) return false;
        }
    }
    return true;
}

void check(int x, int y, int width) {
    if (width == 1) {
        ans[board[x][y]]++;
        return;
    }
    
    if (allSame(x, y, width)) {
        ans[board[x][y]]++;
        return;
    }
    
    check(x, y, width / 2);
    check(x, y + width / 2, width / 2);
    check(x + width / 2, y, width / 2);
    check(x + width / 2, y + width / 2, width / 2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    
    check(0, 0, N);
    cout << ans[0] << '\n' << ans[1];
}