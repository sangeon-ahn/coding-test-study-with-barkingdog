// #include <algorithm>
// #include <vector>
// #include <iostream>
// using namespace std;

// vector<int> v;
// int main(void) {
//   int N, M;
//   cin >> N >> M;

//   for (int i = 0; i < N; i++) {
//     if (i < M) {
//       v.push_back(0);
//     } else {
//       v.push_back(1);
//     }
//   }
  
//   for (int i = 0; i < N; i++) {
//     cout << v[i];
//   }
// }

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> v;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  v[0] = 1;
  cout << v[0];
}