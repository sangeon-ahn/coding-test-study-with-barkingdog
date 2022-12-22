#include <iostream>
#include <string>
#include <stack>
using namespace std;

// const int MX = 1000005;
// int dat[MX];
// int pos = 0;

int main() {
  int N;
  cin >> N;
  stack<int> S;

  for (int i = 0; i < N; i++) {
    string inst;
    int value;
    cin >> inst;

    if (inst == "push") {
      cin >> value;
      S.push(value);
    }
    else if (inst == "top") {
      if (S.empty()) cout << -1 << '\n';
      else cout << S.top() << '\n'; 
    }
    else if (inst == "size") cout << S.size() << '\n';
    else if (inst == "pop") {
      if (S.empty()) cout << -1 << '\n';
      else {
        cout << S.top() << '\n';
        S.pop();
      }
    }
    else if (inst == "empty") {
      if (S.empty()) cout << 1 << '\n';
      else cout << 0 << '\n';
    }
  }
}