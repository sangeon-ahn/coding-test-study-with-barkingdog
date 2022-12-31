#include <bits/stdc++.h>
using namespace std;

class cmp {
  public:
    bool operator() (int a, int b) { // 무조건 메소드 이름을 operator로 해야한다.
      if (abs(a) != abs(b)) return abs(a) > abs(b); // abs(a) < abs(b)이면 false다. false면 a와b의 순서를 바꾸지 않는다.
      return a > 0 && b < 0; // 절댓값이 같으면 한쪽은 +, 한쪽은 -다. 여기서는 a가-, b가+면 false다. a:-, b:+이면 순서를 바꾸지 않는다.
    }
};

int N;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  priority_queue<int, vector<int>, cmp> pq;
  
  for (int i = 0 ; i < N; i++) {
    int x;
    cin >> x;

    if (x == 0) { //x == 0이면
      if (pq.empty()) cout << "0\n"; // 비어있으면 0 출력.
      else { // 차있는 경우 맨위 출력.
        cout << pq.top() << '\n';
        pq.pop(); // 제거한다.
      }
    }
    else { // x != 0이면
      pq.push(x); // 힙에 x 넣는다.
    }
  }
}