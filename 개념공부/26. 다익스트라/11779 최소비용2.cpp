#include <bits/stdc++.h>
using namespace std;

// graph[u] = v, w
vector<pair<int, int>> graph[1001];
long long dist[1001];
int pre[1001];
int cnt[1001];

int INF = 0x3f3f3f3f;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }

  int st, en;
  cin >> st >> en;

  fill(dist, dist + n + 1, INF);
  dist[st] = 0;

  // 거리, 정점번호.
  priority_queue<pair<int, int>> pq;
  pq.emplace(-dist[st], st);

  while (!pq.empty()) {
    auto p = pq.top(); pq.pop();
    if (dist[p.second] != -p.first) continue;

    // nxt: (정점, 간선)
    for (auto nxt : graph[p.second]) {
      // 간선 길이 + dist_prev < dist_new면 교체.
      if (dist[nxt.first] <= dist[p.second] + nxt.second) continue;

      dist[nxt.first] = nxt.second -p.first;
      pq.emplace(-dist[nxt.first], nxt.first);
      pre[nxt.first] = p.second;
    }
  }

  cout << dist[en] << '\n';
  
  vector<int> path;
  int cur = en;
  while (cur != st) {
    path.push_back(cur);
    cur = pre[cur];
  }
  path.push_back(cur);
  reverse(path.begin(), path.end());
  cout << path.size() << '\n';
  for (auto x : path) cout << x << ' ';
  // deque<int> dq;
  // int a = en;
  // while (true) {
  //   if (a == 0) break;
  //   dq.push_front(a);
  //   a = pre[a];
  // }

  // cout << dq.size() << '\n';

  // for (int i = 0; i < dq.size(); i++) {
  //   cout << dq[i] << ' ';
  // }
}
