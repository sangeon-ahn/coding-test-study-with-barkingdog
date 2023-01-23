#include <bits/stdc++.h>
using namespace std;
// 소요시간 16분, 틀림
/*
  N보다 작은 제곱수까지만 구한 후, 뒤에서부터 추가해가면서 합이 N이 될 때까지 더하면 최소값.
*/

int N;
vector<int> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 1; i <= sqrt(N); i++) {
    v.push_back(i*i);
  }
  
  int sum = 0;
  int count = 0;
  int right = v.size() - 1;

  while (sum != N) {
    if (N - sum >= v[right]) {
      sum += v[right];
      cout << v[right] << ' ';
      count++;
    } else {
      right--;
    }
  }

  cout << count;
}
