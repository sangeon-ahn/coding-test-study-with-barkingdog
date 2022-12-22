#include <iostream>

using namespace std;

int arr1[100000];
int arr2[2000000];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, X;
  int count = 0;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr1[i];
  }

  cin >> X;
  for (int i = 0; i < N; i++) {
    arr2[arr1[i]]++;
    // x - a[i] > 0 조건도 추가해야 함.
    if (X - arr1[i] > 0 && arr2[X - arr1[i]]) count++;
  }

  cout << count;
}