#include <iostream>
// #include <cmath>
#include <algorithm>

using namespace std;

// int main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   int max_num = -100;
//   int num;
//   int index;

//   for (int i = 0; i < 9; i++) {
//     cin >> num;
//     if (max_num < num) {
//       max_num = num;
//       index = i + 1;
//     }
//   }

//   cout << max_num << '\n' << index;
// }

// 바킹독 max_element 이용한 풀이
int a[9];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 9; i++) cin >> a[i];
  cout << *max_element(a, a+9) << '\n'; // max_element는 주소값을 리턴하기 때문에 *를 붙여야한다.
  cout << max_element(a, a+9) - a + 1; // 최대값의 주소값에다가 시작 주소값을 빼고 + 1 해주면 인덱스값이 나온다.
}