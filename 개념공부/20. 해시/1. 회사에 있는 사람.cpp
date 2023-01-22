#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int arr[1000010];
vector<string> v;

bool compare(string a, string b) {
  return a > b;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  unordered_map<string, string> umap;

  for (int i = 0; i < N; i++) {
    string name, status;
    cin >> name >> status;
    umap[name] = status;
  }

  for (auto e: umap) {
    if (e.second == "leave") continue;
    v.push_back(e.first);
  }

  sort(v.begin(), v.end(), compare);
  
  for (auto e: v) {
    cout << e << '\n';
  }
}