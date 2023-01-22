#include <bits/stdc++.h>
using namespace std;
// 풀이 실패.
stack<string> s;

string input;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> input;
  string temp = "";

  for (int i = 0; i < input.size(); i++) {
    if (input[i] != '-' && input[i] != '+') {
      temp += input[i];
    }
    else {
      string a = "";
      s.push(temp);
      s.push(a + input[i]);
      temp = "";
    }
  }
  s.push(temp);
  
  while (s.size() > 1) {
    int num1 = stoi(s.top());
    int num2;
    s.pop();

    if (!s.empty() && s.top() == "+") {
      s.pop();
      num2 = stoi(s.top()); s.pop();
      s.push(to_string(num1 + num2));
    }

    else if (!s.empty() && s.top() == "-") {
      s.pop();
      num2 = stoi(s.top()); s.pop();
      s.push(to_string(num2 - num1));
    }
  }

  cout << stoi(s.top());
}