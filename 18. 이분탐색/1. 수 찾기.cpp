#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int A[100010];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A, A+N);
  cin >> M;
  
  for (int i = 0; i < M; i++) {
    int a;
    cin >> a;
    
    int left = 0;
    int right = N-1;
    int mid = left - (left - right) / 2;

    bool isHere = false;
    while (left <= right) {
      if (A[mid] == a) {
        cout << 1 << '\n';
        isHere = true;
        break;
      }

      else if (A[mid] > a) {
        right = mid - 1;
        mid = left + (right - left) / 2;
      }

      else if (A[mid] < a) {
        left = mid + 1;
        mid = left + (right - left) / 2;
      }
   }

    if (!isHere) {
      cout << 0 << '\n';
    }
  }
  // binary_search(A, A+N, a);
}

