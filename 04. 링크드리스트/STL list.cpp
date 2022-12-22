#include <list>
#include <iostream>
using namespace std;

int main(void) {
  list<int> L = {1, 2};
  list<int>::iterator t = L.begin(); // auto t = L.begin();
  L.push_front(10);
  L.push_back(20);
  cout << *t << '\n';
  L.insert(t, 6);
  t++;
  t = L.erase(t);
  cout << *t << '\n';
  for (auto i: L) cout << i << ' ';
}