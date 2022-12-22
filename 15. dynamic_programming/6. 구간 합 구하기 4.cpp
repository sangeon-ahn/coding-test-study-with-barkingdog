#include <iostream>
using namespace std;

// 첫번째 답 시간초과
// int N, M;
// int arr[100010];

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cin >> N >> M;

//   for (int i = 0; i < N; i++) {
//     cin >> arr[i];
//   }

//   for (int i = 0; i < M; i++) {
//     int a, b;
//     int sum = 0;

//     cin >> a >> b;
    
//     for (int j = a-1; j < b; j++) {
//       sum += arr[j];
//     }
//     cout << sum << '\n';
//   }
// }

// 두번째 시도
// 안될거 알아서 중단, O(MN) 시간복잡도라 10만*10만 = 100억, 100초 소요 > 1초
// int N, M;

// int num[100010];
// int arr[100010][2];

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   cin >> N >> M;

//   for (int i = 0 ; i < N; i++) {
//     cin >> num[i];
//   }

//   for (int i = 0; i < M; i++) {
//     cin >> arr[i][0] >> arr[i][1];
//   }

//   for (int i = 0; i < N; i++) {
//     for (int j = 0; j < M; j++) {
      
//     }
//   }
// }

// 바킹독 풀이: prefix sum 기법 필요
// D[i] = A[1] + A[2] + ... + A[i]
// D[i] = D[i-1] + A[i]

// i~j = A[1] + A[2] = D[j] - D[i] + A[i]
// if i = 2, j = 5; D[5] - D[2] = 1, 2, 3, 4, 5 - 1, 2 = 3, 4, 5 + A[2] 더해줘야 하니까
// D[j] - D[i-1] 이렇게 한다.

int N, M;
int D[100010];
int A[100010];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  D[0] = 0;

  for (int i = 1; i <= N; i++) {
    D[i] = D[i-1] + A[i];
  }

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;

    cout << D[b] - D[a-1] << '\n';
  }
}
