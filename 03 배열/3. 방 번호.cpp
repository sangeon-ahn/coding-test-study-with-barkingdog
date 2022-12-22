#include <iostream>
// #include <algorithm>
// #include <cmath>

using namespace std;


// 내풀이, 테스트케이스는 통과했는데 백준 넣으니 틀림.
// int main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   int N;
//   int answer;
//   int arr[10] = {};
//   cin >> N;

//   while (N) {
//     arr[N % 10]++;
//     N /= 10;
//   }

//   // ceil보다 + 1로 하는게 좋다.
//   arr[6] = (arr[6] + arr[9] + 1) / 2;
//   arr[9] = (arr[6] + arr[9] + 1) / 2;

//   answer = *max_element(arr, arr+9);
//   cout << answer;
// }

// 바킹독 풀이.
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, a[10] = {}, ans = 1;
  cin >> N;

  while (N) {
    a[N%10]++;
    N /= 10;
  }

  for (int i = 0; i < 10; i++) {
    if (i == 6 || i == 9) continue;
    ans = max(ans, a[i]);
  }

  ans = max(ans, (a[6]+a[9]+1)/2);
  cout << ans;
}