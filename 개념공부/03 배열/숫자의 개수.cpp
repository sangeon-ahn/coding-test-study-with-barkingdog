#include <iostream>
#include <string>

using namespace std;

// int arr[10];
// int main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   int A, B, C;
//   cin >> A >> B >> C;

//   string str1 = to_string(A * B * C);

//   for (int i = 0; i < str1.length(); i++) {
//     혹은 (int)를 붙인다.
//     arr[str1[i] - '0']++;
//   }

//   for (int i = 0; i < 10; i++) cout << arr[i] << '\n';
// }

// 바킹독 풀이
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int A, B, C;
  cin >> A >> B >> C;
  int t = A*B*C;
  int d[10] = {};

  while (t > 0) {
    d[t%10]++;
    t/=10;
  }

  for (int i = 0; i < 10; ++i) cout << d[i] << '\n';
}