#include <bits/stdc++.h>
using namespace std;

long long A, B, C;
int ans;

int POW(long long a, long long b, long long c) {
  // 왜 b == 1일 때 리턴? b == 1이라는 것은 a^1 % c를 구한다는 거니까 a%c를 리턴해야 하고, b == 0이면 a^0 % c이므로 의미없는 계산이다.
  if (b == 1) return a % c;

  int val = POW(a, b/2, c);
  val = val * val % c;

  if (b % 2 == 0) return val;
  val = val * a % c;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> A >> B >> C;
  ans = POW(A, B, C);
  cout << ans;
}