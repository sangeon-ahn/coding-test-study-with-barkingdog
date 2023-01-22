#include <iostream>
#include <deque>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int N, M;
  cin >> N >> M;
  deque<int> D;
  int ans = 0;

  for (int i = 1; i <= M; i++) {
    D.push_back(i);
  }

  while (M--) {
    int A;
    cin >> A;
    
    int idx = find(D.begin(), D.end(), A) - D.begin();

    while (A != D.front()) {
      if (idx < D.size() - idx) {
        D.push_back(D.front());
        D.pop_front();
      } else {
        D.push_front(D.back());
        D.pop_back();
      }
      ans++;
    }
    D.pop_front();
  }
  cout << ans;
}

// find 함수를 몰라서 못풀었다.
// 시계 방향 vs 시계 반대방향 중 어느게 더 조금 도는지를 알려면 find함수로 타겟 위치의 인덱스를
// 알아낸 후 인덱스 0에서 해당 값까지의 거리 vs deque 크기 - 0에서 해당 값까지의 거리 비교