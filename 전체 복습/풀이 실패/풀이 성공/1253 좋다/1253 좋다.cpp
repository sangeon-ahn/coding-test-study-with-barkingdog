#include <bits/stdc++.h>
using namespace std;
// 시간초과.
int N;
bool isGood[2010];
/*
  시간복잡도 판단.
  sort 오름차순 정렬 2000log2000
  수의 개수 = 2000개
  2000개 중 2개를 고르는 경우의 수 2000C2
  두 수를 더한 후 arr에 있는지 확인: log2000
  있으면 isGood에 표시.
  = 2000log2000 + 2000*1999/2 * log2000 ~= 100만.
*/
set<int> s;
vector<long long> arr;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  // N개의 수를 입력받는다.
  for (int i = 0; i < N; i++) {
    long long a;
    cin >> a;
    arr.push_back(a);
  }
  // 오름차순 정렬.
  sort(arr.begin(), arr.end());

  // 0을 2개, 1을 N-2개 넣는다.
  vector<int> v;
  for (int i = 0; i < 2; i++) {
    v.push_back(0);
  }
  for (int i = 0; i < N - 2; i++) {
    v.push_back(1);
  }

  // 경우의 수를 모두 따진다.
  do
  {
    int sumNum = 0;
    set<int> vv;
    for (int i = 0; i < v.size(); i++) {
      if (v[i] == 0) {
        sumNum += arr[i];
        v.push_back(i);
      }
    }

    // arr에 sumNum이 있으면 set에 추가.
    // arr에 sumNum이 있으면 *it == sumNum이다.
    auto it = lower_bound(arr.begin(), arr.end(), sumNum);

    if (*it == sumNum && vv.lower_bound(it - arr.end()) != vv.end()) {
      s.insert(sumNum);
    }
  } while (next_permutation(v.begin(), v.end()));
  cout << s.size();
}