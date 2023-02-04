#include <bits/stdc++.h>
using namespace std;
/*
  일찍 시작하는 회의 순으로 정렬.
  똑같이 시작하는 경우, 일찍 끝나는 순으로 정렬.
  이후 회의 순회하면서 끝나는 시간 저장하고, 이 값 <= 다음 회의의 시작시간일 때 회의 선택.
*/


int N;
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b) {
  return a.second <= b.second;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }

  sort(v.begin(), v.end(), compare);

  int end_time = 0;
  int ans = 0;

  for (auto a: v) {
    cout << a.first << a.second << '\n';
    if (end_time <= a.first) {
      ans++;
      end_time = a.second;
    }
  }

  cout << ans;
}