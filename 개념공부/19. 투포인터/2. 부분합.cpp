#include <iostream>
using namespace std;

int N, S;
int arr[100010];
int ans = 0x7fffffff;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> S;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  int en = 0;
  int sum = arr[0];
  bool isEnd = false;
  for (int st = 0; st < N; st++) {
    // 일단 나는 arr[++en]이라고 했었는데 이러면 N-1번째 인덱스일 경우 에러가 난다.
    if (isEnd) break;
    while (en < N && sum < S) {
      en++;
      if (en != N) sum += arr[en];
    }
    // 나는 en == N인 경우 답이 없다고 생각해서 cout << 0; return 0; 했는데 이게 아니라 st가 더 낮은 인덱스였을 경우에 sum < S를 만족했다면 그 ans가 정답일텐데 인덱스 증가시키고 돌렸을 때 답이 없다고 cout << 0 해버리면 안된다. 하지만 en == N이 된 순간 다음 st는 할 필요가 없어지므로 isEnd 플래그를 줘서 최적화를 해줬다.
    if (en == N) {
      isEnd = true;
      break;
    };
    ans = min(ans, en - st + 1);
    sum -= arr[st];
  }
  if (ans == 0x7fffffff) ans = 0;
  cout << ans;
}