#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[100010];

// 틀림.
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + N);
  int st = 0;
  int en = N - 1;
  int ans = 0x7fffffff;

  while (st < N) {
    int temp = arr[en] - arr[st];
    if (temp < M) {
      en++;
    } else if (temp > M) {
      st++;
      ans = min(ans, temp);
    }
  }

  cout << ans;
}

int n, m;
int a[100005];
int mn = 0x7fffffff;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n);

  int en = 0;
  
  for (int st = 0; st < n; st++) {
    while (en < n && a[en] - a[st] < m) en++;
    if (en == n) break;
    mn = min(mn, a[en] - a[st]);
  }
  cout << mn;
}