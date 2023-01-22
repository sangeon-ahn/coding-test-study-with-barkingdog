#include <bits/stdc++.h>
using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, t;
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<>> minHeap;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> t;

    // 사이즈 비교 후 민 힙이 크기가 같거나 더 크면 맥스힙에 넣는다.
    if (maxHeap.size() <= minHeap.size()) {
      maxHeap.push(t);
    }
    // 맥스힙이 더 크기가 크면 민힙에 넣는다.
    else minHeap.push(t);

    /*
      지금 민힙, 맥스힙 크기는 맥스힙이 1개 더 많거나 같은 상황이다.
      
    */

    // 민힙에 숫자가 있고 맥스힙에서 제일 큰 숫자가 민힙에서 제일 작은 숫자보다 크면,
    if (!minHeap.empty() && minHeap.top() < maxHeap.top()) {

      // 맥스힙 제일 큰 숫자를 빼서 민힙에 넣고,
      minHeap.push(maxHeap.top());
      maxHeap.pop();

      // 민힙 제일 작은 숫자를 빼서 맥스힙에 넣는다.
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }

    // 맥스힙에서 가장 큰 숫자를 출력한다.
    cout << maxHeap.top() << '\n';
  }

}