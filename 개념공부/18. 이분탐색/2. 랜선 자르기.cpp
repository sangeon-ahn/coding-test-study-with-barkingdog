#include <iostream>
using namespace std;

int K, N;
int arr[10010];
// 예시는 통과했지만 검사에서 틀림
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> K >> N;

  for (int i = 0; i < K; i++) {
    cin >> arr[i];
  }

  int div_num = 1;
  int prev_sum = 0;
  int sum = 0;
  while (true) {
    for (int i = 0; i < K; i++) {
      sum += (arr[i] / div_num);
    }

    if (sum >= N) {
      div_num++;
      prev_sum = sum;
      sum = 0;
    }
    else if (sum < N) break;
  }

  cout << div_num - 1;
}