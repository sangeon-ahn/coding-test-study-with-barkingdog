#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// int N, M;
// int arr[10];
// int isused[10];

// void func(int n) {
//   if (n == M) {
//     sort(arr, arr+M-1);
//     for (int i = 0; i < M; i++) {
//       cout << arr[i] << ' ';
//     }
//     cout << '\n';
//     return;
//   }
  
//   for (int i = 0; i < N; i++) {
//     if (!isused[i+1]) {
//       arr[i] = i+1;
//       isused[i+1] = 1;
//       func(n+1);
//       isused[i+1] = 0;
//     }
//   }
// }

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   cin >> N >> M;
//   func(0);
// }

int N, M;
vector<int> v;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    if (i < M) {
      v.push_back(0);
    }
    else {
      v.push_back(1);
    }
  }

  for (int i = 0; i < N; i++) {
    cout << v[i];
  }

  // do {
  //   for (int i = 0; i < N; i++) {
  //     if (v[i] == 0) {
  //       cout << i+1 << ' ';
  //     }
  //     cout << '\n';
  //   } 
  // } while (next_permutation(v.begin(), v.end()));
}