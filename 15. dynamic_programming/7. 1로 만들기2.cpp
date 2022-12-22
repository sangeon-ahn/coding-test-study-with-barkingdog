#include <iostream>
using namespace std;

int N;
int D[1000010];
int arr[1000010];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  D[1] = 0;

  int idx = 0;

  for (int i = 2; i <= N; i++) {
    D[i] = D[i-1] + 1;

    int temp = i-1;

    if (i % 3 == 0) {
      if (D[i] >= D[i/3] + 1) {
        D[i] = D[i/3] + 1;
        temp = i/3;
      }
    }

    if (i % 2 == 0) {
      if (D[i] >= D[i/2] + 1) {
        D[i] = D[i/2] + 1;
        temp = i/2;
      }
    }

    arr[idx] = temp;
    idx++;
  }

  cout << D[N] << '\n';
  cout << N << ' ';


  int i = N - 2;

  while (i >= 0) {
    cout << arr[i] << ' ';
    i = arr[i] - 2;
  }
}