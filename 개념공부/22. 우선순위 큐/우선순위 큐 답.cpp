#include <bits/stdc++.h>
using namespace std;

int heap[100005]; // 우선순위 큐를 구현할 배열
int sz = 0; // heap에 들어있는 원소의 수

void push(int x){
  heap[++sz] = x;
  int idx = sz;

  while(idx != 1) {
    int parent = idx / 2;
    if (heap[parent] <= heap[idx]) break;
    swap(heap[parent], heap[idx]);
    idx = parent;
  }
}

int top(){
  return heap[1];
}

void pop(){
  heap[1] = heap[sz--];
  int idx = 1;

  while ( 2 * idx <= sz) { // idx의 왼쪽 자식이 마지막 노드인 경우 포함해서 돌린다.
    int lc = 2 * idx, rc = 2 * idx + 1; // 왼쪽 자식, 오른쪽 자식
    int min_child = lc; // 일단 왼쪽 자식을 담아놓는다.
    
    if (rc <= sz && heap[rc] < heap[lc]) { // 오른쪽 자식이 있고, 왼쪽 자식이 오른쪽 자식보다 더 크면 오른쪽 자식이 작은 값이다.
      min_child = rc;
    }
    if (heap[idx] < heap[min_child]) break; // 이렇게 구한 min값이랑 idx랑 비교해서 min이 더 크면 중단.
    swap(heap[idx], heap[min_child]); // min과 같거나 작은 경우 스왑
    idx = min_child; // idx값을 min값으로 갱신해줌.
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