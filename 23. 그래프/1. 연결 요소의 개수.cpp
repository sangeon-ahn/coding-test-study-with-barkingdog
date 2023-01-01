#include <bits/stdc++.h>
using namespace std;

int N, M;
int vis[1002];
vector<int> graph[1005]; // 각 원소의 타입이 vector<int>인 graph 배열을 선언한다.
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

  queue<int> q; // bfs하기 위해 큐 만들기
  fill(vis, vis + N+1, -1); // vis값이 -1이면 처음 방문, 0이면 이미 방문한 정점.
  int ans = 0; // 정답 초기값 0
  for (int i = 1; i <= N; i++) { // connected component 개수를 확인하기 위해 for문을 돌린다.
    if (vis[i] == 0) continue; // 이미 방문한 정점이면 다음 정점으로 가기.

    q.push(i); // 방문 안했으면 큐에 넣고 돌리기

    while (!q.empty()) { // 더이상 방문할 정점이 없을 때까지 while문 수행
      int v = q.front(); q.pop(); // 맨 앞에 정점을 일단 꺼내고
      
      if (vis[v] == 0) continue; // 이 정점이 이미 방문한 정점이면 패스
      vis[v]++; // 방문 안했으면 방문체크 하고

      if (!graph[v].empty()) {
        for (int next_v: graph[v]) { // 이 정점과 연결된 다른 정점들을 다 큐에 일단 넣기.
          q.push(next_v);
        }
      }
    }
    ans++; // while문이 끝났다는건 하나의 연결된 컴포넌트가 끝났다는걸 뜻하므로 ans++시켜준다.
  }

  cout << ans; // 정답을 출력한다.
}