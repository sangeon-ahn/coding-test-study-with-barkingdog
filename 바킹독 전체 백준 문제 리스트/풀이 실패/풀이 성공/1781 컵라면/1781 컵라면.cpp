/*
  우선 컵라면 수가 큰 순서대로 내림차순 정렬을 한다.
  컵라면 수가 같으면 데드라인을 기준으로 오름차순 정렬한다.
  for문을 돌면서 데드라인과 지난 시간을 비교하며, 시간이 남았으면 풀어서 컵라면을 얻는다.
*/

#include <bits/stdc++.h>
using namespace std;
// 풀이 실패

int N;
vector<pair<int, int>> v;

bool compare(pair<int, int> p1, pair<int, int> p2) {
  // 두 문제가 컵라면 수가 같으면 데드라인 오름차순.
  if (p1.first == p2.first) {
    return p1.second <= p2.second;
  }

  // 컵라면 수로 내림차순.
  return p1.first >= p2.first;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;

    v.push_back({b, a});
  }

  // 문제 정렬.
  sort(v.begin(), v.end(), compare);

  // 경과 시간.
  int time = 0;
  int ans = 0;

  // 경과 시간과 데드라인을 비교하여 풀 수 있는 문제면 푼다.
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].first << " " << v[i].second << '\n';
    if (time < v[i].second) {
      ans += v[i].first;
      time++;
    }
  }

  cout << ans;
}