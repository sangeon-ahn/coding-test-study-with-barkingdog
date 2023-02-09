#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[1010][1010], d[1010][1010];
int ans;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    string s;
    cin >> s;

    for (int j = 1; j <= M; j++) {
      board[i][j] = s[j-1] - '0';
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (!board[i][j]) continue;

      d[i][j] = min({d[i-1][j], d[i][j-1], d[i-1][j-1]}) + 1;
      ans = max(ans, d[i][j] * d[i][j]);
    }
  }
  
  cout << ans;
}