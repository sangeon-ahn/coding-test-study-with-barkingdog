#include <iostream>
#include <stack>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  stack<int> S;
  int N;
  int total = 0;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int Money;
    cin >> Money;

    if (Money != 0) {
      S.push(Money);
    } else {
      S.pop();
    }
  }

  while (!S.empty()) {
    total += S.top();
    S.pop();
  }

  cout << total;
}