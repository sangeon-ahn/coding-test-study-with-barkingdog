#include <bits/stdc++.h>
using namespace std;


int M, N, H;
int board[101][101][101];

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
vector<tuple<int, int, int>> ripes;
bool vis[101][101][101];
int unripes;
int ans;

bool inRange(int x, int y, int z) {
  if (x < 0 || x >= N || y < 0 || y >= M || z < 0 || z >= H) return false;
  else return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N >> H;
    
    queue<pair<tuple<int, int, int>, int>> q;
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> board[i][j][k];
                if (board[i][j][k] == 1) {
                    q.push({{i, j, k}, 0});
                    vis[i][j][k] = true;
                }
                else if (board[i][j][k] == 0) unripes++;
            }
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
        
        for (int i = 0; i < 6; i++) {
            int nx = get<0>(pos) + dx[i];
            int ny = get<1>(pos) + dy[i];
            int nz = get<2>(pos) + dz[i];
            
            if (!inRange(nx, ny, nz)) continue;
            if (board[nx][ny][nz] == -1) continue;
            if (board[nx][ny][nz] == 1) continue;
            if (vis[nx][ny][nz]) continue;
            vis[nx][ny][nz] = true;
            board[nx][ny][nz] = 1;
            q.push({{nx, ny, nz}, count + 1});
            unripes--;
        }
    }
    
    if (unripes == 0) cout << ans;
    else cout << -1;
}