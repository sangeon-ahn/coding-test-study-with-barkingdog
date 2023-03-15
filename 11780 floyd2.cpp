#include <bits/stdc++.h>
using namespace std;
/*
  헤멘 부분
  1. 더 짧은 경로 발견했을 때 next_v 갱신해줘야 하는데,
  이때 새로운 값으로 그냥 k를 넣어줬었다.
  i->k로 가려고 할 때 k가 아니라 next_v[i][k]를 넣어줘야 하는데, i에서 k로 가장 짧게 가려고 할 때 next_v[i][k]를 거쳐야 하기 때문이다.

  2. 경로를 바로 출력하는게 아니라 벡터에 저장한 후 경로길이를 구한 후 벡터를 순회하며 경로를 출력해야 한다.
  3. 가장 짧은 경로 출력할 때, (i,j)로 가는 경로가 없는 경우를 예외처리하는걸 깜빡했다. 예시 테스트케이스에는 저 경우가 없었어서 예외처리하지 않아도 통과했지만, 제출시 해당 예외가 발생했다.

  플로이드 알고리즘 시간복잡도 = O(V^3), 3중 for문이므로.
  N == 1000 이하면 사용해도 좋다. 10,000 이상이면 시간초과 발생
*/

long long graph[101][101];
int next_v[101][101];
int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        fill(graph[i], graph[i] + n + 1, INF);
    }
    
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        graph[u][v] = min(graph[u][v], w);
        next_v[u][v] = v;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    next_v[i][j] = next_v[i][k];
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (i == j) cout << 0 << ' ';
          else if (graph[i][j] == INF) {
            cout << 0 << ' ';   
          }
          else  cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // (i, i)거나 경로가 없으면 패스
            if (i == j || graph[i][j] == INF) {
                cout << 0 << '\n';
                continue;
            }

            // 출발지 i, 도착지 j
            int a = i, b = j, count = 1;
            vector<int> temp = {a};
            
            while (true) {
                if (a == b) break;
                temp.push_back(next_v[a][b]);
                a = next_v[a][b];
                count++;
            }
            
            cout << count << ' ';
            
            for (int k = 0; k < temp.size(); k++) {
                cout << temp[k] << ' ';
            }
            cout << '\n';
        }
    }
}