/*
  피보나치 수열: F(n) = F(n-1) + F(n-2)
  F(1) = F(0) + F(-1) = 1 -> F(-1) = 1
  F(0) = F(-1) + F(-2) = 0 = 1 + F(-2) -> F(-2) = -1
  F(-1) = F(-2) + F(-3) = 1 = -1 + F(-3) -> F(-3) = 2
  
  N이 음수일 때,
  F(N) = F(N+2) - F(N+1)
*/
#include <bits/stdc++.h>
using namespace std;

int N;
map<int, long long> m;

long long fibo(int n) {
  // map에 이미 있으면 반환.
  auto p = m.find(n);
  if (p != m.end()) {
    return p->second;
  }

  long long result;

  // 재귀 수행해서 결과 구하고 map에 넣고 리턴.
  // 양수 피보나치.
  if (n > 1) {
    result = fibo(n-1) + fibo(n-2) % 1000000;
    // 음수 피보나치.
  } else if (n < 0) {
    result = fibo(n+2) - fibo(n+1) % 1000000;
  }

  m[n] = result;
  return result;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  m[0] = 0;
  m[1] = 1;

  long long result = fibo(N);

  if (result > 0) cout << "1" << '\n';
  else if (result < 0) cout << "-1" << '\n';
  else cout << "0" << '\n';

  cout << abs(result);
}