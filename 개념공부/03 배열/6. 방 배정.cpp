#include <iostream>
#include <cmath>
using namespace std;


int N, K, S, Y, ans;
int arr[7][2];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    cin >> S >> Y;
    arr[Y][S]++;
  }

  for (int i = 1; i < 7; i++) {
    for (int j = 0; j < 2; j++) {
      // cout << (arr[i][j])/k;
      if (arr[i][j] != 0 && arr[i][j] % K != 0) ans += (arr[i][j]/K) + 1;
      else if (arr[i][j] != 0 && arr[i][j] % K == 0) ans += arr[i][j]/K;
    }
  }

  cout << ans;
}

//바킹독 풀이.

int N, K, ans=0;
int s[2][7] = {};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  // 학생 수 저장
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    s[a][b]++;
  }

  // 필요한 방의 개수 계산.
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j < 7; j++) {
      //배정에 필요한 만큼 방의 개수 추가
      ans += s[i][j] / K;
      // 학생이 남을 경우 하나의 방이 더 필요하므로 방의 개수 추가
      if (s[i][j] % K) ++ans;
    }
  }

  cout << ans;
}