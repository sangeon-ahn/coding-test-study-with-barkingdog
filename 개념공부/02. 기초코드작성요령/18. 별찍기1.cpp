#include <iostream>
#include <string>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    string stars = "";

    for (int j = 0; j < i; j++) {
      stars += '*';
    }

    cout << stars << '\n';
  }
}