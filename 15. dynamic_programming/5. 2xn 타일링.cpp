#include <iostream>
using namespace std;

/*
  D[1] = 1
  D[2] = 2
  D[3] = 3
  D[4] = 5
  D[5] = D[4] + D[3] = 8
  D[6] = D[5] + D[4] + 13
  D[7] = D[6] + D[5] = 21
  D[8] = D[7] + D[6] = 34
  D[9] = D[8] + D[7] = 55
  규칙 발견
  만약 2(세로)*n(가로) 사각형일 때, 맨 왼쪽에 채울 수 있는 경우의 수는
  2*1 네모 1개 -> D[n-1]
  1*2 네모 2개 -> D[n-2]
  따라서 D[n] = D[n-1] + D[n-2]이다.
*/
int N;
int D[10002];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  D[1] = 1;
  D[2] = 2;

  if (N <= 2) {
      cout << D[N];
      return 0;
  }

  for (int i = 3; i <= N; i++) {
    // 여기서 10007로 나눠주지 않으면 int 타입이라 overflow가 일어난다.
    // 여기서 10007로 나눠도 답이 나오는 이유는 다 더한 후에 나눈 나머지랑 계속 나눠주면서 나머지를 구한 값이랑 같기 때문이다.
    D[i] = (D[i-1] + D[i-2]) % 10007;
  }

  cout << D[N];
}