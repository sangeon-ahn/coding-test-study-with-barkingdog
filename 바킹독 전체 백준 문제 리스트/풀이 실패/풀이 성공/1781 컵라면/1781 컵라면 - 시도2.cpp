/*
  이번에는 데드라인 순서대로 정렬해서 해보자
*/
#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> v;

bool compare(pair<int, int> p1, pair<int, int> p2) {
  // 데드라인이 같을 때 컵라면 수 내림차순.
  if (p1.first == p2.first) {
    return p1.second >= p2.second;
  }
  
  // 데드라인 기준 오름차순.
  return p1.first <= p2.first;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++) {
    // a: 데드라인, b: 컵라면수.
    int a, b;
    cin >> a >> b;
    
    v.push_back({a, b});
  }

  sort(v.begin(), v.end(), compare);

  int time = 0;
  long long ans = 0;

  // 문제 탐색 시작.
  for (int i = 0; i < v.size(); i++) {
    // 데드라인 안넘었으면 풀기.
    if (time < v[i].first) {
      ans += v[i].second;
      time++;
    }

    // 넘었으면 패스.
  }
  
  cout << ans;
}