#include <bits/stdc++.h>
using namespace std;

int INF = 0x3f3f3f3f;
int graph[101][101];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    fill(graph[i], graph[i] + n + 1, INF);
    graph[i][i] = 0;
  }

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    // 간선 정보 받기.
    graph[u][v] = min(graph[u][v], w);
  }

  // 거리 정보 넣기, j->i->k일 때를 확인.
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        // 다른 정점을 거치는 경로만 확인함.
        if (i == j) continue;
        
        graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (graph[i][j] >= INF) graph[i][j] = 0;
      cout << graph[i][j] << ' ';
    }
    cout << '\n';
  }
}