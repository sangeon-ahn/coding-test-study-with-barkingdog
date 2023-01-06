#include <bits/stdc++.h>
using namespace std;

int V;
vector<pair<int, int>> tree[100005];
int vis[100005];
int result;

void dfs(int v, int ans) {
  // 정점 v의 자식 정점이 없는 경우 기존 최대값과 새롭게 구한 최댓값을 비교해서 큰 값을 result에 넣기.
  // 정점 v의 자식 정점을 확인한다.
  for (auto p: tree[v]) {
    // 새로운 정점이 이미 방문한 정점이었으면 패스.
    if (vis[p.first] == 1) continue;
    // 답에 간선의 가중치를 더한다.
    int new_ans = ans + p.second;

    // 방문체크하고 dfs 돌리기.
    vis[p.first] = 1;
    dfs(p.first, new_ans);
  }

  result = max(result, ans);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> V;

  // V개의 정점에 대한 정보 받기.
  for (int i = 1; i <= V; i++) {

    // v1 입력받기.
    int v1;
    cin >> v1;

    while (true) {

      // v2 입력받기.
      int v2;
      cin >> v2;

      // -1을 입력받으면 입력받기를 중단한다.
      if (v2 == -1) break;

      // x == -1이 아니면 가중치를 입력받는다.
      int weight;
      cin >> weight;

      // 트리에 집어넣는다.
      tree[v1].push_back({v2, weight});
      tree[v2].push_back({v1, weight});
    }
  }

  // 정점들에 대해 bfs 수행.
  for (int i = 1; i <= V; i++) {
    if (tree[i].size() != 2) continue;
    // 부모 배열과 깊이 배열 초기화
    fill(vis, vis + V + 10, 0);
    vis[i] = 1;
    dfs(i, 0);

  }

  cout << result;
}