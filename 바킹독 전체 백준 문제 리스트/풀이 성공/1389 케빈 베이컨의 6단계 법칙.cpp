#include <bits/stdc++.h>
using namespace std;
// 소요시간: 22분
int N, M;

/*
  1. 그래프를 이용해서 풀이한다.
  2. 무방향 그래프이므로 a->b, b->a
  3. 간선 입력받은 후 각 유저에 대해 bfs 돌기
  4. 각 유저에 대해 dist[], vis[] 만들고 돌기.
*/
int ans;
int mn = 1<<20;

vector<int> graph[101];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  // 일단 간선 데이터 입력.
  for (int i = 0; i < M; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
  }

  // 각 유저에 대해 bfs 수행.
  for (int i = 1; i <= N; i++) {
    bool vis[101];
    fill(vis, vis+101, false);
    int sum = 0;
    queue<pair<int, int>> q;
    vis[i] = true;
    q.push({i, 0});

    while (!q.empty()) {
      auto p = q.front(); q.pop();

      for (auto next_v: graph[p.first]) {
        if (vis[next_v]) continue;
        sum += p.second + 1;
        vis[next_v] = true;
        q.push({next_v, p.second + 1});
      }
    }

    // 더 작을 경우 교체.
    if (mn > sum) {
      ans = i;
      mn = sum;
    }

    // 값이 같을 경우 번호가 작으면 교체.
    else if (mn == sum) {
      if (ans > i) {
        ans = i;
        mn = sum;
      }
    }
  }

  cout << ans;
}