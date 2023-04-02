#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> graph[101];
int answer[101][101];
bool vis[101];
/*
  v[i][k] && v[k][j] == true인 경우  v[i][j] = 1로 해주면서 플로이드 방법 사용하는 풀이도 있다.
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int a;
            cin >> a;
            if (a == 1) {
                graph[i].push_back(j);
            }
        }
    }
    
    queue<int> q;
    for (int i = 0; i < 100; i++) {
        if (graph[i].size() == 0) continue;
        
        q.push(i);
        while (!q.empty()) {
            int p = q.front(); q.pop();
            
            for (int new_p : graph[p]) {
                if (vis[new_p]) continue;
                vis[new_p] = true;
                answer[i][new_p] = 1;
                q.push(new_p);
            }
        }
        
        fill(vis, vis + N, false);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
}