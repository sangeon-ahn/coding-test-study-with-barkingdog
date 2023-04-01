#include <bits/stdc++.h>
using namespace std;
int n;
int x[1000005];
vector<int> uniq;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    uniq.push_back(x[i]);
  }
  sort(uniq.begin(), uniq.end());
  uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());
  for (int i = 0; i < n; i++) {
    cout << lower_bound(uniq.begin(), uniq.end(), x[i]) - uniq.begin() << ' ';
  }
}
