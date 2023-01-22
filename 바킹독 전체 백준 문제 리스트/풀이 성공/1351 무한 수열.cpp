#include <bits/stdc++.h>
using namespace std;

long long N, P, Q;
/*
  a0 = 1
  ai = a(i/p의 내림) + a(i/Q의 내림)
  n = 7, p = 2, q = 3일 때
  a7 = a(3) + a(2)
  a3 = a(3/2내림) + a(3/3내림) = a1 + a1 
  a1 = a0 + a0 = 2
  a2 = a(2/2내림) + a(2/3내림) = a1 + a0 = 3
  a7 = a3 + a2 = 4 + 3 = 7
  1,000,000,000,000
*/

unordered_map<long long, long long> umap;

long long  dp(long long n) {
  long long result = 0;
  auto it = umap.find(n);
  // 없으면
  if (it == umap.end()) {
    result = dp(floor(n/P)) + dp(floor(n/Q));
    umap.insert({n, result});
  }
  // 있으면
  else result = it->second;

  return result;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> P >> Q;

  // 초기값 0, 1 넣는다.
  umap[0] = 1;
  umap[1] = 2;

  dp(N);

  cout << umap.find(N)->second;
}