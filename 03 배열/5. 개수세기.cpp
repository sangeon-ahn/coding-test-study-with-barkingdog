#include <iostream>

using namespace std;

int N, X;
int arr[100];
int ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  cin >> X;

  for (int i = 0; i < N; i++) {
    if (arr[i] == X) ans++;
  }

  cout << ans;
}