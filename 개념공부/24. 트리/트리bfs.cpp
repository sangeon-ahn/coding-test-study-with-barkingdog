#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10]; // 트리.
int parent[10];
int depth[10];
int main() {
  queue<int> q; // bfs할 때 필요한 큐.
  q.push(1); // 트리의 루트정점을 넣고 시작.

  while (!q.empty()) { // 빌때까지.
    int cur = q.front(); // 정점 빼낸다음.
    q.pop();

    cout << cur << ' ';
    
    for (int next: graph[cur]) { // 해당 정점과 연결되어 있는 정점을 순회하기.
      if (parent[cur] == next) continue; // 근데 연결된 정점이 부모면 패스. 루트노드의 부모 노드는 0이다.
      q.push(next); // 아니면 큐에 이 정점 넣고.
      parent[next] = cur; // next 정점의 부모는 cur임을 저장.
      depth[next] = depth[cur] + 1; // 이렇게 자식의 depth를 계산할 수 있음.
    }
  }

}
