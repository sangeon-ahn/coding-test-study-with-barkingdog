#include <iostream>
using namespace std;

int N, M;
int arr[10];
int isused[10];

void func(int count) {
  if (count == M) {
    for (int i = 0; i < M; i++)  {
      cout << arr[i] << " ";
    }
    cout << "\n";
    return;
  }
  
  for (int i = 1; i <= N; i++) {
    if (!isused[i]) {
      arr[count] = i;
      isused[i] = 1;
      func(count+1);
      isused[i] = 0;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  
  func(0);
}