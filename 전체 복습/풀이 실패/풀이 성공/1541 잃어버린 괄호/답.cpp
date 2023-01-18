#include <bits/stdc++.h>
using namespace std;

/*
  인풋으로 들어온 수식을 앞에서부터 살펴보다가 -가 들어온 순간 그 이후의 모든 숫자들은 뺄셈처리를 하면 최솟값을 만들어 낼 수 있다.
*/

int temp, answer;
int sign = 1;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string input;
  cin >> input;

  for (char c: input) {
    if (c != '+' && c != '-') {
      temp *= 10;
      temp += c - '0';
    }
    else {
      answer += temp * sign;
      if (c == '-') sign = -1;
      temp = 0;
    }
  }

  answer += temp * sign;
  cout << answer;
}