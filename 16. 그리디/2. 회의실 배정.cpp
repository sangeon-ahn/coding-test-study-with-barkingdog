// 내 풀이, 회의가 시작하자마자 바로 끝나는 경우의 예외처리도 해주어야 한다. 따라서 일단 끝나는 시간이 빠른 순으로 1차 정렬을 수행한 후, 같은 시간에 끝난다면 시작 시간이 이른 회의가 더 앞에 와야 한다.
// 이걸 구현하려면 pair의 first값에 끝나는 시간을 두고 second 값에 시작시간을 두면 된다.
// 그런 다음, sort함수에 넣으면 sort함수의 특성인 pair의 첫 인자끼리 비교 -> 같은 경우 pair의 두번째 인자끼리 비교 를 수행한다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
pair<int, int> v[1000000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;

    v[i].first = b;
    v[i].second = a;
  }

  sort(v, v+N);

  int end_time = 0;
  int ans = 0;

  for (int i = 0; i < N; i++) {
    if (v[i].second < end_time) continue;
    end_time = v[i].first;
    ans += 1;
  }

  cout << ans;
}
// 바킹독 풀이

int n;
pair<int, int> a[1000005];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i].second >> a[i].first;
  }
  sort(a, a+n);

  int ans = 0;
  int t = 0;
  for (int i = 0; i < n; i++) {
    if (t > a[i].second) continue;
    ans++;
    t = a[i].first;
  }
  cout << ans;
}