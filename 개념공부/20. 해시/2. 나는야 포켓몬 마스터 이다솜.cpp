#include <bits/stdc++.h>
using namespace std;

int N, M;
unordered_map<string, int> umap;
string arr[100010];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  for (int i = 1 ; i <= N; i++) {
    string s;
    cin >> s;
    umap[s] = i;
    arr[i] = s;
    // cin >> arr[i];
    // umap[arr[i]] = i;
  }

  for (int i = 0; i < M; i++) {
    string s;
    cin >> s;
    if (isdigit(s[0])) {
      cout << arr[stoi(s)] << '\n';
    } else cout << umap[s] << '\n';
  }
}