#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, L, ans;
vector<int> arr;
vector<int> dist;

// 그리디로 풀면 안된다. parametric search로 풀면 된다는데 아직 안배운거다.
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> L;

  arr.push_back(0);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    arr.push_back(a);
  }
  arr.push_back(L);

  sort(arr.begin(), arr.end());

  for (int j = 0; j < arr.size() - 1; j++) {
    dist.push_back(arr[j+1] - arr[j]);
  }
  
  for (int i = 0; i < M; i++) {
    int max_dist = *max_element(dist.begin(), dist.end());
    int max_dist_idx = max_element(dist.begin(), dist.end()) - dist.begin();
    int new_rest = arr[max_dist_idx] + (max_dist / 2);

    arr.push_back(new_rest);
    sort(arr.begin(), arr.end());

    vector<int> temp;
    for (int j = 0; j < arr.size() - 1; j++) {
      temp.push_back(arr[j+1] - arr[j]);
    }
    dist = temp;

    ans = max(ans, max_dist % 2 == 0 ? max_dist / 2 : (max_dist / 2) + 1);
  }

  cout << ans;
}