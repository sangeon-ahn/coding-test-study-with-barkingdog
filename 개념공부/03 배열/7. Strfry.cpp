#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// int main(void) {
  // ios::sync_with_stdio(0);
  // cin.tie(0);

  // int N;
  // cin >> N;

  // for (int i = 0; i < N; i++) {
  //   string a, b;
  //   cin >> a >> b;
  //   int arr1[26] = {};
  //   int arr2[26] = {};
  //   // cout << '\n';
  //   for (int j = 0; j < a.length(); j++) {
  //     arr1[a[j] - 'a']++;
  //     // cout << (int)a[j] << ' ';
  //   }
  //   // cout << '\n';
  //   for (int j = 0; j < b.length(); j++) {
  //     arr2[b[j] - 'a']++;
  //     // cout << (int)b[j] << ' ';
  //   }

  //   if (a.length() == b.length()) {
  //     bool c = true;

  //     for (int j = 0; j < 1000; j++) {
  //       if (arr1[j] != arr2[j]) {
  //         cout << "Impossible" << '\n';
  //         c = false;
  //         break;
  //       } else continue;
  //     }

  //     if (c) cout << "Possible" << "\n";
  //   }
  // }
// }

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    string a, b;
    cin >> a >> b;
    int arr1[26] = {};
    for (auto c : a) arr1[c - 'a']++;
    for (auto c : b) arr1[c - 'a']--;
    
    bool c = true;

    for (int j = 0; j < 26; j++) {
      if (arr1[j] != 0) {
        c = false;
      }
    }

    if (c) cout << "Possible" << "\n";
    else cout << "Impossible" << "\n";
  }
  // int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // for (auto c: arr) cout << c;

}