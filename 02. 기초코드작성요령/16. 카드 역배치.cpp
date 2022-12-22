#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int arr[20];
  int a, b;
  for (int i = 0; i < 20; i++) {
    arr[i] = i + 1;
  }
  for (int i = 0; i < 10; i++) {
    cin >> a >> b;
    if (a > b) swap(a, b);
    for (int j = 0; j < ((b - a + 1) / 2); j++) {
      // cout << j << '\n';
      // cout << j - 1 << ' ' << j - (b - a) - 1 << '\n';
      swap(arr[a-1+j], arr[b-1-j]);
    }
  }

  for (int i = 0; i < 20; i++) {
    cout << arr[i] << ' ';
  }
}

// 바킹독은 역순으로 배치하는 코드를 함수로 뽑았다.

// 배열도 algorithm 헤더의 reverse함수 되나 확인
int main() {
  int arr[3] = {1, 2, 3};
  reverse(arr, arr + 3);

  for (int i: arr) cout << i;
}
// 된다.
