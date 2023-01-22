#include <bits/stdc++.h>
using namespace std;

int N, K;
pair<int, int> jewels[300030];
multiset<int> backs;
long long ans = 0;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;


  for (int i = 0; i < N; i++) {
    int m, v;
    cin >> m >> v;
    pair<int, int> vv = {v, m};
    jewels[i] = vv;
  }

  sort(jewels, jewels + N);

  for (int i = 0; i < K; i++) {
    int c;
    cin >> c;
    backs.insert(c);
  }

  for (int i = N-1; i >= 0; i--) {
    int m = jewels[i].second;
    int v = jewels[i].first;

    auto it = backs.lower_bound(m);
    if (it == backs.end()) continue;
    ans += v;
    backs.erase(it);
  }

  cout << ans;
}