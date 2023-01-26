#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> topping) {
  map<int, int> m1;
  map<int, int> m2;
  int answer = 0;

  for (int i = 0; i < topping.size(); i++) {
    m2[topping[i]]++;
  }

  for (int i = 0; i < topping.size() - 1; i++) {
    m1[topping[i]]++;
    m2[topping[i]]--;

    if (m2[topping[i]] == 0) m2.erase(topping[i]);
    if (m1.size() == m2.size()) answer++;
  }

  return answer;
}

int main() {
  int ans = solution({1, 2, 1, 3, 1, 4, 1, 2});
  cout << ans;
}