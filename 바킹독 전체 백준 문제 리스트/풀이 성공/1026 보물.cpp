#include <bits/stdc++.h>
using namespace std;
// 풀이 소요시간: 6분 30초
int N;
int A[100];
int B[100];

// 내림차순을 위한 비교 함수.
bool compare(int a, int b) {
  return a > b;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }

  // A는 오름차순, B는 내림차순한다.
  sort(A, A + N);
  sort(B, B + N, compare);

  int ans = 0;

  // 같은 인덱스 위치끼리 A[i]*B[i]를 ans에 더해준다.
  for (int i = 0; i < N; i++) {
    ans += A[i] * B[i];
  }

  cout << ans;
}