#include <bits/stdc++.h>
using namespace std;
// 풀이시간 50분
int N, S;
int arr[30];
int result;
void dfs(int idx, int count, int sum_count) {
  if (idx == N) {
    if (count == S && sum_count >= 1) {
      result++;
    }
    return;
  }

  // 안 더할 때
  dfs(idx + 1, count, sum_count);

  // 더할 때
  dfs(idx + 1, count + arr[idx], sum_count + 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> S;
  vector<int> v;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  // for (int i = 1; i < N; i++) v.push_back(1);
  // v.push_back(0);
  dfs(0, 0, 0);

  // for (int i = 1; i <= N; i++) {

  //   do
  //   {
  //     int ans = 0;

  //     for (int i = 0; i < N; i++) {
  //       if (v[i] == 0) {
  //         ans += arr[i];
  //       }
  //     }

  //     if (ans == S) result += 1;
  //     v.clear();

  //     for (int j = 2; j <= N; j++) {
  //       for (int k = 0; k < j; k++) {
  //         v.push_back(0);
  //       }
  //       for (int k = 0; k < N - j; k++) {
  //         v.push_back(1);
  //       }
  //     }

  //   } while (next_permutation(v.begin(), v.end()));

  // }
  cout << result;
}