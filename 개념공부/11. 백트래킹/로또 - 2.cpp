#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (true) {
    int k;
    cin >> k;

    if (k == 0) break;

    int nums[14];
    for (int i = 0; i < k; i++) {
      cin >> nums[i];
    }
    sort(nums, nums + k);
    vector<int> vec(k, 1);
    
    for (int i = 0; i < 6; i++) {
      vec[i] = 0;
    }

    do {
      for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == 0) {
          cout << nums[i] << ' ';
        }
      }
      cout << '\n';
    } while(next_permutation(vec.begin(), vec.end()));
    cout << '\n';
  }
}