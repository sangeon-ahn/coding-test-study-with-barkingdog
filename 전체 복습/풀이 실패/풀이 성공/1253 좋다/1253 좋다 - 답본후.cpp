#include <bits/stdc++.h>
using namespace std;

int N;
int arr[2010];
int result;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + N);

  for (int i = 0; i < N; i++) {
    int val = arr[i];
    int left = 0;
    int right = N - 1;

    while (left < right) {
      int sum = arr[left] + arr[right];

      if (sum == val) {
        if (i != left && i != right) {
          result++;
          break;
        } else if (i == left) {
          left++;
        } else if (i == right) {
          right--;
        }
      } else if (sum < val) {
        left++;
      } else {
        right--;
      }
    }
  }

  cout << result;
}