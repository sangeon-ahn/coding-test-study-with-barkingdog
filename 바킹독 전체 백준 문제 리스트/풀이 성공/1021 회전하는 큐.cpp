#include <bits/stdc++.h>
using namespace std;
// 풀이 소요시간: 40분 35초
int N, M;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  deque<int> dq;
  int ans = 0;

  for (int i = 1 ; i <= N; i++) {
    dq.push_back(i);
  }

  for (int i = 0; i < M; i++) {
    int p;
    cin >> p;
    auto it = find(dq.begin(), dq.end(), p);
    // 짝수: 0 1 2 3, 반2
    // 홀수: 0 1 2 3 4, 반2.5

    int move_count = it - dq.begin();
    int inverse_move_count = dq.size() - move_count;

    if (move_count <= dq.size() / 2) {
      ans += move_count;
      for (int i = 0; i < move_count; i++) {
        int temp = dq.front();
        dq.pop_front();
        dq.push_back(temp);
      }
      dq.pop_front();
    } else {
      ans += inverse_move_count;
      for (int i = 0; i < inverse_move_count; i++) {
        int temp = dq.back();
        dq.pop_back();
        dq.push_front(temp);
      }
      dq.pop_front();
    }
  }
  cout << ans;
}