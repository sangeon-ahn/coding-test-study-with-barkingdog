#include <bits/stdc++.h>
using namespace std;

const int NMX = 10002;

int mx;
int sc[NMX];
vector<int> adj[NMX];
bool vis[NMX];

void trav(int cur) {
  // 현재 정점 방문체크.
  vis[cur] = 1;

  // 지금 u -> v 이렇게 간선이 저장되어 있는데 실제로는 v에서 u로 가는거라서 결국 sc[cur]++를 한다는 건 cur 정점을 감염시키면 이전 정점도 감염시킬 수 있다는게 되므로 sc[cur]++ 해주면 된다.
  // 생각하기 어려운 부분.
  sc[cur]++;

  // 최대값 갱신.
  mx = max(mx, sc[cur]);

  // 자식정점 돌기.
  for(int nxt : adj[cur]) {
    if(vis[nxt]) continue;
    trav(nxt);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // 간선 입력받기.
  int n, m; cin >> n >> m;
  while(m--) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  // sc를 0으로 초기화
  fill(sc, sc + NMX, 0);

  // 모든 정점에 대해서 trav 수행.
  for(int i = 1; i <= n; i++) {
    fill(vis, vis + NMX, 0);
    trav(i);
  }

  // 위에서 mx값 구한걸 가지고 mx값이랑 같으면 i 출력.
  for(int i = 1; i <= n; i++)
    if(sc[i] == mx) cout << i << ' ';
}