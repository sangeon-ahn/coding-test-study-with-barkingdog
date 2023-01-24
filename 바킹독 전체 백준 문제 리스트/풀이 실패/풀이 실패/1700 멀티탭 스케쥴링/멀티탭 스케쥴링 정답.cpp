#include <bits/stdc++.h>
using namespace std;

int a[105]; //  전기용품의 사용 순서.
bool power[105]; // 해당 전기용품이 멀티탭에 꽂혀 있는지


int N, K;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;

  for (int i = 1; i <= K; i++) {
    cin >> a[i];
  }

  int answer = 0;
  int count = 0; // 멀티탭에 꽂혀 있는 전기용품의 개수.

  for (int i = 1; i <= K; i++) {
    int cur = a[i];

    if (power[cur]) continue; // 이미 꽂혀 있으면 넘어감.

    // 멀티탭에 자리가 남으면 그냥 꽂음
    if (count < N) {
      power[cur] = true;
      count++;
    }
    
    // 자리가 없는 경우.
    else {
      // 멀티탭에 꽂혀 있는 전기 용품 중, a에서 앞으로 가장 빨리 나올 위치를 이름과 함께 저장함.
      // (위치, 이름)
      vector<pair<int, int>> v;
      
      // x: 기기의 이름. 기기의 이름은 1~K
      for (int x = 1; x <= K; x++) {

        // 멀티탭에 안꽂혀있는 기기면 패스.
        if (!power[x]) continue;

        bool vis = false;

        // y: 콘센트에 꽃는 기기의 순서. i+1번째 순서부터 확인.
        for (int y = i + 1; y <= K; y++) {
          if (a[y] == x) {

            // y번째에 콘센트 연결할 x를 v에 넣기.
            v.push_back({y, x});
            vis = true;
            break;
          }
        }

        // 해당 기기가 이후에 사용되지 않는다면, (K + 1, x) 로 처리.
        // 왜 ? 이후에 사용되지 않는 기기는 교체 최우선 등급이기 때문에 내림차순 했을 때 맨 처음에 있게 하기 위함.
        if (!vis) v.push_back({K + 1, x});
      }
      // greater<자료형>() -> 내림차순 정렬.
      sort(v.begin(), v.end(), greater<pair<int, int>>());
      
      // 가장 늦게 사용할 전기용품을 뽑고 cur을 꽂으면 됨.
      int target = v[0].second;
      power[target] = false; answer++;
      power[cur] = true;
    }
  }

  cout << answer;
}