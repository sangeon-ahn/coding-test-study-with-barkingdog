#include <bits/stdc++.h>
using namespace std;

int board[5][5];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool vis[5][5];
bool isAdj[5][5];
int ans = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < 5; j++) {
            board[i][j] = s[j];
        }
    }

    vector<int> vec(25, 1);
    for (int i = 0; i < 7; i++) {
        vec[i] = 0;
    }

    do {
        queue<pair<int, int>> q;
        vector<pair<int, int>> temp;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == 0) {
                temp.push_back({i / 5, i % 5});
                isAdj[i/5][i%5] = true;
            }
        }

        q.push(temp[0]);
        vis[temp[0].first][temp[0].second] = true;
        int adj = 1;
        int dasom = 0;
        int doyeon = 0;
        int result = 0;

        if (board[temp[0].first][temp[0].second] == 'S') dasom++;
        else doyeon++;

        while (!q.empty()) {
            auto cur = q.front(); q.pop();

            // bool flag = false;

            for (int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                if (!isAdj[nx][ny]) continue;
                if (vis[nx][ny]) continue;

                // flag = true;
                vis[nx][ny] = true;
                adj++;
                if (board[nx][ny] == 'S') dasom++;
                else if (board[nx][ny] == 'Y') doyeon++;
                q.push({nx, ny});
            }

            // if (!flag) break;
        }

        if (adj >= 7 && dasom >= 4) ans++;
        memset(isAdj, false, sizeof(isAdj));
        memset(vis, false, sizeof(vis));
    } while(next_permutation(vec.begin(), vec.end()));
    cout << ans;
}