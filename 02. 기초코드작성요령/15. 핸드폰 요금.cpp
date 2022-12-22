#include <iostream>
#include <cmath>

using namespace std;

int N, arr[21];
int Y, M;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 1; i < N+1; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i < N+1; i++) {
    if (arr[i] % 30 == 0) Y += 10 * (arr[i] / 30);
    else Y += 10 * ((arr[i] / 30) + 1);
  }

  for (int i = 1; i < N+1; i++) {
    if (arr[i] % 60 == 0) M += 15 * (arr[i] / 60);
    else M += 15 * ((arr[i] / 60) + 1);
  }

  if (Y == M) cout << 'Y' << ' ' << 'M' << ' ' << Y; // cout << 'Y M ' << Y
  else if (Y > M) cout << 'M' << ' ' << M;
  else if (Y < M) cout << 'Y' << ' ' << Y;
}

