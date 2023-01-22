#include <iostream>
#include <algorithm>
using namespace std;

// 테스트케이스는 통과, 제출은 실패
// 백트래킹 기법 사용
int N, K;
pair<int, int> arr[104];
int ans;

bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) {
    return a.second >= b.second;
  }

  return a.first < b.first;
}

void func(int idx, int total_weight, int total_value) {
  if (total_weight == K) {
    ans = max(ans, total_value);
    return;
  }

  if (idx >= N-1) return;

  if (total_weight > K) return;

  func(idx+1, total_weight, total_value);
  func(idx+1, total_weight+arr[idx+1].first, total_value+arr[idx+1].second);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;

  for (int i = 1; i <= N; i++) {
    cin >> arr[i].first >> arr[i].second;
  }
  sort(arr, arr+N, compare);

  func(0, 0, 0);
  cout << ans;
}

// dp 기법 사용
