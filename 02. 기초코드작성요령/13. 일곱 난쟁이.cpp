#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int sum = 0;
  int arr[9];
  int fake;
  int a, b = 0;

  for (int i = 0; i < 9; i++) {
    cin >> arr[i];
    sum += arr[i];
  }

  fake = sum - 100;
  int arr2[101];

  sort(arr, arr+9);
  
  for (int i = 0; i < 9; i++) {
    arr2[arr[i]] = 1;

    if (arr2[fake - arr[i]]) {
      a = fake - arr[i];
      b = arr[i];
    }
  }

  for (int i = 0; i < 9; i++) {
    if (arr[i] != a && arr[i] != b) cout << arr[i] << '\n';
  }
}