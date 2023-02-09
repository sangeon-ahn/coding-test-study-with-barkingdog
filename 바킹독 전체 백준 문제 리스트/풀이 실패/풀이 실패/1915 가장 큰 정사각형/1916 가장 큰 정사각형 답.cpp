#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[1010][1010], d[1010][1010];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    
    for (int j = 1; j <= m; j++) {
      board[i][j] = s[j-1] - '0';
    }
  }

  int ans = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (board[i][j]) {
        /*
          d[2][1] = min({d[1][1], d[2][0], d[1][0]}) + 1;
          d[2][2] = min({d[1][2], d[2][1], d[1][1]}) + 1;
          d[i][j] = (i, j)에 대해 위쪽 칸, 왼쪽 위 대각선 칸, 왼쪽 칸이 정사각형 꼭짓점 중에서 오른쪽 아래 꼭지점일 때 만들 수 있는 가장 큰 정사각형 중에 가장 작은 값 + 1
        */
        d[i][j] = min({d[i-1][j], d[i][j-1], d[i-1][j-1]}) + 1;
        ans = max(ans, d[i][j]);
      }
    }
  }
  cout << ans * ans;
}