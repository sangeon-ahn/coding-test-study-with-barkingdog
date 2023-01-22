#include <bits/stdc++.h>
using namespace std;
// 소요시간 14분
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;

  /*
    0과 1 연속된 부분을 각각 구한 후 더 작은 수가 답이다.
  */
  
  // 각 자리수를 더했을 때 0이거나 s의 길이면 모두 0 이거나 1이므로 0 리턴.
  int sum = 0;

  for (int i = 0; i < s.length(); i++) {
    sum += s[i] - '0';
  }

  if (sum == 0 || sum == s.length()) {
    cout << 0;
    return 0;
  }

  int zero_sector = 0;
  int one_sector = 0;

  bool zeroFlag = true;
  bool oneFlag = true;

  for (int i = 0; i < s.length(); i++) {
    if (zeroFlag && s[i] == '0') {
      zero_sector++;
      zeroFlag = false;
      oneFlag = true;
    }

    else if (oneFlag && s[i] == '1') {
      one_sector++;
      oneFlag = false;
      zeroFlag = true;
    }
  }

  int answer = zero_sector >= one_sector ? one_sector : zero_sector;

  cout << answer;
}