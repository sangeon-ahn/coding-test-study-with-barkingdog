#include <iostream>
#include <stack>
using namespace std;


// 일단 while 문에서 n번 수행하고, 내부 while문에서는 이미 스택에 들어간 값 중 가장 최근 top 값이랑 넣을 값이랑 비교해서 넣을 값이 같거나 크면 일단 ans에 두번째 값 더하고 같은 값일 경우 같은값 개수에 더하고 이제 h보다 작은 값은 필요없으므로(다음에 들어갈 값들은 어차피 h에서 막히기 때문) pop시켜준다.
// 그리고 비었거나 h값이 더 작아서 while문을 나오게 되었을 때 비었으면 h값이 가장 큰 값이었으므로 ans++안해도 되는데 안비었으면 h보다 더 큰 값이 있다는거니까 둘이 서로 볼 수 있다는 거니까 또 ans++해준다.
// 마지막으로 h값 push해준다.
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  stack<pair<int, int>> S;
  int ans = 0;

  while (N--) {
    int h;
    cin >> h;
    int cnt = 1;
    while (!S.empty() && S.top().first <= h) {
      ans += S.top().second;
      if (S.top().first == h) cnt += S.top().second;
      S.pop();
    }
    if (!S.empty()) ans++;
    S.push({h, cnt});
  }
  cout << ans;
}