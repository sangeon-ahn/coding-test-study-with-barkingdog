#include <bits/stdc++.h>
using namespace std;
 /*
  우선, 진실을 아는 사람이 있는 파티에서 거짓말을 하는 것 -> 안됨.
  진실을 아는 사람이 없는 방에서 거짓말을 한 후, 진실을 아는 사람이 있는 파티에서 진실을 말하는 것 -> 안됨
  => 진실을 아는 사람이 있는 파티에 진실을 모르는 사람의 리스트를 뽑고,
  진실을 아는 사람 + 아는 사람 방에 있는 모르는사람 리스트 만들어서, 전체 파티 순회하면서 있나 확인.
 */
int N, M, K;
vector<int> know;
vector<vector<int>> parties;
int ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> K;

  // 진실을 아는 사람을 know에 저장.
  if (K != 0) {
    for (int i = 0; i < K; i++) {
      int a;
      cin >> a;
      know.push_back(a);
    }
  }
  
  // 파티 정보 parties에 저장.
  for (int i = 0; i < M; i++) {
    // 파티에 참석하는 사람 수 heads.
    int heads;
    cin >> heads;

    vector<int> temp;

    // 파티에 참석하는 사람 저장.
    for (int i = 0; i < heads; i++) {
      int p;
      cin >> p;
      temp.push_back(p);
    }

    parties.push_back(temp);
  }

  for 
}