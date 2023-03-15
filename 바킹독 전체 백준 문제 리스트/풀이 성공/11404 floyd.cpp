#include <bits/stdc++.h>
using namespace std;
/*
  헤맨 이유들
  1. 플로이드 와샬 기법을 사용하려면 for문을 3번 돌리고, 모든 (i, j)에 대해 1을 거칠 때 갱신 -> 2를 거칠 때 갱신 ... -> n을 거칠 때 갱신
  이런식으로 해줬어야 했는데 (i, j) 최단거리를 1,2,3,4,..,n까지 한번에 구한 후 다른 (i,j)로 가는 for문을 사용했었다.
  -> 플로이드 와샬 기법을 정확히 몰랐고, for문을 어떻게 돌려야 할 지 헷갈려서 생긴 문제

  2. 처음에 i->j로 바로 갈 수 없는 경로에 대해 INF 처리를 해준 후 모든 정점을 거쳐서 최단거리를 구한 후에도 INF로 남아있는 (i,j)에 대해서는
  불가능을 의미하는 숫자로 0을 넣었어야 했는데 이 처리를 하지 않아서 많은 시간이 소요되었다.
  -> 직접 발견하지는 못했고, 질문 리스트에서 발견하여 해결했다.
*/
int graph[101][101];
int INF = 10000000;

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
        graph[u][v] = min(graph[u][v], w);
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= n; k++) {
          graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
        }
      }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] == INF) {
                 graph[i][j] = 0;
            }
            cout << graph[i][j] << ' ';
        }
        if (i == n) continue;
        cout << '\n';
    }
}