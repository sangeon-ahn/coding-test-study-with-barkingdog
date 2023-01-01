#include <bits/stdc++.h>
using namespace std;

int N; // 노드의 개수.
vector<int> graph[100010]; // 트리를 저장할 그래프.
int parent[100010]; // 노드의 부모를 저장할 배열.

void dfs(int cur) { // 트리를 깊이우선 탐색.
  for (int next: graph[cur]) { // 현재 노드의 인접 노드 탐색.
    if (parent[cur] == next) continue; // 인접 노드가 부모면 패스.
    parent[next] = cur; // 자식이면 부모를 cur로 지정.
    dfs(next); // 자식의 인접노드를 탐색하러 출발.
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0 ; i < N-1; i++) {
    int u, v;
    cin >> u >> v; // 노드들 연결관계 입력받기.

    // 무방향 트리 그래프이기 때문에 양쪽으로 추가.
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  dfs(1); // 트리의 루트 == 1

  for (int i = 2; i <= N; i++) {
    cout << parent[i] << '\n';
  }
}