#include <bits/stdc++.h>
using namespace std;

int heap[100005]; // 우선순위 큐를 구현할 배열
int sz = 0; // heap에 들어있는 원소의 수

void push(int x){
  heap[++sz] = x;
  int idx = sz;

  while (idx != 1 && heap[idx] < heap[idx / 2]) {
    int temp = heap[idx / 2];
    heap[idx / 2] = heap[idx];
    heap[idx] = temp;
    idx /= 2;
  }
}

int top(){
  if (sz == 0) {
    return 0;
  }
  return heap[1];
}

void pop(){
  heap[1] = heap[sz];
  sz--;

  int idx = 1;
  // 지금 맨 위 노드를 마지막 노드로 바꾸고 밑으로 내려주는 코드 작성하는 중인데 자식 노드가 없는데 인덱스 접근을 하면 에러가 나서
  // 이걸 어떻게 처리해야 할지 고민중이다.
  // 자식 노드가 있을 때까지만 하면 되겠다.
  while (idx <= sz) {
    // idx의 자식이 2개 있다면
    if (2 * idx + 1 <= sz) {
      if (heap[2 * idx] < heap[2 * idx + 1]) { // 오른쪽 자식이 더 크면 왼쪽 자식과 비교 후에 바꿀지 결정한다.
        if (heap[idx] > heap[2 * idx]) {
          int temp = heap[2 * idx];
          heap[2 * idx] = heap[idx];
          heap[idx] = temp;
          idx = 2 * idx;
        }
      } else {
        if (heap[idx] > heap[2 * idx + 1]) {
          int temp = heap[2 * idx + 1];
          heap[2 * idx + 1] = heap[idx];
          heap[idx] = temp;
          idx = 2 * idx + 1;
        }
      }
    }

    // idx의 자식이 1개 있다면
    else if (2 * idx == sz) {
      if (heap[idx] > heap[2 * idx]) {
        int temp = heap[2 * idx];
        heap[2 * idx] = heap[idx];
        heap[idx] = temp;
        idx = 2 * idx;
      }
    }
    
    else { // idx 자식이 0개 있다면
      break;
    }
  }
}

void test(){
  push(10); push(2); push(5); push(9); // {10, 2, 5, 9}

  cout << top() << '\n'; // 2
  pop(); // {10, 5, 9}
  pop(); // {10, 9}
  cout << top() << '\n'; // 9
  push(5); push(15); // {10, 9, 5, 15}
  cout << top() << '\n'; // 5
  pop(); // {10, 9, 15}
  cout << top() << '\n'; // 9
}

int main(){
  test();
}