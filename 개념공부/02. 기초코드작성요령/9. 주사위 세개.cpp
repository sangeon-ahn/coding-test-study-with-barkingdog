#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

// 바킹독 1번 풀이.
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c;
  cin >> a >> b >> c;

  if (a == b && b == c) cout << 10000 + a * 1000;
  else if (a == b || a == c) cout << 1000 + a * 1000;
  else if (b == c) cout << 1000 + b * 1000;
  else cout << max({a, b, c}) * 600;
}

// 바킹독 2번 풀이

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int arr[3];

  cin >> arr[0] >> arr[1] >> arr[2];
  sort(arr, arr+3);

  if (arr[0] == arr[2]) cout << 10000 + arr[0] * 1000;
  else if (arr[0] == arr[1] || arr[1] == arr[2]) cout << 1000 + arr[0] *100;
  else cout << arr[2] * 600;
  
}