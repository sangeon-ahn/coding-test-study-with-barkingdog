#include <bits/stdc++.h>
using namespace std;
// 소요시간 29분
int N, M;
vector<pair<int, int>> tree[1010];
bool visit[1010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  // 정점 연결관계와 거리를 입력받는다.
  for (int i = 0; i < N-1; i++) {
    int v1, v2, dist;
    cin >> v1 >> v2 >> dist;

    tree[v1].push_back({v2, dist});
    tree[v2].push_back({v1, dist});
  }

  // 정점 두개를 입력받고 거리를 출력한다.

  for (int i = 0; i < M; i++) {
    int v1, v2;
    cin >> v1 >> v2;

    // 매 시도 당 새로운 q와 visit를 만들어 준다.
    queue<pair<int, int>> q;
    bool visit[1010];

    // 함수 내부에서 정의했기 때문에 false로 초기화해준다.
    fill(visit, visit + N + 10, false);

    // 큐에 넣고 방문했음을 체크한다.
    q.push({v1, 0});
    visit[v1] = true;

    // 초기 시작점 v1에서 v2를 발견할 때까지 돌다가 발견하면 지금까지 더한 거리를 출력한다.
    while (!q.empty()) {
      auto p = q.front(); q.pop();

      // 정점이 v2라면 지금까지 더한 거리를 출력하고 while을 빠져나온다.
      if (p.first == v2) {
        cout << p.second << '\n';
        break;
      }

      // p 정점와 연결된 정점들 중에서,
      for (auto next_v: tree[p.first]) {
        // 일단 방문했던 정점인 경우 패스하고,
        if (visit[next_v.first]) continue;
        // 처음 방문한 경우에만 방문여부 true로 체크한 후,
        visit[next_v.first] = true;
        // p 정점에서 next_v 정점까지의 거리를 추가해서 큐에 다시 넣는다.
        q.push({next_v.first, p.second + next_v.second});
      }
    }
  }
}