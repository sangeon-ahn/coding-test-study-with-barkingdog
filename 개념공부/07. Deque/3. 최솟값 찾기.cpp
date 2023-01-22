#include <iostream>
#include <deque>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, L;
  cin >> N >> L;
  deque<int> DQ;

  for (int i = 1; i <= N; i++) {
    int I, A;
    I = i - L + 1;
    cin >> A;
    DQ.push_back(A);
    if (I > 0) {

    }
  }
}

// 바킹독 풀이

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, L;
  deque<pair<int, int>> dq;
  cin >> N >> L;

  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;

    // 넣을 수보다 큰 수 있으면 다 지워버림, 작은수만 있음.
    while (!dq.empty() && dq.back().second >= num) {
      dq.pop_back();
    }

    dq.push_back({i, num});
    
    // 범위 벗어나는 숫자 삭제.
    if (dq.front().first <= i - L) {
      dq.pop_front();
    }

    cout << dq.front().second << ' ';
  }

  return 0;
}