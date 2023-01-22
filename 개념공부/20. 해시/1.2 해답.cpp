/*
  내 답과 다른 점들
  1. map 대신 set 사용
  2. 정렬하기 위해 벡터를 선언하는 방식이 간단
*/

#include <bits/stdc++.h>
using namespace std;

unordered_set<string> s;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  while (n--) {
    string name, log;
    cin >> name >> log;
    if (log == "enter") s.insert(name);
    else s.erase(name);
  }

  vector<string> ans(s.begin(), s.end());
  sort(ans.begin(), ans.end(), greater<string>());

  for (auto x: ans) cout << x << '\n';
}