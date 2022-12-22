#include <iostream>
#include <cmath>

using namespace std;

int answer = 0;

void recursion(int n, int r, int c) {
  if (n == 0) {
    return;
  }

  if (pow(2, n- 1) > r && pow(2, n - 1) > c) {
    recursion(n - 1, r, c);
  } else if (pow(2, n - 1) > r && pow(2, n - 1) <= c) {
    answer += pow(2, n - 1) * pow(2, n - 1);
    recursion(n - 1, r, c - pow(2, n - 1));
  } else if (pow(2, n - 1) <= r && pow(2, n - 1) > c) {
    answer += 2 * (pow(2, n - 1) * pow(2, n - 1));
    recursion(n - 1, r - pow(2, n - 1), c);
  } else {
    answer += 3 * (pow(2, n - 1) * pow(2, n - 1));
    recursion(n - 1, r - pow(2, n - 1), c - pow(2, n - 1));
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, r, c;
  cin >> N >> r >> c;

  recursion(N, r, c);
  cout << answer;
}

