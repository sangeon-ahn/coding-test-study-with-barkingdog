/*
  투포인터로 풀 수 있다.
  left, right = 0으로 둔 후에, left ~ right 합이 원하는 값보다 작으면 right++ 해준다.
  더한 값이 해당 값보다 같거나 크면 ans, right - left + 1중 더 작은 값을 ans에 넣기, left++ 해준다.
  언제까지? right가 벗어나려고 할 때까지
*/

// 풀이성공, 27분 소요
#include <bits/stdc++.h>
using namespace std;

int N, S;
int arr[100010];
int ans = 100000001;

int sum(int a, int b) {
  int result = 0;

  for (int i = a; i <= b; i++) {
    result += arr[i];
  }

  return result;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> S;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  int left = 0;
  int right = 0;
  int numSum = arr[left];

  while (right < N) {

    // left가 right보다 크면 숫자 S와 같거나 큰 숫자를 만난 것이므로 ans = 1, break;
    if (left > right) {
      ans = 1;
      break;
    }


    // S보다 같 or 크면 최솟값 갱신하고 left++.
    if (numSum >= S) {
      ans = min(ans, right - left + 1);
      numSum -= arr[left++];
    }

    // S보다 작으면 right++
    else if (numSum < S) {
      numSum += arr[++right];
    }
  }

  if (ans == 100000001) cout << 0;
  else cout << ans;
}