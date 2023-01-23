#include <bits/stdc++.h>
using namespace std;

int n;
// d[i]: 숫자 i를 제곱수의 합으로 표현할 때 최소개수..
int d[100010];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  // dp 상향식 풀이방법. 1->n
  for (int i = 1; i <= n; i++) {
    // 우선 가장 큰 경우의 수로, 모든 제곱수가 1인 경우를 대입한다.
    d[i] = i;

    // 그 후, 1~제곱한게 i와 같거나 작을 때까지 돌린다.
    for (int j = 1; j * j <= i; j++) {

      // i는 i - j*j + j*j이고, i-j*j 에다가 한번의 더하기인, j*J만 더하면 i가 되기 때문에,
      // 현재 d[i]값과 d[i - j*j] + 1을 비교해서 더 작은 값을 취한다.
      // 이걸 j = 1부터 j*j <= i 일 때까지 j를 더하면서 최소값을 구한다.
      d[i] = min(d[i], d[i - j * j] + 1);
    }
  }

  cout << d[n];
}