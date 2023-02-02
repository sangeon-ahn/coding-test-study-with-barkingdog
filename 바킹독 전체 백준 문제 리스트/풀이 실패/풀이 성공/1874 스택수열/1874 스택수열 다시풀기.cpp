#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  stack<int> s;
  vector<int> v;
  int num = 1;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;

    while (num <= a) {
      s.push(num++);
      v.push_back(1);
    }

    if (s.top() == a) {
      s.pop();
      v.push_back(0);
    }
  }

  if (!s.empty()) cout << "NO";
  else {
    for (int n : v) {
      if (n) cout << "+\n";
      else cout << "-\n";
    }
  }
}