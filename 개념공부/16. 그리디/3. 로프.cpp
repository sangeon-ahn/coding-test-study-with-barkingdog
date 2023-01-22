#include <iostream>
#include <algorithm>
using namespace std;
// 간단한 문제였다.
int N;
int arr[100010];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  int ans = 0;

  sort(arr, arr+N);

  int k = N;

  for (int i = 0; i < N; i++) {
    ans = max(ans, arr[i] * k);
    k -= 1;
  }
  cout << ans;
}