#include <bits/stdc++.h>
using namespace std;

int N;
char board[101][101];
bool vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int normal_sectors;
int secmang;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    
    queue<pair<int, int>> q;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (vis[i][j]) continue;
            normal_sectors++;
            q.emplace(i, j);
            vis[i][j] = true;
            
            while (!q.empty()) {
                auto cur = q.front(); q.pop();
                
                for (int i = 0; i < 4; i++) {
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];
                    
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (vis[nx][ny]) continue;
                    
                    // 일반인
                    if (board[cur.first][cur.second] == board[nx][ny]) {
                        vis[nx][ny] = true;
                        q.emplace(nx, ny);
                    }
                }
            }
        }
    }
    memset(vis, false, sizeof(vis));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (vis[i][j]) continue;
            secmang++;
            q.emplace(i, j);
            vis[i][j] = true;
            
            while (!q.empty()) {
                auto cur = q.front(); q.pop();
                
                for (int i = 0; i < 4; i++) {
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];
                    
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (vis[nx][ny]) continue;
                    
                    // 색맹
                    // 같거나 R-G, G-R 이면 체크
                    if (board[cur.first][cur.second] == board[nx][ny] || board[cur.first][cur.second] == 'R' && board[nx][ny] == 'G' || board[cur.first][cur.second] == 'G' && board[nx][ny] == 'R') {
                        vis[nx][ny] = true;
                        q.emplace(nx, ny);
                    }
                }
            }
        }
    }
    cout << normal_sectors << ' ' << secmang;
}