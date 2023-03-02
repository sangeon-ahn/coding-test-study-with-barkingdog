#include <bits/stdc++.h>
using namespace std;
/*
    답을 통해 배운 점
    1. summit인지 체크할 때 summits를 for문 돌리는게 아니라 벡터 자료구조를 사용해서 O(1) 만에 확인할 수 있다.
    
    2. emplace_back, emplace를 사용하면 pair나 그밖의 다른 타입으로 넣어야 할 경우 값 복사가 일어나지 않아서 더 빠르게 삽입 가능하다.

    3. 벡터는 생성시 크기를 지정해주는게 좋다.

    4. MAX값을 생성하려면 1000000 같은 숫자가 아니라 0x3f3f3f3f나 INT_MAX를 사용하면 된다.

    5. 다익스트라 알고리즘을 pq를 이용해서 구할 수 있다.
*/
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> check_gate(n + 1);
    vector<int> check_summit(n + 1);

    for (int gate : gates) check_gate[gate] = 1;
    for (int summit: summits) check_summit[summit] = 1;

    vector<vector<pair<int, int>>> graph(n + 1);

    for (vector<int> path : paths) {
        int u = path[0], v = path[1], w = path[2];
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    sort(summits.begin(), summits.end());

    priority_queue<pair<int, int>> pq;
    vector<int> dist(n + 1, 0x3f3f3f3f); // intensity 저장소

    for (int gate : gates) {
        dist[gate] = 0; // 모든 게이트에 대해 intensity = 0으로 초기설정 하고 최대힙을 최소힙으로 만들어주기 위해 입력값 첫항에 - 붙이고 넣기.
        pq.emplace(-dist[gate], gate); // 게이트 거리와 게이트
    }

    while (!pq.empty()) {
        auto [d, cur] = pq.top(); pq.pop(); // 매 순간 가장 intensity가 작은걸 꺼낸다. 처음에는 모든 값이 (0, gate)이므로, gate가 가장 큰것부터 나온다.

        if (dist[cur] < -d) continue; // 꺼낸 d가 이미 저장된, 현재 위치에 대한 intensity보다 크면 더 볼 필요도 없으므로 바로 패스한다. => 가장 작은 intensity를 고르기 위해.
        if (check_summit[cur]) continue; // 현재 위치가 봉우리면 끝났으므로 패스한다.

        for (auto [next, W] : graph[cur]) {
            if (dist[next] > max(W, -d)) { // 다음 위치에 대한 기존의 intensity 값보다 max(W, -d)가 더 작으면 이전걸 버리고 max(W, -d)로 교체한다.
                dist[next] = max(W, -d);
                pq.emplace(-dist[next], next);
            }
        }
    }
    
    // pq가 끝나면 노드에 대한 도달하는데 필요한 최대 intensity가 결정된다.
    vector<int> answer(2, INT_MAX);
    for (int summit : summits) {
        if (answer[1] > dist[summit]) {
            answer[1] = dist[summit];
            answer[0] = summit;
        }
    }

    return answer;
}