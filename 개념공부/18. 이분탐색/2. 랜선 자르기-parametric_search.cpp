#include <iostream>
#include <algorithm>
using namespace std;

int K, N;
int arr[10010];
// 2^31- 1같은 큰 수 할당할 때는 0x7fffffff같이 16진수로 쓰면 간단하다. 그리고 long long 타입 선언
 bool solve(long long mid) {
    int sum = 0;
    for (int i = 0; i < K; i++) {
      sum += (arr[i] / mid);
    }
    return N <= sum;
  }
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> K >> N;

  for (int i = 0; i < K; i++) {
    cin >> arr[i];
  }
  long long start = 1;
  long long end = 0x7FFFFFFF; // 2^31 - 1

  while (start < end) {
    long long mid = (start + end + 1) / 2;
    
    if (solve(mid)) start = mid;
    else end = mid - 1;
  }
  cout << start;
}