#include <iostream>
using namespace std;


int N, K;
int arr[100];


// 내풀이, a를 1씩 증가시켜가면서 동전 몇개까지 되는지 구함.
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  int count = 0;
  int remain = K;

  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }

  for (int i = N; i > 0; i--) {
    if (remain == 0) break;

    if (remain >= arr[i]) {
      int a = 1;
      while (true) {
        if (remain >= arr[i] * a) {
          a++;
        } else break;
      }
      remain -= arr[i] * (a - 1);
      count += (a - 1);
    }
  }

  cout << count;
}

// 바킹독 풀이. 내 풀이방식 말고 몫을 구하는 방식으로 구함.
int n, k;
int a[15];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ans = 0;
  cin >> n >> k;

  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = n-1; i >= 0; i--) {
    ans += k / a[i];
    k %= a[i];
  }
  cout << ans;
}