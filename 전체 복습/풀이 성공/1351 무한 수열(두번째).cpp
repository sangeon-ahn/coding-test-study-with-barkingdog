#include <iostream>
#include <map>
#include <math.h>
using namespace std;
// 소요시간: 28분
int N, P, Q;
map<int, int> mmap;

int recursive(int n) {
  // 이미 mmap에 있는 경우 해당 값을 리턴하고, 없으면 재귀적으로 구한다.
  auto it = mmap.find(n);

  if (it != mmap.end()) {
    return mmap[n];
  }

  int temp = recursive(floor(n/P)) + recursive(floor(n/Q));
  mmap[n] = temp;

  return temp;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> P >> Q;
  
  mmap[0] = 1;
  mmap[1] = 2;

  cout << recursive(N);
}
