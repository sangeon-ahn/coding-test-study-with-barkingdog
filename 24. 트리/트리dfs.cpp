#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10];
int parent[10];
int depth[10];

void dfs(int cur) {
  cout << cur << ' ';
  for (int next: graph[cur]) {
    if (parent[cur] == next) continue;
    parent[next] = cur;
    depth[next] = depth[cur] + 1;
    dfs(next);
  }
}
 