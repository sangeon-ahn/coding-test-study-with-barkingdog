#include <bits/stdc++.h>
using namespace std;
// 소요시간: 13분
int N, K;
int arr[100001];
/*
  큐를 만들어서 이 안에 수빈이가 -1, +1, *2를 움직인 경우를 넣는다.
  큐에서 빼낸 후, arr에서 해당 위치가 이전에 왔던 곳이라면 패스하고, 없던 곳이면
  걸린 시간을 할당한 후에 다시 -1, +1, *2를 하고 큐에 넣는다.
  큐에서 빼냈을 때 위치가 만약 동생의 위치와 같다면, 해당 위치까지 도달하는데 걸린 시간을 출력한다.
*/
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;

  queue<pair<int, int>> q;
  q.push({N, 0});

  while (!q.empty()) {
    auto p = q.front(); q.pop();

    if (K == p.first) {
      cout << p.second;
      return 0;
    }

    if (p.first <= 100000 && arr[p.first] == 0) {
      arr[p.first] = p.second + 1;
      q.push({p.first + 1, p.second + 1});
      q.push({p.first - 1, p.second + 1});
      q.push({p.first * 2, p.second + 1});
    }
  }
}