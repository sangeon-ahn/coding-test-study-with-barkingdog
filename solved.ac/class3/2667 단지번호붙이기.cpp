#include <bits/stdc++.h>
using namespace std;

int board[26][26];
bool vis[26][26];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
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
    
    queue<pair<int, int>> q;
    int sectors = 0;
    vector<int> homes;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (vis[i][j] || board[i][j] == 0) continue;
            sectors++;
            vis[i][j] = true;
            q.emplace(i, j);
            int cnt = 1;
            while (!q.empty()) {
                auto cur = q.front(); q.pop();
                
                for (int i = 0; i < 4; i++) {
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];
                    
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (vis[nx][ny]) continue;
                    if (board[nx][ny] == 0) continue;

                    cnt++;
                    vis[nx][ny] = true;
                    q.emplace(nx, ny);
                }
            }
            homes.push_back(cnt);
        }
    }
    
    cout << sectors << '\n';
    sort(homes.begin(), homes.end());
    for (int c : homes) {
        cout << c << '\n';
    }
}
