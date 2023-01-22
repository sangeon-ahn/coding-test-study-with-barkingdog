#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> v;

// true를 리턴하면 위치를 그대로 하고, false면 swap.
bool compare(string s1, string s2) {
  // 규칙 1. A와 B의 길이가 다르면 짧은게 먼저 온다.
  if (s1.size() != s2.size()) {
    return s1.size() < s2.size();
  }

  // 규칙 2. 길이가 같으면 숫자의 합이 작은게 먼저온다.
  if (s1.size() == s2.size()) {
    int s1_sum = 0;
    int s2_sum = 0;

    // 숫자의 합을 구한다.
    for (int i = 0; i < s1.size(); i++) {
      int temp = s1[i] - '0';

      if (0 <= temp && temp <= 9) {
        s1_sum += temp;
      }
      temp = (int)s2[i] - '0';

      if (0 <= temp && temp <= 9) {
        s2_sum += temp;
      }
    }

    if (s1_sum != s2_sum) {
      return s1_sum < s2_sum;
    }
  }

  // 규칙 3. 사전순으로 비교.
  return s1 < s2;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  // 시리얼 입력받아 v에 넣기.
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    v.push_back(s);
  }

  // 규칙대로 정렬하기.
  sort(v.begin(), v.end(), compare);

  for (string s: v) {
    cout << s << '\n';
  }
}