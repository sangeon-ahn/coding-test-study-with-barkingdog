#include <bits/stdc++.h>
using namespace std;

// graph[u] = v, w
vector<pair<int, int>> graph[20001];
int dist[20001];
int INF = 10000000;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }
  fill(dist, dist + n + 1, INF);
  dist[k] = 0;
  
  // 거리, 정점번호.
  priority_queue<pair<int, int>> pq;
  pq.emplace(0, k);

  while (!pq.empty()) {
    auto p = pq.top(); pq.pop();
    if (dist[p.second] != -p.first) continue;

    for (auto new_ns : graph[p.second]) {
      // 간선 길이 + dist_prev < dist_new면 교체.
      if (new_ns.second + (-p.first) < dist[new_ns.first]) {
        dist[new_ns.first] = new_ns.second -p.first;
        pq.emplace(-dist[new_ns.first], new_ns.first);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (dist[i] >= INF) cout << "INF" << '\n';
    else cout << dist[i] << '\n';
  }
}