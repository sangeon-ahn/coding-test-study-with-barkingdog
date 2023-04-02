#include <bits/stdc++.h>
using namespace std;

int N;
int P;
vector<int> graph[101];
bool vis[101];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> P;
    
    for (int i = 0; i < P; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int sum = 0;
    queue<int> q;
    q.push(1);
    vis[1] = true;
    
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        
        for (int new_node : graph[cur]) {
            if (vis[new_node]) continue;
            sum++;
            vis[new_node] = true;
            q.push(new_node);
        }
    }
    
    cout << sum;
}