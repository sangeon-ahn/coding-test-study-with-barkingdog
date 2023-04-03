#include <bits/stdc++.h>
using namespace std;

int N, M;
int ladders[101];
int snakes[101];
bool vis[101];
int ans = 0x7f7f7f7f;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int a, b;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        ladders[a] = b;
    }
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        snakes[a] = b;
    }

    // 현재 몇번째 칸인지, 몇번 굴렸는지
    queue<pair<int, int>> q;
    q.push({1, 0});
    vis[1] = true;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int curPos = cur.first;
        int cnt = cur.second;

        if (curPos == 100) {
            ans = min(ans, cnt);
            continue;
        }

        for (int i = 1; i <= 6; i++) {
            int newPos = curPos + i;
            int temp = newPos;

            if (temp > 100) {
              continue;
            }

            if (vis[temp]) continue;

            if (ladders[temp] != 0) {
                newPos = ladders[temp];
            }

            else if (snakes[temp] != 0) {
                newPos = snakes[temp];
            }

            vis[newPos] = true;
            vis[temp] = true;

            q.push({newPos, cnt + 1});
        }
    }
    cout << ans;
}