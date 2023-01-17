#include <bits/stdc++.h>
using namespace std;

// 1. 문자열 delimiter로 나누기.
vector<string> split(string str, char delimiter) {
  string tmp;
  stringstream st(str);
  vector<string> result;

  while (getline(st, tmp, delimiter)) {
    result.push_back(tmp);
  }

  return result;
}

// 2. true: swap X, false: swap O.
bool compare(string s1, string s2) {
  return s1 < s2;
}
int main() {
  vector<string> v = {"A910", "145C"};
  sort(v.begin(), v.end(), compare);
  for (string s: v) {
    cout << s;
  }
}

// 3. set for문 돌리기
int main() {
  set<int> s;
  for (auto it = s.begin(); it != s.end(); it++) {
    cout << *it;
  }
}

// 4. map for문 돌리기
int main() {
  map<char, int> m;
  for (auto it = m.begin(); it != m.end(); it++) {
    cout << it->first;
    cout << it->second;
  }
}

// 5. 타입을 알아내는 방법
char c = '0';
typeid(c) // char