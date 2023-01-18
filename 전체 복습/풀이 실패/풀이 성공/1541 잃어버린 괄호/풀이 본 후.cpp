#include <bits/stdc++.h>
using namespace std;

/*
  -인 순간부터는 다 빼주면 된다.
*/

int answer;
int sign = 1;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string input;
  cin >> input;

  string temp = "";

  for (int i = 0; i < input.size(); i++) {
    if (input[i] != '+' && input[i] != '-') {
      temp += input[i];
    } else {
      answer += stoi(temp) * sign;
      if (input[i] == '-') sign = -1;
      temp = "";
    }
  }
  answer += stoi(temp) * sign;
  cout << answer;
}