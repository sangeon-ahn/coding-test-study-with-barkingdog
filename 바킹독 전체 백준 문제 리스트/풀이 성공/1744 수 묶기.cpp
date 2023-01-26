#include <bits/stdc++.h>
using namespace std;
/*
  숫자 무리를 음수, 0, 양수로 나눈 후,
  각각을 새로운 큐에 집어넣는다.
  그 후 음수의 개수가 홀수개라서 곱하기가 안된 수가 있을 때, 0이 있으면 없애고 0이 없으면 음수 더하기
  양수도 마찬가지로 큰 수끼리 곱해서 더하고, 홀수개라서 나머지 하나 생겼으면 더하기.
*/
int N;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  priority_queue<int, vector<int>, greater<int>> minusPq;
  priority_queue<int> plusPq;
  int zeroCount = 0;

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    
    if (x > 0) plusPq.push(x);
    else if (x < 0) minusPq.push(x);
    else zeroCount++;
  }

  int ans = 0;

  // 양수에 대해 계산.
  while (plusPq.size() > 1) {
    int a = plusPq.top(); plusPq.pop();
    int b = plusPq.top(); plusPq.pop();

    if (a == 1 || b == 1) ans += a + b;
    else ans += a * b;
  }

  // 양수가 홀수개라서 1개 남았으면 더하기.
  if (!plusPq.empty()) {
    ans += plusPq.top();
  }

  // 음수에 대해 계산..
  while (minusPq.size() > 1) {
    int a = minusPq.top(); minusPq.pop();
    int b = minusPq.top(); minusPq.pop();

    ans += a * b;
  }

  while (!minusPq.empty() && zeroCount > 0) {
    minusPq.pop();
    zeroCount--;
  }

  while (!minusPq.empty()) {
    ans += minusPq.top(); minusPq.pop();
  }

  cout << ans;
}