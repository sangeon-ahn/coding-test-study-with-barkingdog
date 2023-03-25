#include <bits/stdc++.h>
using namespace std;

int board[21][21];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    pair<int, int> W;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) W = {i, j};
        }
    }
    
    // 1. bfs 결과 먹을 수 있는 (물고기의 위치와, 거리) 쌍들을 구한다.
    
    // 2. 1의 결과 해당되는 쌍이 없으면 끝
    // 3. 하나면 그 물고기 먹기
    // 4. 여러개면, 거리가 가장 가까운 물고기 -> 거리 같은게 여러개면 가장 위 왼쪽 물고기 먹기

    // 5. eat카운트 + 1, 시간 += 거리, 위치 갱신, eat카운트가 현재 상어 크기와 같을 시 크기 + 1, eat카운트 0으로 초기화
    
    int ans = 0;
    int eatCount = 0;
    int size = 2;
    
    // 상어 위치, 시간
    queue<pair<pair<int, int>, int>> q;
    
    while (true) {
        bool vis[21][21];
        for (int i = 0; i < 21; i++) {
            for (int j = 0; j < 21; j++) {
                vis[i][j] = false;
            }
        }

        // 현재 위치, 거리

        q.push({W, 0});
        vis[W.first][W.second] = true;
        vector<pair<int, pair<int, int>>> fishes;

        while (!q.empty()) {
            auto p = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = p.first.first + dx[i];
                int ny = p.first.second + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (board[nx][ny] > size) continue;
                if (vis[nx][ny]) continue;

                vis[nx][ny] = true;
                if (board[nx][ny] != 0 && board[nx][ny] < size) {
                    fishes.push_back({p.second + 1, {nx, ny}});
                }

                else if (board[nx][ny] == 0 || board[nx][ny] == size) {
                    q.push({{nx, ny}, p.second + 1});
                }
            }
        }

        if (fishes.size() == 0) {
          cout << ans;
          break;
        }
        
        sort(fishes.begin(), fishes.end());

        // 먹을 물고기 선택
        auto fish = fishes[0];
        int dist = fish.first;
        auto fishPos = fish.second;

        eatCount += 1;
        board[W.first][W.second] = 0;
        board[fishPos.first][fishPos.second] = 9;
        W = fishPos;
        ans += dist;

        if (eatCount == size) {
            size++;
            eatCount = 0;
        }  
    }
}
