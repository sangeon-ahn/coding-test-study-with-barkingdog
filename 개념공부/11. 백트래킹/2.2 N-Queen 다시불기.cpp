#include <iostream>
using namespace std;

int N;
int ans;
// 2차원 배열 그래프에서 func에 들어가는 값은 행으로 보면 되고, 내부의 i는 열 으로 보면 된다.
// isused1은 사용된 열을 나타내는 곳
// isused2는 y=x인 곳
// isused3는 y=-x인 곳
int isused1[20];
int isused2[40];
int isused3[40];

void func(int n) {
  if (n == N) {
    ans += 1;
    return;
  }

  for (int i = 0; i < N; i++) {
    if (isused1[i] || isused2[i+n] || isused3[i-n+N-1]) continue;
    isused1[i] = 1;
    isused2[i+n] = 1;
    isused3[i-n+N-1] = 1;
    func(n+1);
    isused1[i] = 0;
    isused2[i+n] = 0;
    isused3[i-n+N-1] = 0;
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  func(0);
  cout << ans;
}