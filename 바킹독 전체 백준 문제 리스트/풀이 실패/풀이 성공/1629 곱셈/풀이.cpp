#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll POW(ll a, ll b, ll m) {
  if (b == 1) return a % m;

  // a^b = a^(b/2) + a^(b/2)이다. 그래서 반쪽에 해당하는 val를 구한 후, val * val을 해준다.
  ll val = POW(a, b/2, m);
  val = val * val % m;
  
  // 짝수인 경우에는 구한 값을 바로 리턴하지만, b가 홀수면 한번 더 곱한걸 나누고 리턴한다.
  if (b % 2 == 0) return val;
  return val * a % m;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll a, b, c;

  cin >> a >> b >> c;
  cout << POW(a, b, c);
}