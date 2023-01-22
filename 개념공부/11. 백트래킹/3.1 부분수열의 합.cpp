#include <iostream>
#include <vector>
using namespace std;

int N, S;
int arr[50];
bool isused[50];
int ans;
void func(int sum, int len) {
  if (sum == S && len != 0) {
    ans++;
    return;
  }
  
  for (int i = 0; i < N; i++) {
    if (!isused[i]) {
      isused[i] = 1;
      func(sum+arr[i], len+1);
      isused[i] = 0;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> S;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  func(0, 0);
  cout << ans;
}