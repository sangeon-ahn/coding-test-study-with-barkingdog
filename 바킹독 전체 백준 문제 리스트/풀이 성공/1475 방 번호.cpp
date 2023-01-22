#include <bits/stdc++.h>
using namespace std;
// 소요시간: 13분
int N;
int arr[10];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  // 자릿수를 구해서 +1.
  while (N > 0) {
    arr[N % 10]++;
    N /= 10;
  }

  // 필요 덱 수를 계산
  
  // 6이나 9 필요 개수 계산
  int need = (arr[6] + arr[9] + 1) / 2;
  
  // 0부터 9까지 돌면서 가장 많이 필요한 수를 need로 함.
  for (int i = 0; i < 10; i++) {
    if (i == 6 || i == 9) continue;
    need = max(need, arr[i]);
  }

  cout << need;
}