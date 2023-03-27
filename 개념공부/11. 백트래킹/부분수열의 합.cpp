#include <bits/stdc++.h>
using namespace std;

int N, S;
int arr[21];
long long ans = 0;

void backtracking(int count, int ssum) {
  if (count == N) {
    if (ssum == S) {
      ans++;
    }
    return;
  }

  backtracking(count + 1, ssum + arr[count]);
  backtracking(count + 1, ssum);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> S;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  backtracking(0, 0);
  if (S == 0) ans--;
  cout << ans;
}