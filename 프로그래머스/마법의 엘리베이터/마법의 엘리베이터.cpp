#include <bits/stdc++.h>

using namespace std;

int getNumber(int idx, int number) {
  // ex) idx = 0이면 1의 자리 수 구해서 준다.
  // 몫을 빼고, 나머지를 뺀다.
  // 8432이고 2을 구하려면 10으로 나눈 843에 10을 곱해서 빼면 2, 1으로 나누면 몫 2
  int temp = number / pow(10, idx + 1);
  temp *= pow(10, idx + 1);
  temp = number - temp;
  temp /= pow(10, idx);

  return temp;
}

int getNumLength(int num) {
  int n = 0;
  while (num > 0) {
    num /= 10;
    n++;
  }
  return n;
}

int solution(int storey) {
  int answer = 2147483647;
  // 자릿수를 구한다.
  int n = 0;
  int aa = storey;
  while (aa > 0) {
    aa /= 10;
    n++;
  }

  for (int i = 0; i < pow(2, n); i++) {
    int brute = i;
    vector<int> v;
    int sum = 0;
    int num = storey;

    for (int j = 0; j < n; j++) {
      int temp = brute % 2;
      v.push_back(temp);
      brute /= 2;
    }

    for (int j = 0; j < v.size(); j++) {
      int temp = getNumber(j, num);
      // cout << temp;
      if (temp == 0) continue;
      
      // 0이면 자릿수가 0 될때까지 더함. 1의 자리부터 시작.
      if (v[j] == 0) {
        sum += 10 - temp;
        num += pow(10, j) * (10 - temp);
      // 1이면 0 될때까지 뺌.
      } else if (v[j] == 1) {
        sum += temp;
        num -= pow(10, j) * (temp);
      }

      // 가장 큰 자릿수에서 0 될때까지 더한다면 다음 자릿수가 1 되므로 1을 빼줘야 한다.
      if (j == v.size() - 1 && v[j] == 0) {
        sum++;
      }
    }
    answer = min(answer, sum);
  }

  return answer;
}

int main() {
  cout << solution(78);
}