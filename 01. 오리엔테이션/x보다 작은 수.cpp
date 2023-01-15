#include <iostream>
#include <string>

using namespace std;

// 1번 솔루션
int n, x, a[10005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < x) cout << a[i] << ' ';
  }
}

// 2번 솔루션
// int main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   int n, x, t;
//   cin >> n >> x;
//   while(n--) {
//     cin >> t;
//     if (t < x) cout << t << ' ';
//   }
// }
