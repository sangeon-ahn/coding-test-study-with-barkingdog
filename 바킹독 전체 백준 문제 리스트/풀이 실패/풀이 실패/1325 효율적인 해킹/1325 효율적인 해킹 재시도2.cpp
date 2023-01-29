/*
  A가 B를 신뢰할 때, B를 해킹한다면 A도 해킹 가능.
  A->B 방향 있는 그래프 만들고, A에서 탐색하면서 만나는 모든 정점의 결과값을 + 1 함
  최종적으로 가장 결과값이 큰 정점들을 찾아서 출력.
*/
// 틀림. 메모리초과.
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> graph[10010];
int results[10010];

// int main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cin >> N >> M;
//   fill(results, results + 10010, 1);

//   for (int i = 0; i < M; i++) {
//     int v1, v2;
//     cin >> v1 >> v2;
//     graph[v1].push_back(v2);
//   }

//   // {정점, 누적값}
//   queue<pair<int, int>> q;

//   for (int i = 1; i <= N; i++) {

//     // out간선 없으면 패스.
//     if (graph[i].size() == 0) continue;

//     q.push({i, 1});

//     while (!q.empty()) {
//       auto p = q.front(); q.pop();
      
//       for (int new_v: graph[p.first]) {
//         results[new_v]++;
//         q.push({new_v, p.second++});
//       }
//     }
//   }
//   auto p = max_element(results, results + N + 2);
  
//   for (int i = 1; i <= N; i++) {
//     if (results[i] == *p) cout << i << ' ';
//   }
// }
int mx;
bool vis[10010];
void trav(int v) {
  vis[v] = true;
  results[v]++;

  // 최대값 갱신.
  mx = max(mx, results[v]);

  // 자식정점 돌기.
  for(int nxt : graph[v]) {
    if (vis[nxt]) continue;
    trav(nxt);
  }
}

int main() {
    ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  fill(results, results + 10010, 1);

  for (int i = 0; i < M; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    graph[v1].push_back(v2);
  }

  for (int i = 1; i <= N; i++) {
    fill(vis, vis + 10010, false);
    trav(i);
  }

  // 위에서 mx값 구한걸 가지고 mx값이랑 같으면 i 출력.
  for(int i = 1; i <= N; i++)
    if(results[i] == mx) cout << i << ' ';
}

