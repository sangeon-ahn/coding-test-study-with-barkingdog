#include <bits/stdc++.h>
using namespace std;

int K;
int v, e;
vector<int> graph[20002];
int group[20002];

bool solve() {
  fill(group, group + v + 1, -1);

  for (int i = 1; i <= v; i++) {
    // 이미 방문했으면 패스.
    if (group[i] != -1) continue;

    queue<int> q;
    q.push(i);
    group[i] = 0;

    while (!q.empty()) {
      int cur = q.front(); q.pop();

      for (int next_v : graph[cur]) {
        // 이미 방문했고 그룹이 현재 정점이랑 같으면 false 리턴.
        if (group[next_v] != -1) {
          if (group[next_v] == group[cur]) return false;
          else continue;
        } 

        // 처음 방문하는 경우 그룹에 추가하고 큐에 넣기.
        group[next_v] = (group[cur] + 1) % 2;
        q.push(next_v);
      }
    }
  }
  // 모든 정점 다 돌았는데 리턴 안됐으면 두 그룹으로 잘 나뉘어진 것이므로 true 리턴.
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> K;

  while (K--) {
    cin >> v >> e;

    
    while (e--) {
      int v1, v2;
      cin >> v1 >> v2;
      
      graph[v1].push_back(v2);
      graph[v2].push_back(v1);
    }

    if (solve()) cout << "YES\n";
    else cout << "NO\n";

    for (int i = 1; i <= v; i++) {
      graph[i].clear();
    }
  }
}