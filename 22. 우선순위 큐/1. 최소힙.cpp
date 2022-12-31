// #include <bits/stdc++.h>
// using namespace std;

// int heap[100005]; // 우선순위 큐를 구현할 배열
// int sz = 0; // heap에 들어있는 원소의 수
// int N;
// int arr[100010];

// void push(int x){
//   heap[++sz] = x;
//   int idx = sz;

//   while (idx != 1 && heap[idx] < heap[idx / 2]) {
//     int temp = heap[idx / 2];
//     heap[idx / 2] = heap[idx];
//     heap[idx] = temp;
//     idx /= 2;
//   }
// }

// int top(){
//   if (sz == 0) {
//     return 0;
//   }
//   return heap[1];
// }

// void pop(){
//   if (sz == 0) return;
//   heap[1] = heap[sz];
//   sz--;

//   int idx = 1;
//   // 지금 맨 위 노드를 마지막 노드로 바꾸고 밑으로 내려주는 코드 작성하는 중인데 자식 노드가 없는데 인덱스 접근을 하면 에러가 나서
//   // 이걸 어떻게 처리해야 할지 고민중이다.
//   // 자식 노드가 있을 때까지만 하면 되겠다.
//   while (idx <= sz) {
//     // idx의 자식이 2개 있다면
//     if (2 * idx + 1 <= sz) {
//       if (heap[2 * idx] < heap[2 * idx + 1]) { // 오른쪽 자식이 더 크면 왼쪽 자식과 비교 후에 바꿀지 결정한다.
//         if (heap[idx] > heap[2 * idx]) {
//           int temp = heap[2 * idx];
//           heap[2 * idx] = heap[idx];
//           heap[idx] = temp;
//           idx = 2 * idx;
//         }
//       } else {
//         if (heap[idx] > heap[2 * idx + 1]) {
//           int temp = heap[2 * idx + 1];
//           heap[2 * idx + 1] = heap[idx];
//           heap[idx] = temp;
//           idx = 2 * idx + 1;
//         }
//       }
//     }

//     // idx의 자식이 1개 있다면
//     else if (2 * idx == sz) {
//       if (heap[idx] > heap[2 * idx]) {
//         int temp = heap[2 * idx];
//         heap[2 * idx] = heap[idx];
//         heap[idx] = temp;
//         idx = 2 * idx;
//       }
//     }

//     else { // idx 자식이 0개 있다면
//       break;
//     }
//   }
// }

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
int N;
int arr[100010];
int main(){
  // 입력 시간 최소화
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  // N번 입력 받는다.
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < N; i++) {
    if (arr[i] == 0) { // x == 0이면,
      cout << top() << '\n'; // 가장 작은 값을 출력하고,
      pop(); // 제거한다.
    }
    else { // x != 0의 경우,
      push(arr[i]); // x를 힙에 넣는다.
    }
  }
}