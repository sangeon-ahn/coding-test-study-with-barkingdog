#include <bits/stdc++.h>
using namespace std;

int main() {
  pair<int, int> arr[10];
  arr[0] = {2, 2};
  arr[1] = {1, 3};
  arr[2] = {1, 1};
  arr[3] = {1, 2};

  sort(arr, arr + 5);
  for (auto a: arr) {
    cout << a.first << ' ' << a.second << '\n';
  }
}