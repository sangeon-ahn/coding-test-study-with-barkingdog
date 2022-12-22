#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int scoreNumber;
  cin >> scoreNumber;

  if (scoreNumber >= 90 && scoreNumber <= 100) {
    cout << 'A';
  } else if (scoreNumber >= 80) {
    cout << 'B';
  } else if (scoreNumber >= 70) {
    cout << 'C';
  } else if (scoreNumber >= 60) {
    cout << 'D';
  } else {
    cout << 'F';
  }
}