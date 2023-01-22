#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>> N;

  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<>> minHeap;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;

    int maxHeapSize = maxHeap.size();
    int minHeapSize = minHeap.size();

    // 맥스 힙과 민 힙 크기가 같으면 맥스힙에 집어넣기.
    if (maxHeapSize == minHeapSize) {
      maxHeap.push(a);
    }

    // 맥스 힙 사이즈가 더 크면 민힙에 집어넣기.
    else if (maxHeapSize > minHeapSize) {
      minHeap.push(a);
    }

    // 맥스힙과 민힙의 top을 비교해서 맥스힙의 top이 더 크면 둘이 스위칭 하기.
    if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
      minHeap.push(maxHeap.top());
      maxHeap.pop();

      maxHeap.push(minHeap.top());
      minHeap.pop();
    }

    cout << maxHeap.top() << '\n';
  }
}