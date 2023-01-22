#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int avg = 0;
  int sum = 0;
  int mid_num = 0;
  int arr[5];

  for (int i = 0; i < 5; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  avg = sum /5;

  sort(arr, arr+5);

  mid_num = arr[2];

  cout << avg << '\n' << mid_num;
}