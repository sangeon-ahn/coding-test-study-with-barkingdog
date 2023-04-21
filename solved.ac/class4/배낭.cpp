#include <bits/stdc++.h>
using namespace std;

bool isUsed[100010][101];
int N, K;
int dp[100010];
vector<pair<int, int>> items;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    int w, v;
    cin >> w >> v;
    items.emplace_back(w, v);
  }

  sort(items.begin(), items.end());
  cout << '\n';
  
  for (auto a: items) {
    cout << a.first << ' ' << a.second << '\n';
  }

  for (int i = items[0].first; i <= K; i++) {
    int temp = -1;
    for (int j = 0; j < N; j++) {
      if (i - items[j].first < 0) break;
      if (isUsed[i - items[j].first][j]) continue;
      if (dp[i] < dp[i - items[j].first] + items[j].second) {
        dp[i] = dp[i - items[j].first] + items[j].second;
        temp = j;
      }
    }

    if (temp != -1) {
      isUsed[i][temp] = true;
    }
  }

  int mx = 0;
  for (int i = 0; i <= K; i++) {
    cout << dp[i] << ' ';
    if (mx < dp[i]) mx = dp[i];
  }
  cout << mx;
}