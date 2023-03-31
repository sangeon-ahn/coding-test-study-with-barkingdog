// 백트래킹의 두번째 인자에 for문 시작 인덱스를 넣는 방식으로 풀어보자
#include <bits/stdc++.h>
using namespace std;

int N, M;
int nums[10];
int arr[10];

void backtracking(int size, int start) {
  if (size == M) {
    for (int i = 0; i < M; i++) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }

  int temp = 0;
  for (int i = start; i < N; i++) {
    if (temp != nums[i]) {
      arr[size] = nums[i];
      temp = nums[i];
      backtracking(size + 1, start + 1);
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