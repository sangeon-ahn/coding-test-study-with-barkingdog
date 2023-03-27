#include <bits/stdc++.h>
using namespace std;


int graph[101][101];
int nxt[101][101];
int INF = 100000000;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    fill(graph[i], graph[i] + n + 1, INF);
    graph[i][i] = 0;
  }

  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    if (graph[u][v] > w) {
      graph[u][v] = w;
      nxt[u][v] = v;
    }
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (graph[i][j] > graph[i][k] + graph[k][j]) {
          graph[i][j] = graph[i][k] + graph[k][j];
          nxt[i][j] = nxt[i][k];
        }
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

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int a = i;
      if (nxt[a][j] == 0) {
        cout << 0 << '\n';
        continue;
      }

      int count = 1;
      vector<int> vec = {a};

      while (true) {
        if (nxt[a][j] == 0) break;
        vec.push_back(nxt[a][j]);
        a = nxt[a][j];
        count++;
      }

      cout << count << ' ';
      for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << ' ';
      }
      cout << '\n';
    }
  }
}
