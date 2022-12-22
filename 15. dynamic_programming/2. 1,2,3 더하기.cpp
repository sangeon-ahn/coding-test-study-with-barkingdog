/*
  d[1] = {{1}}
  d[2] = {(1+1), (2)}
  d[3] = {(1+1+1), (1+2), (2+1), (3)}
  d[4] = {(1+1+1+1), (2+1+1), (1+2+1), (1+1+2), (3+1), (1+3), (2+2)}
  d[5] = {(1+1+1+1+1), (2+2+1), (2+3), (1+1+3), (1+1+1+2)} = 1+3+2+3+4 = 14가지

*/

#include <iostream>
using namespace std;

int d[100];
int T;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;

  d[1] = 1;
  d[2] = 2;
  d[3] = 4;

  for (int i = 0; i < T; i++) {
    int n;
    cin >> n;

    for (int j = 4; j <= n; j++) {
      d[j] = d[j-1]+d[j-2]+d[j-3];
    }
    cout << d[n];
  }
}