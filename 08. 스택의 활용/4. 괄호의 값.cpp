#include <iostream>
#include <stack>
#include <string>
using namespace std;

// int main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   string s1;
//   stack<char> S;
//   cin >> s1;
//   int sl = s1.length();
//   int multiple = 1;
//   int ans = 0;
//   for (int i = 0; i < sl; i++) {
//     if (s1[i] == '(') {
//       if (s1[i+1] != ')') {
//         multiple *= 2;
//         S.push(s1[i]);
//       } else {
//         ans += multiple * 2;
//         S.pop();
//       }
//     } else if (s1[i] == '[') {
//       if (s1[i+1] != ']') {
//         multiple *= 3;
//         S.push(s1[i]);
//       } else {
//         ans += multiple * 3;
//         S.pop();
//       }
//     } else if (s1[i] == ']') {
//       if (!S.empty() && S.top() == '[') {
//         S.pop();
//       } else ans = 0; break;
//     } else if (s1[i] == ')') {
//       if (!S.empty() && S.top() == '(') {
//         S.pop();
//       } else ans = 0; break;
//     }
//   }
//   cout << ans;
// }

// 바킹독 풀이
// 그냥 ( 나오면 곱하기 2 하고, [ 나오면 곱하기 3 하는식으로 햇음

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s1;
  stack<char> S;
  cin >> s1;
  int multiple = 1;
  int ans = 0;

  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] == '(') {
      multiple *= 2;
      S.push(s1[i]);
    } else if (s1[i] == '[') {
      multiple *= 3;
      S.push(s1[i]);
    } else if (s1[i] == ')') {
      // 비어있거나 차있을 때 탑이 (이 아니면 리턴.
      if (S.empty() || S.top() != '(') {
        cout << 0;
        return 0;
      }
      // S.top()으로 하게되면 ()같이 붙어있는 경우만을 타겟으로 하는게 아니게되서 안된다.
      if (s1[i-1] == '(') {
        ans += multiple;
      }
        multiple /= 2;
        S.pop();
    } else if (s1[i] == ']') {
      if (S.empty() || S.top() != '[') {
        cout << 0;
        return 0;
      }
      if (s1[i-1] == '[') {
        ans += multiple;
      }
        multiple /= 3;
        S.pop();
    }
  }
  if (S.empty()) cout << ans;
  else cout << 0;
}