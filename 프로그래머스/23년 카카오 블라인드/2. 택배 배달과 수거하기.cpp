#include <bits/stdc++.h>
using namespace std;
// empty() 조건을 안붙여서 10~20분 낭비 + 한군데를 Cap 대신 cap으로 써서 시간을 20분~30분 낭비
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
  long long answer = 0;

  /*
    스택 두개를 만들어서 deliveries와 pickups를 각각 넣고 top을 확인해서 0이면 뺀다.
    이동거리는 둘 중 더 먼곳까지의 거리 * 2 이다.
  */

  stack<int> delis;
  stack<int> picks;

  for (int i = 0; i < deliveries.size(); i++) {
    delis.push(deliveries[i]);
    picks.push(pickups[i]);
  }

  // 모든 배달과 수거가 끝날 때까지 돌기. 둘 중 하나라도 비어있지 않으면 true
  while (!delis.empty() || !picks.empty()) {

    // top이 0이면 빼고 패스
    if (!delis.empty() && delis.top() == 0) {
      delis.pop();
      continue;
    }

    if (!picks.empty() && picks.top() == 0) {
      picks.pop();
      continue;
    }

    int Cap = cap;
    // 거리 구해서 더하기
    long long dist = delis.size() >= picks.size() ? delis.size() * 2 : picks.size() * 2;
    answer += dist;
    cout << dist;
    // deliveries에서 빼기

    while (!delis.empty() && Cap > 0) {
      int d = delis.top();
      delis.pop();

      if (d > Cap) {
        delis.push(d - Cap);
        Cap = 0;
      } else if (d < Cap){
        Cap -= d;
      } else if (d == Cap) {
        Cap = 0;
      }
    }

    Cap = cap;

    while (!picks.empty() && Cap > 0) {
      int p = picks.top();
      picks.pop();

      if (p > Cap) {
        picks.push(p - Cap);
        Cap = 0;
      } else if (p < Cap) {
        Cap -= p;
      } else if (p == Cap) {
        Cap = 0;
      }
    }
  }

  return answer;
}