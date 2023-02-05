
#include <bits/stdc++.h>
using namespace std;
// 메모리초과 실패.


int N;
vector<int> v[510];
int ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++) {
    int count = 0;

    while (count <= i) {
      int a;
      cin >> a;
      v[i].push_back(a);
      count++;
    }
  }

  // {{현재 인덱스, 현재 층(맨 위 = 0층)}, 현재 총합}
  queue<pair<pair<int, int>, int>> q;
  q.push({{0, 0}, v[0][0]});

  while (!q.empty()) {
    auto p = q.front(); q.pop();
    
    // 맨 밑층에 도달했으면 최댓값 갱신..
    if (p.first.second + 1 == N) {
      ans = max(ans, p.second);
      continue;
    }

    // 배열의 바로 아래와 오른쪽 하나에 대해 경로 검사.
    for (int i = p.first.first; i <= p.first.first + 1; i++) {

      // 아직 맨 밑층이 아니면 시작.
      int new_node = v[p.first.second + 1][i];
      q.push({{i, p.first.second + 1}, p.second + new_node});
    }
  }
  cout << ans;
}