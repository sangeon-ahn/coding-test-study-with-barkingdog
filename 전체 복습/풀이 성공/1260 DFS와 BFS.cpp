#include <bits/stdc++.h>
using namespace std;
// 12분 40초
// 신경써야 할 부분: dfs, bfs 하기 전에 vis true로 하고 넘겨야 한다는 것. 작은 정점 순서대로 출력하기 위해 각 graph의 벡터 요소들을 오름차순 정렬해야 한다는 것.
int N, M, V;
vector<int> graph[1010];
bool vis[1010];

void dfs(int v) {
  cout << v << ' ';

  for (int next_v: graph[v]) {
    if (vis[next_v]) continue;
    vis[next_v] = true;
    dfs(next_v);
  }
}

void bfs(int v) {
  queue<int> q;
  q.push(v);

  while(!q.empty()) {
    int p = q.front(); q.pop();
    cout << p << ' ';

    for (int next_v: graph[p]) {
      if (vis[next_v]) continue;;
      vis[next_v] = true;
      q.push(next_v);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> V;

  // 간선을 입력받아 graph에 넣는다.
  for (int i = 0; i < M; i++) {
    int v1, v2;
    cin >> v1 >> v2;

    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
  }

  // graph를 오름차순으로 정렬한다.
  for (int i = 1; i <= N; i++) {
    sort(graph[i].begin(), graph[i].end());
  }

  // dfs를 수행한다.
  vis[V] = true;
  dfs(V);
  cout << '\n';
  fill(vis, vis+1010, false);
  // bfs를 수행한다.
  vis[V] = true;
  bfs(V);
}