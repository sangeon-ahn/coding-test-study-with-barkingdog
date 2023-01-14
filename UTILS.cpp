#include <bits/stdc++.h>
using namespace std;

// 문자열 delimiter로 나누기.
vector<string> split(string str, char delimiter) {
  string tmp;
  stringstream st(str);
  vector<string> result;

  while (getline(st, tmp, delimiter)) {
    result.push_back(tmp);
  }

  return result;
}

// true: swap X, false: swap O.
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