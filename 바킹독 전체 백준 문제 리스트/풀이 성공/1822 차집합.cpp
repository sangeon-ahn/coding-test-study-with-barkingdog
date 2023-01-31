/*
  set을 써서 풀어보자.
  집합 B를 먼저 set에 넣은 후에, A의 원소를 set에서 find로 찾아봤을 때 없으면 ans 벡터에 넣기
*/

// 풀이 성공, 10분.
#include <bits/stdc++.h>
using namespace std;

int A, B;
vector<int> v;
set<int> s;
vector<int> ans;

int arrA[500010];
int arrB[500010];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> A >> B;

  // A집합 데이터 입력.
  for (int i = 0; i < A; i++) {
    cin >> arrA[i];
  }

  // B집합 데이터 입력..
  for (int i = 0; i < B; i++) {
    int b;
    cin >> b;

    arrB[i] = b;
    s.insert(b);
  }

  // 차집합 생성.
  for (int i = 0; i < A; i++) {
    auto p = s.find(arrA[i]);

    if (p == s.end()) {
      ans.push_back(arrA[i]);
    }
  }

  // 차집합이 없는 경우.
  if (ans.size() == 0) {
    cout << 0;
    return 0;
  }

  // 차집합 있는 경우.
  cout << ans.size() << '\n';

  sort(ans.begin(), ans.end());

  for (int a: ans) {
    cout << a << ' ';
  }
}