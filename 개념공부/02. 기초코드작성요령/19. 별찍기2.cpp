#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (j < N - i - 1) cout << ' ';
      else cout << '*';
    }
    cout << '\n';
  }
}