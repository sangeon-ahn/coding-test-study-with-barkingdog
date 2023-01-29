#include <bits/stdc++.h>
using namespace std;
// 메모리 초과.

int N, M;
vector<int> graph[10010];
int max_path;
vector<int> answer;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  // 간선 관계 입력받는다.
  for (int i = 0; i < M; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    graph[v2].push_back(v1);

  }

  // graph의 모든 정점을 확인하면서 최댓값을 갱신해나간다.
  for (int i = 1; i <= N; i++) {
    if (graph[i].size() == 0) continue;

    // 정점 1개마다 최대 path를 구한다.
    int path = 0;
    queue<pair<int, int>> q;
    q.push({i, 0});

    while (!q.empty()) {
      auto p = q.front(); q.pop();
    
      for (int next_v: graph[p.first]) {
        q.push({next_v, p.second + 1});
      }

      if (graph[p.first].size() == 0) {
        path = max(path, p.second);
      }
    }

    if (max_path == path) {
      answer.push_back(i);
    } else if (max_path < path) {
      max_path = path;
      answer.clear();
      answer.push_back(i);
    } else continue;
  }

  for (int v: answer) {
    cout << v << ' ';
  }
}