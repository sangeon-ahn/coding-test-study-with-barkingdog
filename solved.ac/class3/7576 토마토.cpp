#include <bits/stdc++.h>
using namespace std;


int M, N;
int board[1001][1001];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool vis[1001][1001];
int unripes;
int ans;

bool inRange(int x, int y) {
  if (x < 0 || x >= N || y < 0 || y >= M) return false;
  else return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;
    
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                q.push({{i, j}, 0});
                vis[i][j] = true;
            }
            else if (board[i][j] == 0) unripes++;
        }
    }    
    
    if (unripes == 0) {
        cout << 0;
        return 0;
    }
    
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        auto pos = p.first;
        int count = p.second;
        
        ans = count;
        
        for (int i = 0; i < 4; i++) {
            int nx = pos.first + dx[i];
            int ny = pos.second + dy[i];
            
            if (!inRange(nx, ny)) continue;
            if (board[nx][ny] == -1) continue;
            if (board[nx][ny] == 1) continue;
            if (vis[nx][ny]) continue;
            vis[nx][ny] = true;
            board[nx][ny] = 1;
            q.push({{nx, ny}, count + 1});
            unripes--;
        }
    }
    
    if (unripes == 0) cout << ans;
    else cout << -1;
}