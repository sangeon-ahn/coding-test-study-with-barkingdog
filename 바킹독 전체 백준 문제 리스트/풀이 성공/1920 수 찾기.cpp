#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[100010];
int B[100010];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  sort(A, A + N);

  cin >> M;

  for (int i = 0; i < M; i++) {
    int a;
    cin >> a;
    
    bool p = binary_search(A, A + N, a);

    if (p) cout << "1\n";
    else cout << "0\n";
  }
}
