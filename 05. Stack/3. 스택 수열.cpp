#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  stack<int> S;
  int N;
  cin >> N;
  int count = 0;
  int b = 1;
  vector<int> V;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    while (b <= a) {
      S.push(b);
      V.push_back(1);
      b++;
    }
    if (S.top() == a) {
      S.pop();
      V.push_back(0);
    }
  }

  if (!S.empty()) cout << "NO";
  else {
    for (int n: V) {
      if (n) cout << "+" << '\n';
      else cout << "-" << '\n';
    }
  }
}

// 바킹독 풀이
// 문자열에 답을 저장하다가 안될때 cout한다음 리턴.
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  stack<int> S;
  int cnt = 1;
  string ans;
  while (n--) {
    int t;
    cin >> t;
    while (cnt <= t) {
      S.push(cnt++);
      ans += "+\n";
    }
    if (S.top() != t) {
      cout << "NO\n";
      return 0;
    }
    S.pop();
    ans += "-\n";
  }
}