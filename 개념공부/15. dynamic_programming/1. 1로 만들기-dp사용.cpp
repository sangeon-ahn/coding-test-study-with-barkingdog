#include <iostream>
using namespace std;

int N;
int d[1000001];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  // d[i] = k, 숫자 i가 1이 되는데 걸리는 최소 횟수
  // d[12] = d[4] + 1 (이유: 12 / 3 = 4이고 이후에는 d[4]값을 더하면되기 때문에 d[12] = d[4] + 1)
  d[1] = 0;

  for (int i = 2; i <= N; i++) {
    d[i] = d[i-1] + 1;

    if (i % 3 == 0) {
      d[i] = min(d[i], d[i/3] + 1);
    }
    if (i % 2 == 0) {
      d[i] = min(d[i], d[i/2] + 1);
    }
  }
  cout << d[N];
}

// int d[1000005];
// int n;

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cin >> n;
//   d[1] = 0;
//   for(int i = 2; i <= n; i++){
//     d[i] = d[i-1]+1;
//     if(i%2 == 0) d[i] = min(d[i],d[i/2]+1);
//     if(i%3 == 0) d[i] = min(d[i],d[i/3]+1);
//   }
//   cout << d[n];
// }