#include <bits/stdc++.h>
using namespace std;

long A, B, C;
vector<int> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> A >> B >> C;

  // A를 B번 곱한 수를 C로 나눈 나머지 구하기
  // 곱할 때마다 C로 나눠준다.

  for (int i = 0; i < B; i++) {
    A %= C;
    auto it = find(v.begin(), v.end(), A);

    if (it == v.end()) {
      v.push_back(A);
      A *= A;
    } else {
      int size = v.size();
      cout << v[B % size];
      break;
    }
  }
  /*
    3 % 6 = 3
    3*5%6 = 3
    3*5^2%6 = 3
  */
}