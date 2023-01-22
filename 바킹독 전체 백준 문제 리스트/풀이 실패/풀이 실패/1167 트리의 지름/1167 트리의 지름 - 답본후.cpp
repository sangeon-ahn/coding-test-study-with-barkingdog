#include <bits/stdc++.h>
using namespace std;

/*
  이 문제 풀이의 핵심 원리는 임의의 점에서 가장 멀리 있는 점을 구한 다음, 이 점에서 가장 멀리 있는 점을 구한 후 이 둘 사이의 거리를 구하면 이게 트리에서 가장 긴 path가 된다는 점이다.
  임의의 점을 골라도 되는 이유는 점이 있으면 왼쪽 서브트리와 오른쪽 서브트리가 있을텐데 가장 멀리 있는 점 찾았을 때 왼쪽 서브트리 맨 끝에 있다면 이 점에서 가장 멀리 있는 점은 오른쪽 서브트리 맨끝 정점일 것이기 때문이다.
*/

int V;
vector<pair<int, int>> tree[100010];
int max_node;
bool vis[100005];
int max_ans;

void dfs(int v, int ans) {
  if (max_ans < ans) {
    max_node = v;
    max_ans = ans;
  }

  for (auto p: tree[v]) {
    if (vis[p.first]) continue;
    vis[p.first] = true;
    dfs(p.first, ans + p.second);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> V;
  for (int i = 0; i < V; i++) {
    int v1;
    cin >> v1;

    while (true) {
      int v2;
      cin >> v2;

      if (v2 == -1) break;
      
      int weight;
      cin >> weight;

      tree[v1].push_back({v2, weight});
    }
  }
  vis[1] = true;
  dfs(1, 0);
  fill(vis, vis + 100000, false);
  vis[max_node] = true;
  dfs(max_node, 0);
  cout << max_ans;
}

