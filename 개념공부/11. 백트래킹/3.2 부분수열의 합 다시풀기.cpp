#include <iostream>
using namespace std;

int N, S, ans;
int arr[40];
// 다시풀기 실패
void func(int cur, int tot) {
  if (cur == N) {
    if (tot == S) ans++;
    return;
  }

}
// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   cin >> N >> S;
//   for (int i = 0; i < N; i++) {
//     cin >> arr[i];
//   }

//   func(0, 0);
// }

// 이 문제는 각 숫자가 1, 23, -3, 4 뭐 이런식으로 들어온다고 쳤을 때, 1의 인덱스를 0으로 잡고
// 각 숫자를 더할지 말지 이렇게 2가지 갈래로 각각 들어가주면 된다.
// 그리고 모든 숫자에 대해 더할지 말지를 정했을 때(cur == n) 이때 합이 주어진 값과 같은지를 보면 된다.

void func2(int cur, int tot) {
  if (cur == N) {
    if (tot == S) {
      ans++;
    }
    return;
  }
  
  func2(cur+1, tot);
  func2(cur+1, tot+arr[cur]);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> S;

  for (int i=0; i<N; i++) {
    cin >> arr[i];
  }

  func2(0, 0);
  
  if (S == 0) ans--;
  cout << ans;
}
