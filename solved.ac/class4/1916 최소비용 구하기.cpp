#include <bits/stdc++.h>
using namespace std;

int N, M, st, en;
vector<pair<int, int>> graph[1010];
int dist[1010];
int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }
    
    cin >> st >> en;
    memset(dist, INF, sizeof(dist));
    
    dist[st] = 0;
    // 거리, 현재노드
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    pq.push({-dist[st], st});
    
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (dist[cur.second] != -cur.first) continue; // 같지 않다는건 이전에 거리 최솟값이 갱신되었다는 소리고, 최솟값 갱신은 현재 저장된 거리보다 작을 때 갱신되므로 top값은 구식 데이터라서 사용할 필요 없다.

        for (auto next_node : graph[cur.second]) {
          if (-cur.first + next_node.second < dist[next_node.first]) {
              dist[next_node.first] = -cur.first + next_node.second;
              pq.push({-dist[next_node.first], next_node.first});
          }
        }
    }
    
    cout << dist[en];
}