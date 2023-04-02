#include <bits/stdc++.h>
using namespace std;

int board[70][70];
string ans = "";

bool allSame(int x, int y, int width) {
    int a = board[x][y];
    
    for (int i = x; i < x + width; i++) {
        for (int j = y; j < y + width; j++) {
            if (board[i][j] != a) return false;
        }
    }
    return true;
}

void check(int x, int y, int width) {
    if (width == 1) {
        ans += to_string(board[x][y]);
        return;
    }
    
    if (allSame(x, y, width)) {
        ans += to_string(board[x][y]);
        return;
    }
    
    ans += "(";
    check(x, y, width / 2);
    check(x, y + width / 2, width / 2);
    check(x + width / 2, y, width / 2);
    check(x + width /2 , y + width / 2, width / 2);
    ans += ")";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        
        for (int j = 0; j < s.size(); j++) {
            board[i][j] = s[j] - '0';
        }
    }
    
    check(0, 0, N);
    cout << ans;
}
