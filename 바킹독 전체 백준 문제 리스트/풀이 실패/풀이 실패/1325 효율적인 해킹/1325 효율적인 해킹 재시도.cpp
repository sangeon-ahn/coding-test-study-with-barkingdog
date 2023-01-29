/*
  방향이 있는 그래프
  A가 B를 신뢰한다면 B를 해킹하면 A도 해킹 가능 => vector[B].push(A)를 한 후 B와 연결된 정점 탐색
  max = 0 으로 한 후 max와 비교해서 더 크면 max 체인지
  결과 벡터에 시작 정점과 결과값 pair로 저장
  모든 정점 탐색 후, 결과 벡터 순회하면서 max값과 결과값이 같은 pair의 정점을 출력
*/

// 틀림. 메모리초과.
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> graph[10001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  // 그래프 구성.
  for (int i = 0; i < M; i++) {
    int v1, v2;
    cin >> v1 >> v2;

    graph[v2].push_back(v1);
  }

  // 그래프 탐색.
  int maxResult = 0;
  vector<pair<int, int>> results;
  for (int i = 1; i <= N; i++) {

    // 해당 정점의 out간선이 있으면 시작.
    if (graph[i].size() != 0) {

      // bfs 시작
      queue<int> q;
      q.push(i);
      int result = 1;

      while(!q.empty()) {
        int p = q.front(); q.pop();

        for (int next_v: graph[p]) {
          result++;
          q.push(next_v);
        }
      }

      results.push_back({i, result});
      maxResult = max(maxResult, result);
    }
  }

  // 최대값과 같은 결과들 출력.
  for (auto result: results) {
    if (result.second == maxResult) cout << result.first << ' ';
  }
}