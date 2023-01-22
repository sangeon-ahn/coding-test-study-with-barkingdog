#include <bits/stdc++.h>
using namespace std;

int N, M, T;
vector<int> party[100];

// 인접벡터를 만들 생각을 못했음.
vector<int> adj[52];

int knowTruth[100];

void bfs() {
  queue<int> q;
  for (int i = 1; i <= N; i++) {
    if (knowTruth[i] == 0) continue;
    q.push(i);

    while (!q.empty()) {
      auto p = q.front(); q.pop();

      for (auto np: adj[p]) {
        if (knowTruth[np] == 1) continue;
        knowTruth[np] = 1;
        q.push(np);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> T;

  while (T--) {
    int t;
    cin >> t;
    knowTruth[t] = 1;
  }

  for (int i = 0; i < M; i++) {
    int n;
    cin >> n;


    // 이부분부터 어려움.
    int prev, next;
    cin >> prev;
    party[i].push_back(prev);

    while (--n) {
      cin >> next;

      party[i].push_back(next);
      adj[prev].push_back(next);
      adj[next].push_back(prev);
      swap(prev, next);
    }
  }

  bfs();
  int ans = 0;

  for (int i = 0; i < M; i++) {
    bool isFalse = false;

    for (int j = 0; j < party[i].size(); j++) {
      if (knowTruth[party[i][j]] == 1) {
        isFalse = true;
        break;
      }
    }

    if (isFalse) continue;
    ans++;
  }

  cout << ans;
}