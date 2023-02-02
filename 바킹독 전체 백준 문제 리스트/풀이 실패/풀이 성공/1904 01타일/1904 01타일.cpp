#include <bits/stdc++.h>
using namespace std;
/*
  00을 0 하나로 묶어서 순열을 돌린다.
  00이 0번, 1번, 2번, ... N/2번 나오는 경우의 순열을 구한다.
*/
int N;
int ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  int count = 0;

  for (int i = 0; i <= N/2; i++) {
    vector<int> v;
    
    for (int j = 0; j < N - i; j++) {
      v.push_back(1);
    }

    for (int j = 0; j < i; j++) {
      v[j] = 0;
    }

    do
    {
      ans++;
    } while (next_permutation(v.begin(), v.end()));

    ans %= 15746;
  }

  cout << ans;
}