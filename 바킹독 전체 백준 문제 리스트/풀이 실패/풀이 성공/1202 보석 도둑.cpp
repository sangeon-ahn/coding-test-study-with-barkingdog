#include <bits/stdc++.h>
using namespace std;
// 시간 초과(bags를 벡터로 구현했을 때)

int N, K;
pair<int, int> jewels[300030];
// vector<int> bags;
multiset<int> bags;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;

  // 보석의 정보를 받는다.
  for (int i = 0; i < N; i++) {
    // 무게, 가치 정보를 받아 저장한다.
    // 1. 벡터에 저장. 2. 배열에 저장.
    int m, v;
    cin >> m >> v;
    jewels[i] = {-1 * v, m};
  }

  for (int i = 0; i < K; i++) {
    // 가방 무게를 받아 저장한다.
    // 가방을 빼내야 하기 때문에 벡터에 저장.
    int m;
    cin >> m;
    // bags.push_back(m);
    bags.insert(m);
  }
  // 가치 순서대로 보석을 정렬한다.
  // compare 함수 써서, 첫번째 자리에서 오름차순하고, 같은 경우 두번째 자리에서 오름차순한다.
  sort(jewels, jewels + N);
  // 같은 가치인 경우 무게가 적게 나가는 순서대로 정렬한다.
  
  // 가방을 무게가 적게 나가는 순서대로 정렬한다.
  sort(bags.begin(), bags.end());
  // 첫번째 보석부터 가방들에 lower_bound를 적용해서 자기가 들어갈 수 있는 가방 중 가장 작은 가방을 골라 빼낸다. 그후 보석 가치를 답에 더한다.
  long long ans = 0;

  for (int i = 0; i < N; i++) {
    // 기존 코드 주석처리.
    // auto it = lower_bound(bags.begin(), bags.end(), jewels[i].second);
    
    // vector 대신 multiset 사용
    auto it = bags.lower_bound(jewels[i].second);
    if (it != bags.end()) {
      ans += -1 * jewels[i].first;
      bags.erase(it);
    }
  }
  // 답을 출력한다.
  cout << ans;
}