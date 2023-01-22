#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1<<31-1][2]; // arr[x][0]: 음수 개수, arr[x][1]: 양수 개수

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0 ; i < N; i++) {
    int x;
    cin >> x;

    // 음수일 경우.
    if (x < 0) {
      arr[abs(x)][0]++; // 0번째 인덱스에 +1 해준다.
      pq.push(abs(x)); // 절댓값을 취하고 최소힙에 넣는다.
    }
    else if (x > 0) { // 양수일 경우.
      arr[x][1]++; // 1번째 인덱스에 +1 해준다.
      pq.push(x); // 그냥 최소힙에 넣는다.
    }
    else { // x == 0일 경우,
      if (!pq.empty()) { // 비어있지 않다면,
        int top = pq.top(); // 절댓값이 가장 작은 값을 받는다.
        pq.pop(); // 그리고 그 값을 큐에서 제거한다.
        if (arr[top][0] > 0) { // 만약 이 절댓값이 음수가 있다면,
          cout << -1 * top << '\n'; // 그 음수를 출력한다.
          arr[top][0]--; // 그리고 개수를 줄인다.
        } else { // 음수가 없다면 양수다.
          cout << top << '\n'; // 일단 출력한다.
          arr[top][1]--; // 그리고 개수를 줄인다.
        }
      } else cout << "0\n"; // 비어있는 경우 0 출력.
    }
  }
}