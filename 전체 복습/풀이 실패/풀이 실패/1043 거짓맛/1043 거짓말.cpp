#include <bits/stdc++.h>
using namespace std;

int N, M;
int P;
vector<int> party[100];
bool isTrue[100];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  cin >> P;

  fill(isTrue, isTrue + N + 1, true);

  for (int i = 0; i < P; i++) {
    int x;
    cin >> x;
    isTrue[x] = false;
  }

  for (int i = 0; i < M; i++) {
    int n;
    cin >> n;

    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      party[i].push_back(a);
    }
  }

  for (int i = 0; i < M; i++) {
    // 파티에 진실을 알고 있는 사람이 있으면(isTrue가 false인 사람이 있으면) 파티의 모든 사람의 isTrue값을 false로 바꾼다.
    bool isFalse = false;
    
    for (int j = 0; j < party[i].size(); j++) {
      if (!isTrue[party[i][j]]) {
        isFalse = true;
        break;
      }
    }
    
    if (!isFalse) continue;

    for (int j = 0; j < party[i].size(); j++) {
      isTrue[party[i][j]] = false;
    }
  }

  int ans = 0;

  for (int i = 0; i < M; i++) {
    bool isFalse = false;

    for (int j = 0; j < party[i].size(); j++) {
      if (!isTrue[party[i][j]]) {
        isFalse = true;
        break;
      }
    }

    if (isFalse) continue;
    ans++;
  }
  cout << ans;
}