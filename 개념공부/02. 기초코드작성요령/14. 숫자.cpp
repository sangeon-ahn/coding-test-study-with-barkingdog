#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int A, B;
  cin >> A >> B;
  // B가 더 크다는 보장이 없기 때문에 A가 더 큰 경우 스왑해주어야 한다. algorithm 헤더에 swap 존재.
  if (A > B) swap(A, B);
  // 둘 간의 차이가 1인 경우 or 같은 숫자인 경우는 0 리턴
  if (A == B || B - A == 1) cout << 0;
  else {
    cout << B - A - 1 << '\n';

    for (int i = A + 1; i < B; i++) {
      cout << i << ' ';
    }
  }
}
