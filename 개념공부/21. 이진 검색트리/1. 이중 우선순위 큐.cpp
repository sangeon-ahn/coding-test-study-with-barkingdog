#include <bits/stdc++.h>
using namespace std;

int T;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;

  for (int i = 0; i < T; i++) {
    int k;
    cin >> k;
    multiset<int> s;

    for (int j = 0; j < k; j++) {
      char c;
      int num;
      cin >> c >> num;

      if (c == 'I') {
        s.insert(num);
        continue;
      }

      if (c == 'D') {
        if (s.empty()) continue;
        if (num == 1) {
          s.erase(prev(s.end()));
        }
        else s.erase(s.begin());
      }
    }

    if (s.empty()) cout << "EMPTY";
    else {
      cout << *prev(s.end()) << ' ' << *s.begin();
    }
    cout << '\n';
  }
}