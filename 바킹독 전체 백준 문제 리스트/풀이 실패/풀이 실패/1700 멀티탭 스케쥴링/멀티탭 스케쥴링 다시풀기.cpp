#include <bits/stdc++.h>
using namespace std;


int N, K;
int arr[105];
bool power[105];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;

  for (int i = 1; i <= K; i++) {
    cin >> arr[i];
  }

  int answer = 0;

  // 현재 멀티탭에 꽂힌 기기 개수.
  int count = 0;

  // 꽂는 순서 i.
  for (int i = 1; i <= K; i++) {
    int cur = arr[i];

    // 이미 같은게 꽂혀 있으면 패스.
    if (power[cur]) continue;

    // 아직 자리가 남았으면 꼽기.
    if (count < N) {
      power[cur] = true;
      count++;
    }

    // 자리가 없는 경우에는 하나를 빼야하는데 이때 기준은 이미 꽂혀 있는 기기 중에서 가장 늦게 다시 꽂아야 하는 기기를 뺀다.
    else {
      vector<pair<int, int>> v;

      for (int x = 1; x <= K; x++) {
        if (!power[x]) continue;

        bool vis = false;

        for (int y = i + 1; y <= K; y++) {
          if (arr[y] == x) {
            v.push_back({y, x});
            vis = true;
            break;
          }
        }

        if (!vis) v.push_back({K + 1, x});
      }
      sort(v.begin(), v.end(), greater<pair<int, int>>());

      int target = v[0].second;
      power[target] = false;
      power[cur] = true;
      answer++;
    }
  }

  cout << answer;
}