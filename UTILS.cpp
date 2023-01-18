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
int main() {
  char c = '0';
  typeid(c); // char
}

// 6. pair를 sort로 정렬하면 앞에서부터 오름차순 정렬된다.
int main() {
  pair<int, int> arr[10];
  arr[0] = {2, 2};
  arr[1] = {1, 3};
  arr[2] = {1, 1};
  arr[3] = {1, 2};

  sort(arr, arr + 5);
  for (auto a: arr) {
    cout << a.first << ' ' << a.second << '\n';
  }
}

// 7. string에 char 더할 수 있다.
int main() {
  string a = "";
  cout << a + 'c';

  // "abc" + 'c'는 안된다.
}