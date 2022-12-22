#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  int ans = 0;
  cin >> N;

  for (int i = 0; i < N; i++) {
    string s1;
    stack<char> S;
    getline(cin, s1);
    int A_num = 0;
    int B_num = 0;
    bool isValid = true;

    for (char c: s1) {
      if (S.empty()) {
        if (c == 'A') A_num++;
        else B_num++;
        S.push(c);
      }
      else if (c == 'A') {
        if (S.top() != 'A' && A_num > 0) {
          isValid = false;
          break;
        }
        else if (S.top() == 'A') {
          S.pop();
        }
        else S.push(c);
      }
      else if (c == 'B') {
        if (S.top() != 'B' && B_num > 0) {
          isValid = false;
          break;
        }
        else if (S.top() == 'B') S.pop();
        else S.push(c);
      }
    }
    if (!isValid) continue;
    if (S.empty()) ans++;
  }
  cout << ans;
}

// 바킹독 풀이.
int n, ans = 0;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  while (n--) {
    string a;
    cin >> a;
    stack<int> S;
    for (auto c: a) {
      if (!S.empty() && S.top() == c) S.pop();
      else S.push(c);
    }
    if (S.empty()) ans++;
  }
  cout << ans << '\n';
}