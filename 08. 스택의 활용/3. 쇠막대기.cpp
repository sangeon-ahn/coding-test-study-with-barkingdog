#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  stack<char> S;
  string s1;
  cin >> s1;
  int ans = 0;
  char prev = '(';

  for (char c : s1) {
    if (c == '(') {
      S.push(c);
      prev = '(';
    }
    else if (prev == '(' && c == ')') {
      S.pop();
      ans += S.size();
      prev = ')';
    }
    else {
      S.pop();
      ans++;
    }
    cout << ans << '\n';
  }
  cout << ans;
}

// 바킹독 풀이.
// 내 풀이랑 거의 같다.
// 다른 점은 나는 prev로 이전 값을 알아냈는데 바킹독은 그냥 s1[i-1]로 인덱스 접근해서 알아낸다는 점이다.
// 나는 이걸 생각 못했었다.