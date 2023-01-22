#include <iostream>
#include <algorithm>

using namespace std;

// 바킹독 1번풀이
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c;
  cin >> a >> b >> c;
  int d, e, f;
  d = std::min({a, b, c});
  f = std::max({a, b, c});
  e = a+b+c-d-f;
  cout << d << ' ' << e << ' ' << f;
}

// 바킹독 2번풀이

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int arr[3];

  for (int i = 0; i < 3; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + 3);

  for (int i = 0; i < 3; i++) {
    cout << arr[i] << ' ';
  }
}

