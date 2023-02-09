/*
  모든 노드에 대해 더이상 갈 수 없을때까지 갔을 때 가중치의 누적값의 최대값을 구한다.
*/

// 풀이성공, 27분
#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> graph[10010];
bool vis[10010];
int ans;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  // 무방향 트리 입력.
  for (int i = 1; i < N; i++) {
    int v1, v2, w;
    cin >> v1 >> v2 >> w;

    graph[v1].push_back({v2, w});
    graph[v2].push_back({v1, w});
  }

  
  
  // (현재 노드, 가중치 합)
  queue<pair<int, int>> q;

  // 모든 노드에 대해 bfs 수행.
  for (int i = 1; i <= N; i++) {
    q.push({i, 0});
    vis[i] = true;
    int result = 0;

    while (!q.empty()) {
      auto p = q.front(); q.pop();

      for (auto new_p: graph[p.first]) {
        // 이미 방문한 노드면 패스.
        if (vis[new_p.first]) continue;

        // 방문체크.
        vis[new_p.first] = true;

        int new_node = new_p.first;
        int new_weightSum = p.second + new_p.second;

        // i번째 노드에서의 지름 최댓값 갱신.
        result = max(result, new_weightSum);

        q.push({new_node, new_weightSum});
      }
    }
    // i번째 노드에서 지름의 최댓값과 전체 최댓값 비교.
    ans = max(ans, result);

    // 다시 vis 초기화.
    fill(vis, vis + 10010, false);
  }

  cout << ans;
}