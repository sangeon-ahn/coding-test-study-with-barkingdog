#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, K;
  vector<int> V;
  cin >> N >> K;
  list<int> L = {};
  for (int i = 0; i < N; i++) L.push_back(i+1);
  auto t = L.begin();
  // for (int c: L) cout << c;

  while (!L.empty()) {
    for (int i = 0; i < K - 1; i++) {
      t++;
      if (t == L.end()) t = L.begin();
    }
    V.push_back(*t);
    t = L.erase(t);
    if (t == L.end()) t = L.begin();
  }

  // for (auto n: V) {
  //   if (n == V.front()) cout << '<' << n << ", ";
  //   else if (n == V.back()) cout << '>';
  //   else cout << n << ", ";
  // }

  for (int i = 0; i < N; i++) {
    if (i == 0) cout << "<" << V[i] << ", ";
    else if (i == N - 1) cout << V[i] << " >";
    else cout << V[i] << ", ";
  }
}

// 1. 야매 링크드리스트 이용
  // 원형 링크드리스트 만들어서 풀기
int N, K, len = 0;

// 리스트에서 이전 노드/다음 노드를 가리키는 변수
int pre[5001];
int nxt[5001];
//요세푸스 순열을 저장하는 변수
vector<int> v;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;

  // 원형 연결 리스트 생성
  // 맨 처음 노드와 마지막 노드가 서로를 가리키도록 설정
  for (int i = 1; i <= N; i++) {
    pre[i] = i == 1 ? N : i - 1;
    nxt[i] = i == N ? 1 : i + 1;
    ++len;
  }

  int i = 1;
  // 연결 리스트를 순회하며 순열 생성
  for (int cur = 1; len != 0; cur = nxt[cur]) {
    // K 번째일 때 제거
    if (i == K) {
      pre[nxt[cur]] = pre[cur];
      nxt[pre[cur]] = nxt[cur];
      v.push_back(cur);
      i = 1;
    } else ++i;
  }

  // 요세푸스 순열 출력
  cout << "<";
  for (size_t i =0; i < v.size(); ++i) {
    cout << v[i];
    if (i != v.size() - 1) cout << ", ";
  }
  cout << ">";

}
// 2. 큐 이용
  // 큐에 넣고 2번 빼서 다시 넣고 1번 빼서 답에 넣고
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  queue<int> Q;
  for (int i = 1; i <= n; i++) Q.push(i);
  cout << '<';
  while (!Q.empty()) {
    for (int i = 0; i < k - 1; i++) {
      Q.push(Q.front());
      Q.pop();
    }
    cout << Q.front();
    Q.pop();
    if (Q.size()) cout << ", ";
  }
}
// 3. 벡터 이용
  // 다 뺄때까지 2번 빼서 다시 뒤로 넣고 한번 답에 넣고
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> V, ans;
  for (int i = 1; i <= n; i++) {
    V.push_back(i);
  }

  for (int i = 0; ans.size() < n; i++) {
    if (i % k == k - 1) ans.push_back(V[i]);
    else V.push_back(V[i]);
  }

  cout << "<";
  for (int i = 0; i < n; i++) {
    if (i == n - 1) cout << ans[i];
    else cout << ans[i] << ", ";
  }
  cout << ">";
}