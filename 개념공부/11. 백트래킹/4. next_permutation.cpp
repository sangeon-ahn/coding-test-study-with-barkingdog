#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// int a[3] = {1, 1, 3};
// int b[4] = {0, 0, 1, 1};

// // int main(void) {
// //   do {
// //     for (int i = 0; i < 3; i++) {
// //       cout << a[i];
// //     }
// //     cout << '\n';
// //   } while (next_permutation(a, a+3));
// // }
// int main(void) {
//   do {
//     for (int i = 0; i < 4; i++) {
//       if (b[i] == 0) {
//         cout << i+1;
//       }
//     }
//     cout << '\n';
//   } while (next_permutation(b, b+4));
// }
vector<pair<int, int>> chickens = {{10, 20}, {31, 51}, {63, 15}, {783, 52}, {1, 1}};
int arr[5] = {0, 0, 0, 1, 1};
int M = 2;
int N = 6;
int board[100][100];
int main(void) {
  vector<int> v = {0, 0, 1, 1, 1};

  do {
    vector<int> temp_v;
    for (int i = 0; i < chickens.size(); i++) {
      if (i < M) {
        temp_v.push_back(0);
      } else {
        temp_v.push_back(1);
      }
    }

    // vector<pair<int, int>> v2;
    for (int i = 0; i < v.size(); i++) {
      if (v[i] == 0) {
        // v2.push_back(chickens[i]);
        cout << chickens[i].first << ' ' << chickens[i].second << ' ' << '\n';
      }
    }

  } while (next_permutation(v.begin(), v.end()));
}