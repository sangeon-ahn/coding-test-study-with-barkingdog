#include <bits/stdc++.h>
using namespace std;

vector<bool> broken(10, false);

bool check(int n) {
  string s = to_string(n);

  for (int i = 0; i < s.length(); i++) {
    if (broken[s[i] - 48]) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int a;
    cin >> a;
    broken[a] = true;
  }

  int minimum = abs(100 - N);
  for (int i = 0; i <= 1000000; i++) {
    if (check(i)) {
      string s = to_string(i);
      int temp = abs(N - i) + s.length();
      minimum = min(minimum, temp);
    }
  }

  cout << minimum;
}