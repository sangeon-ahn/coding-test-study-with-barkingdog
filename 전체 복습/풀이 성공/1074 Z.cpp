#include <bits/stdc++.h>
using namespace std;
// 풀이 소요시간 30분30초
int N, r, c;
int ans;
void dfs(int x, int y, int count) {
  if (count == 0) return;

  // 찾는 점이 2사분면에 있는 경우.
  if (pow(2, count - 1) > x && pow(2, count - 1) > y) {
    dfs(x, y, count - 1);
    return;
  }

  // 찾는 점이 1사분면에 있는 경우.
  else if (pow(2 , count - 1) > x && pow(2, count - 1) <= y) {
    ans += pow(pow(2, count - 1), 2);
    dfs(x, y - pow(2, count - 1), count - 1);
  }

  // 찾는 점이 3사분면에 있는 경우.
  else if (pow(2, count - 1) <= x && pow(2, count - 1) > y) {
    ans += 2 * pow(pow(2, count - 1), 2);
    dfs(x - pow(2, count - 1), y, count - 1);
  }

  // 찾는 점이 4사분면에 있는 경우.
  else if (pow(2, count - 1) <= x && pow(2, count - 1) <= y) {
    ans += 3 * pow(pow(2, count - 1), 2);
    dfs(x - pow(2, count - 1), y - pow(2, count - 1), count - 1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> r >> c; // 2^N * 2*N 크기, r,c는 0부터 시작

  dfs(r, c, N);
  cout << ans;
}