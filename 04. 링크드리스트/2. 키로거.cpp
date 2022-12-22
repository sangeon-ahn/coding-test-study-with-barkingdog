#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    string s1;
    cin >> s1;

    list<char> pwd = {};
    auto cursor = pwd.end();

    for (char c: s1) {
      if (c == '<') {
        if (cursor != pwd.begin()) cursor--;
      }
      else if (c == '>') {
        if (cursor != pwd.end()) cursor++;
      }
      else if (c == '-') {
        if (cursor != pwd.begin()) {
          cursor--;
          cursor = pwd.erase(cursor);
        }
      }
      else {
        pwd.insert(cursor, c);
      }
    }
    for (auto c: pwd) cout << c;
    cout << '\n';
  }
}