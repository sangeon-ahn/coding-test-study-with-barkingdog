#include <bits/stdc++.h>
using namespace std;

int N, M;
int nums[10];
int idxes[10];


void backtracking(int size) {
  if (size == M) {
    for (int i = 0; i < M; i++) {
      cout << nums[idxes[i]] << ' ';
    }
    cout << '\n';
    return;
  }

  int st = 0;
  if (size != 0) st = idxes[size - 1] + 1;

  for (int i = st; i < N; i++) {
    idxes[size] = i;
    backtracking(size + 1);
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

  backtracking(0);
}