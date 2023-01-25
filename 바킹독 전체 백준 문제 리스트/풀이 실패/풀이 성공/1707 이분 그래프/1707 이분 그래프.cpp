#include <bits/stdc++.h>
using namespace std;
// 틀림.
int K;
vector<int> graph[20010];
int prevV[20010];
bool isNo = false;
void dfs(int v1, int initialV) {
  if (isNo) return;
  // 초기 정점에 도달했다면 No 출력 후 리턴.
  for (int new_v: graph[v1]) {
    // 이전 정점인 경우 패스.
    if (isNo) return;
    if (prevV[v1] == new_v) continue;
    if (prevV[new_v] == v1) {
      cout << "NO";
      isNo = true;
      return;
    }
    prevV[new_v] = v1;
    dfs(new_v, initialV);
  }
}
bool hasCircular(int V) {
  for (int v = 1; v <= V; v++) {
    dfs(v, v);
    fill(prevV, prevV+V, 0);
  }
  if (!isNo) cout << "YES";
  isNo = false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> K;

  while (K--) {
    int V, E;
    cin >> V >> E;


    for (int i = 0; i < E; i++) {
      int v1, v2;
      cin >> v1 >> v2;

      graph[v1].push_back(v2);
      graph[v2].push_back(v1);
    }

    bool isYes = hasCircular(V);
    
    for (int i = 1; i <= V; i++) {
      graph[i].clear();
    }
  }
}