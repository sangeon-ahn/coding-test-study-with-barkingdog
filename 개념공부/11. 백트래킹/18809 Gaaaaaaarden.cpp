#include <bits/stdc++.h>
using namespace std;

int N, M, G, R;
int board[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int visTime[2][51][51];
bool flowers[51][51];
int ans = -1;

vector<pair<int, int>> spots;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> G >> R;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            
            if (board[i][j] == 2) spots.push_back({i, j});
        }
    }
    
    // 초록색, 빨간색 배양액 경우의 수 구하기.
    // spots에서 G+R만큼 조합 선택 후 permuation 돌려서 0이면 녹색, -1이면 빨간색
    vector<int> vec(spots.size(), 1);
    for (int i = 0; i < G + R; i++) {
        if (i < G) vec[i] = 0;
        else vec[i] = -1;
    }
    
    do {
        int result = 0;
        // 좌표, 색, 시간
        queue<pair<pair<int, int>, pair<int, int>>> q;
        memset(visTime, -1, sizeof(visTime));
        for (int i = 0; i < vec.size(); i++) {
            // 녹색 = 0
            if (vec[i] == 0) {
                visTime[0][spots[i].first][spots[i].second] = true;
                q.push({spots[i], {0, 0}});
            }
            // 빨간색 = 1
            else if (vec[i] == -1) {
                visTime[1][spots[i].first][spots[i].second] = true;
                q.push({spots[i], {1, 0}});
            }
        }
        
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            auto cur = p.first;
            int color = p.second.first;
            int time = p.second.second;
            
            // 해당 칸에 두 약이 있고 같은 시간에 놓였으면 꽃
            if (!flowers[cur.first][cur.second] && visTime[0][cur.first][cur.second] != 0 && visTime[0][cur.first][cur.second] == visTime[1][cur.first][cur.second]) {
                result++;
                flowers[cur.first][cur.second] = true;
                continue;
            }
            
            for (int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                
                // 보드밖이면 패스
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                
                // 해당색 이미 방문시 패스
                if (visTime[color][nx][ny] >= 0) continue;

                // 호수면 패스
                if (board[nx][ny] == 0) continue;

                // 꽃이 있으면 패스
                if (flowers[nx][ny]) continue;

                // 새자리에 상대 배양액이 이미 있을 때
                if (visTime[!color][nx][ny] >= 0) {
                  // 해당 배양액이 놓일 수 있는 경우는 시간이 같은 경우 뿐이다. 따라서 같지 않은 경우 무시하면 된다.
                  if (visTime[!color][nx][ny] != time + 1) continue;
                }

                visTime[color][nx][ny] = time + 1;
                q.push({{nx, ny}, {color, time + 1}});
                
            }
        }
        // 최댓값 갱신
        ans = max(ans, result);
        
        // 초기화
        memset(visTime, -1, sizeof(visTime));
        memset(flowers, false, sizeof(flowers));
    } while (next_permutation(vec.begin(), vec.end()));
    
    cout << ans;
}