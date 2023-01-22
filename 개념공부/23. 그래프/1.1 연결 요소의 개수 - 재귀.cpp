#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1005];
int N, M;
bool vis[1005];

void dfs(int a) {
  vis[a] = true;
  for (auto b: graph[a]) {
    if (vis[b]) continue;
    dfs(b);
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < M; i++) { // 간선 개수만큼 돌린다.
  int u, v; // 간선 연결관계를 얻는다.
  cin >> u >> v; // 정점 u는 정점 v와 연결되어 있다.

  graph[u].push_back(v); // 무방향 그래프라서 u -> v
  graph[v].push_back(u); // 무방향 그래프라서 v -> u
  }

  int ans = 0;

  for (int i = 1; i <= N; i++) {
    if (vis[i]) continue;
    dfs(i);
    ans++;
  }

  cout << ans;
}

