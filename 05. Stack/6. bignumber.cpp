#include <iostream>
#include <vector>
#include <stack>
using namespace std;


// 테케는 맞았는데 돌려보니 틀림
// int main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   int N;
//   cin >> N;
//   vector<int> V;
//   bool isBig = false;
  
//   for (int i = 0; i < N; i++) {
//     int A;
//     cin >> A;
//     V.push_back(A);
//   }

//   for (int i = 0; i < N - 1; i++) {
//     for (int j = i+1; j < N; j++) {
//       if (V[i] < V[j]) {
//         isBig = true;
//         cout << V[j] << ' ';
//         break;
//       }
//     }
//     if (!isBig) cout << -1 << ' ';
//   }
//   cout << -1;
// }

// 바킹독 풀이
int a[1000000];
int ans[1000000];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) cin >> a[i];
  stack<int> S;

  for (int i = n - 1; i >= 0; i--) {
    while (!S.empty() && S.top() <= a[i]) S.pop();
    if (S.empty()) ans[i] = -1;
    else ans[i] = S.top();
    S.push(a[i]);
  }
  
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}