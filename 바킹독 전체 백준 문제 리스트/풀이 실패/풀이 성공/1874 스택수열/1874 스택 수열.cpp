#include <bits/stdc++.h>
using namespace std;

int N;
int arr[100010];
vector<int> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  stack<int> s;
  int idx = 0;
  int num = 1;

  // 아직 빼야할 숫자가 남아 있고, num이 N보다 같거나 작을때
  while (idx < N && num <= N) {
    // 스택 비어있으면 숫자 넣기.
    if (s.empty()) {
      cout << "1";
      s.push(num++);
      v.push_back(1);
    }

    // top이 수열이랑 다르면 숫자 넣기.
    else if (s.top() < arr[idx]) {
      cout << "2";
      s.push(num++);
      v.push_back(1);
    }

    // top이 수열이랑 같으면 pop시키기.
    else if (s.top() == arr[idx]) {
      cout << "3";
      s.pop();
      v.push_back(-1);
      idx++;
    }

    // s.top() > arr[idx]이면 NO
    else cout << "NO"; return 0;
  }

  for (int a : v) {
    if (a == 1) cout << "+\n";
    else cout << "-\n";
  }
}