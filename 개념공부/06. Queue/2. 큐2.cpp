#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  queue<int> Q;

  for (int i = 0; i < N; i++) {
    string inst;
    cin >> inst;
    if (inst == "push") {
      int X;
      cin >> X;
      Q.push(X);
    }
    else if (inst == "front") {
      if (Q.empty()) cout << "-1" << '\n';
      else cout << Q.front() << '\n';
    }
    else if (inst == "back") {
      if (Q.empty()) cout << "-1" << '\n';
      else cout << Q.back() << '\n';
    }
    else if (inst == "pop") {
      if (Q.empty()) cout << "-1" << '\n';
      else {
        cout << Q.front() << '\n';
        Q.pop();
      }
    }
    else if (inst == "size") {
      cout << Q.size() << "\n";
    }
    else if (inst == "empty") {
      cout << (int)Q.empty() << '\n';
    }
  }
}