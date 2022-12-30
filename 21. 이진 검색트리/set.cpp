/*
  c++에서 set은 unordered set과 ordered set으로 나뉜다.
  unordered set은 말 그대로 순서가 보장되지 않는 set이다. 해시를 이용해서 구현할 수 있다.
  ordered set은 순서대로 정렬되고, 이진 트리로 구현해서 크기 순서대로 정렬되어 있다.
*/
#include <bits/stdc++.h>
using namespace std;
void set_example() {
  set<int> s;
  s.insert(-10); s.insert(100); s.insert(15);
  s.insert(-10);
  cout << s.erase(100) << '\n';
  cout << s.erase(20) << '\n';

  if (s.find(15) != s.end()) cout << "15 in s\n";
  else cout << "15 not in s\n";

  cout << s.size() << '\n';
  cout << s.count(50) << '\n';

  for (auto e: s) cout << e << ' ';
  cout << '\n';

  s.insert(-40);

  set<int>::iterator it1 = s.begin();
  it1++;
  auto it2 = prev(it1);
  it2 = next(it1);
  advance(it2, -2);

  auto it3 = s.lower_bound(-20);
  auto it4 = s.find(15);

  cout << *it1 << '\n';
  cout << *it2 << '\n';
  cout << *it3 << '\n';
  cout << *it4 << '\n';
}

int main() {
  set_example();
}