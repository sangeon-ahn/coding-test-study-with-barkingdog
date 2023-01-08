#include <bits/stdc++.h>
using namespace std;

int cap = 2;
int n = 7;
vector<int> deliveries = {1, 0, 2, 0, 1, 0, 2};
vector<int> pickups = {0, 2, 0, 1, 0, 2, 0};

bool isAllZero(vector<int> v1, vector<int> v2) {
  int a = 0;
  for (int v: v1) {
    a += v;
  }
  for (int v: v2) {
    a += v;
  }

  return a == 0;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    // 스택을 이용한 풀이.
    stack<int> d;
    stack<int> p;

    // 스택에 다 넣기.
    for (int i: deliveries) {
      d.push(i);
    }

    for (int i: pickups) {
      p.push(i);
    }

    // 뒤에서 부터 볼때 배송이나 수거가 0이면 없애버리기.
    while (!d.empty() || !p.empty()) {
      if (d.top() == 0) {
        d.pop();
        continue;
      }
      if (p.top() == 0) {
        p.pop();
        continue;
      }

      // 택배차는 가장 멀리 있는 집 순서대로 방문해야 하기 때문에 스택의 top 부분이 몇번째 집인지를 알아야 해서 스택의 사이즈로 구한다.
      answer += 2 * (max(d.size(), p.size()));

      // 사용가능한 배송, 수거 카운트
      int deli_count = cap;
      int pic_count = cap;

      // 배송부터 시작. 배송할 곳이 없거나 배송가능 한도가 0이면 나가기.
      while (!d.empty() && deli_count >= 0) {

        // 배송한도가 배송량보다 많으면 해당 집에 다 배송하고 스택에서 빼버리기.
        if (d.top() <= deli_count) {
          deli_count -= d.top();
          d.pop();
          // 배송량이 더 많으면 다음에 또 와아햐기 때문에 pop하지 않음.
        } else {
          d.top() -= deli_count;
          break;
        }
      }

      // 수거 시작. 배송과 동일하게 반복.
      while (!p.empty() && pic_count >= 0) {
        if (p.top() <= pic_count) {
          pic_count -= p.top();
          p.pop();
        } else {
          p.top() -= pic_count;
          break;
        }
      }
    }
    return answer;
}

int main() {
  cout << solution(cap, n, deliveries, pickups);
}