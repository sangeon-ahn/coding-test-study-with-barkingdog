#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string a, b;
  cin >> a >> b;

  int ans = 0;
  int arr[26] = {};

  for (auto c: a) arr[c - 'a']++;
  for (auto c: b) arr[c - 'a']--;

  for (auto num: arr) {
    if (num < 0) ans += -num;
    else ans += num;
  }

  cout << ans;
}

//바킹독 풀이
// 두 문자열에 대해 각각 배열을 만드는게 아니라 2차원 배열로 만들었다.
int arr[2][26], res;
string s1, s2;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s1 >> s2;

  for (char c: s1) arr[0][c - 'a']++;
  for (char c: s2) arr[1][c - 'a']++;

  // c++에는 abs 절대값 함수가 있다.
  for (int i = 0; i < 26; i++) res += abs(arr[0][i] - arr[1][i]);

  cout << res;
}