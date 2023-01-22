#include <bits/stdc++.h>
using namespace std;

int K, N;
vector<int> v;
long long ans;

int check(int mid) {
  int result = 0;

  for (int a: v) {
    result += a / mid;
  }

  return result;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> K >> N;
  
  for (int i = 0; i < K; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }

  sort(v.begin(), v.end());

  long long st = 1;
  long long en = 0x7f7f7f7f;
 // 1, 457 229
  while (st < en) {
    long long mid = (st + en) / 2;
    cout << st << ' ' << en << ' ' << mid << '\n';
    long long result = check(mid);

    if (result < N) en = mid - 1;
    else if (result > N) st = mid;
    else {
      ans = max(ans, mid);
      st = mid;
    }
  }

  cout << ans;
}