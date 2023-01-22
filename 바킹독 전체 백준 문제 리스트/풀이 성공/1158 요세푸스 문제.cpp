#include <bits/stdc++.h>
using namespace std;
// 13분 30초
int N, K;
vector<int> ans;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;
  
  // 큐를 이용한 풀이.
  queue<int> q;

  // q에 1부터 N까지의 자연수를 넣음.
  for (int i = 1; i <= N; i++) {
    q.push(i);
  }

  // 큐가 빌 때까지 돌기.
  while (!q.empty()) {
    // K - 1번 빼내고 다시 넣기
    int p;
    for (int i = 0; i < K - 1; i++) {
      p = q.front(); q.pop();
      q.push(p);
    }

    // K 번째에서는 빼내고 정답 배열에 넣는다.
    p = q.front(); q.pop();
    ans.push_back(p);
  }

  // 큐에서 다 나왔고 이제 출력한다.
  cout << '<';
  for (int i = 0; i < ans.size() - 1; i++) {
    cout << ans[i] << ", ";
  }
  cout << ans[ans.size() - 1] << '>';
}