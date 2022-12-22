#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, L, ans;
vector<int> arr;
vector<int> dist;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> L;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    arr.push_back(a);
    cout << arr[i];
  }

}