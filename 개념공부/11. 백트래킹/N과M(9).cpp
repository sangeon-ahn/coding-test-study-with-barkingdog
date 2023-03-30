#include <bits/stdc++.h>
using namespace std;

int counts[10];
int nums[10];
int idxes[10];
int N, M;

void backtracking(int size) {
  if (size == M) {
    for (int i = 0; i < M; i++) {
      cout << nums[idxes[i]] << ' ';
    }
    cout << '\n';
    return;
  }

/*
 백트래킹 끝나고 다음 i 시작할 때 temp값이랑 지금 가리키는 nums[i]값이랑 같으면, 이후에 진행되는 수열들은 모두 이전에 나온 수열들에 이미 포함되는 걸 확인했다.-> 이럴수밖에 없다.ㄴ
*/
  int temp = 0;
  for (int i = 0; i < N; i++) {
    if (counts[nums[i]] > 0 && temp != nums[i]) {
      idxes[size] = i;
      temp = nums[i];
      counts[nums[i]]--;
      backtracking(size + 1);
      counts[nums[i]]++;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> nums[i];
    counts[nums[i]]++;
  }

  sort(nums, nums + N);

  backtracking(0);
}

/*
  4 2
  9 7 9 1

*/