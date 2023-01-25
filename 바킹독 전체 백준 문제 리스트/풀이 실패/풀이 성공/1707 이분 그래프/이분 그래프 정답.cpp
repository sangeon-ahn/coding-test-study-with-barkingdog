#include <bits/stdc++.h>
using namespace std;

int k, v, e;
int group[20002];
vector<int> graph[20002];

bool solve() {
  fill(group, group + v + 1, -1);

  for (int i = 1; i <= v; i++) {
    if (group[i] != -1) continue;

    queue<int> q;
    q.push(i);
    group[i] = 0;

    while (!q.empty()) {
      int cur = q.front(); q.pop();

      // 여기서 이전 정점 방문하는 경우 false를 리턴할 것 같은데 왜 잘 작동하는지 모르겠다.
      // 내 착각이었다. next_v와 cur은 같을 수 없다.
      for (int next_v: graph[cur]) {
        cout << cur << " " << next_v << '\n';
        if (group[next_v] != -1) {
          if (group[next_v] == group[cur]) return false;
          else continue;
        }
        group[next_v] = (group[cur] + 1) % 2;
        q.push(next_v);
      }
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> k;
  while (k--) {
    cin >> v >> e;

    for (int i = 1; i <= v; i++) {
      graph[i].clear();
    }

    int i, j;
    while (e--) {
      cin >> i >> j;

      graph[i].push_back(j);
      graph[j].push_back(i);
    }

    if (solve()) cout << "YES\n";
    else cout << "NO\n";
  }
}