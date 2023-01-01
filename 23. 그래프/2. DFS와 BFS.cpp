#include <bits/stdc++.h>
using namespace std;

int N, M, V;
vector<int> graph[1005];
vector<int> bfss;
vector<int> dfss;
int vis[1005];

void dfs(int v) { // dfs 구현.
  vis[v] = true; // 일단 들어오면 방문했다고 하고.
  dfss.push_back(v); // 기록에 집어넣기.

  for (int new_v: graph[v]) { // 간선으로 연결된 정점 순회.
    if (vis[new_v]) continue; // 이미 방문했으면 패스.
    dfs(new_v); // 처음 방문했으면 dfs 시작.
  }
}

void bfs(int v) { // bfs 구현.
  queue<int> q; // bfs는 큐를 이용함.
  q.push(v); // q에 들어온 정점 넣기.
  vis[v] = true; // 방문했다고 하기.

  while (!q.empty()) { // 빌때까지 하기.
    int a = q.front(); q.pop();
    bfss.push_back(a);

    for (int new_v: graph[a]) {
      if (vis[new_v]) continue;
      vis[new_v] = true;
      q.push(new_v);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> V;

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;

    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  // 작은 정점부터 dfs와 bfs를 해야하기 때문에 정렬.
  for (int i = 1; i <= N; i++) {
    sort(graph[i].begin(), graph[i].end());
  }

  //dfs
  dfs(V);
  // bfs 돌리기 위해 vis 다시 false로 초기화. index가 1부터 시작하기 때문에 N+1만큼 초기화
  fill(vis, vis+N+1, false);
  // bfs 시작
  bfs(V);

  for (int num: dfss) {
    cout << num << ' ';
  }

  cout << '\n';

  for (int num: bfss) {
    cout << num << ' ';
  }

  cout << '\n';
}