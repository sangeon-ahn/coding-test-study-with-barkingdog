#include <bits/stdc++.h>
using namespace std;
// 틀림.
int N, K;
vector<int> v;
set<int> s;
int selectToBeRemoved(int idx) {
  map<int, int> m;

  for (int i = idx; i < v.size() - 1; i++) {
    m[v[i]]++;
  }

  int minNum = 10000;
  int minIdx = 10000;
  for (int i = 0; i < N; i++) {
    if (minNum > m[v[i]]) {
      minNum = m[v[i]];
      minIdx = v[i];
    }
  }

  if (minIdx == 10000) {
    auto it = s.begin();
    minIdx = *it;
  }

  return minIdx;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;
  int count = 0;

  for (int i = 0; i < K; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }

  for (int i = 0; i < K; i++) {
    if (s.size() < 2) {
      s.insert(v[i]);
    }
    else {
      auto it = s.find(v[i]);
      if (it != s.end()) {
        continue;
      }
      int num = selectToBeRemoved(i);
      cout << num;
      s.erase(num);
      s.insert(v[i]);
      count++;
    }
  }

  cout << count;

}

/*
  
*/