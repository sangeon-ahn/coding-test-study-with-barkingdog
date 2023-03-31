#include <bits/stdc++.h>
using namespace std;

int N, M;
int nums[10];
int arr[10];

void backtracking(int size, int order) {
  if (size == M) {
    for (int i = 0; i < M; i++) {
      cout << nums[i] << ' ';
    }
    cout << '\n';
    return;
  }

  int temp = 0;
  for (int i = order; i < N; i++) {
    if (temp != nums[i]) {
      arr[size] = nums[i];
      temp = arr[size];
      backtracking(size + 1, order + 1);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }
  sort(nums, nums + N);
  backtracking(0, 0);
}