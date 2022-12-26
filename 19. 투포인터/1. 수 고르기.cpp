#include <iostream>
#include <algorithm>
using namespace std;

// 정렬: O(NlogN), for문: O(N*logN)
// 하지만 틀림. 예시는 통과.
int N, M;
int A[100010];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  sort(A, A+N);
  int ans = A[N-1] - A[0];
  for (int i = 0; i < N; i++) {
    int start = 0;
    int end = N - 1;

    while (start < end) {
      int mid = (start + end + 1) / 2;
      int temp = abs(A[mid] - A[i]);

      if (temp > M) {
        end = mid - 1;
        ans = min(ans, temp);
      } else if (temp < M) {
        start = mid;
      } else if (temp == M) {
        cout << M;
        return 0;
      }
    }
  }
  cout << ans;
}


// start, end 정하는 법
// 만약 1, 2, 3, 4, 5, 6 이렇게 있다고 치면
/*
  start = 0
  end = 5
  
  while (start <= end) {
    int mid = (start + end + 1) / 2;
    if (A[mid] > 6) { mid == 3 이므로 A[3] = 4
      end = mid - 1;
    } else if (A[mid] < 6) {
      start = mid or mid + 1;
    } else 6 발견
  }
*/

/*
  지금 테스트 케이스 1, 5, 3

*/