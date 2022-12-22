#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 틀림.
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  stack<char> S;
  bool pass = false;

  while (1) {
    char c;
    cin >> c;
    if (pass && c != '.') continue;
    if (c == '.') {
      pass = false;
      if (S.empty()) cout << "yes" << '\n';
      else cout << "no" << '\n';
    }
    else if (c == '^') break;
    else if (c == '(' || c == '[') {
      S.push(c);
    }
    else if (c == ')') {
      if (S.top() == '(') S.pop();
      else {
        cout << "no" << '\n';
        pass = true;
      }
    }
    else if (c == ']') {
      if (S.top() == '[') S.pop();
      else {
        cout << "no" << '\n';
        pass = true;
      }
    }
  }
}

// 바킹독 풀이
// stack 헤더에 getline 함수를 사용하면 한줄 받아올 수 있다.getline(cin, a)

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (true) {
    string a;
    getline(cin, a);
    if (a == ".") break;
    stack<char> s;
    bool isValid = true;
    for (auto c: a) {
      if (c == '(' || c == '[') s.push(c);
      else if (c == ')') {
        if (s.empty() || s.top() != '(') {
          isValid = false;
          break;
        }
        s.pop();
      }
      else if (c == ']') {
        if (s.empty() || s.top() != '[') {
          isValid = false;
          break;
        }
        s.pop();
      }
    }
    if (!s.empty()) isValid = false;
    if (isValid) cout << "yes\n";
    else cout << "no\n";
  }
}