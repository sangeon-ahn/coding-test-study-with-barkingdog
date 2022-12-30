#include <bits/stdc++.h>
using namespace std;

void map_example() {
  map<string, int> m;
  m["hi"] = 123;
  m["bkd"] = 1000;
  cout << m.size() << '\n';

  m["hi"] = 7;
  
  if (m.find("hi") != m.end()) cout << "hi in m\n";
  else cout << "hi not in m\n";

  m.erase("bkd");
  
  for (auto e: m) {
    cout << e.first << ' ' << e.second << '\n';
  }
  auto it1 = m.find("hi");
  cout << it1->first << ' ' << it1->second << '\n';
}


int main() {
  map_example();
}