#include <bits/stdc++.h>
using namespace std;

int N, M, L;
int v[51];

// x는 휴게소간의 거리다.
bool solve(int x) {
  int must_count = 0;
  int pre = 0;

  for (int i = 0; i <= N; i++) {
    int dist = v[i] - pre;

    // 거리 x보다 dist가 같거나 클때,
    if (dist >= x) {

      // 왜 dist를 x로 나누는지 모르겠다.
      if (dist % x != 0) must_count += dist / x;
      else must_count += dist / x - 1;
    }

    pre = v[i];
  }

  // 휴게소 개수가 m보다 크다면 구간 최댓값은 커져야 함.
  if (must_count > M) return true;
  else return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> L;

  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }

  sort(v, v + N);

  v[N] = L;

  int st = 1, en = L;

  while (st < en) {
    int mid = (st + en) / 2;
    if (solve(mid)) st = mid + 1;
    else en = mid;
  }

  cout << st;
}