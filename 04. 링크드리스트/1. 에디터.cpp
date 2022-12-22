#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s1;
  list<char> L = {};
  int N;
  bool leftFlag = true;
  cin >> s1;
  cin >> N;
  for (char c: s1) {
    L.push_back(c);
  }
  auto t = L.end();

  for (int i = 0; i < N; i++) {
    char X, Y;
    cin >> X;

    if (X == 'P') cin >> Y;

    if (X == 'P') {
      L.insert(t, Y);
    }
    else if (X == 'L')
    {
      if (t == L.begin()) continue;
      t--;
    }
    else if (X == 'D')
    {
      if (t == L.end()) continue;
      t++;
    }
    else if (X == 'B')
    {
      if (t == L.begin()) continue;
      t--;
      t = L.erase(t);
    }
  }
  for (auto c: L) cout << c;
}