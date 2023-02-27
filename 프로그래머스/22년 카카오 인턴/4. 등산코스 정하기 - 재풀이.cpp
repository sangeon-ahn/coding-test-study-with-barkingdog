#include <bits/stdc++.h>
using namespace std;
int MAX_NUM = 0x3f3f3f3f;
 /*
        pq를 이용해서 해당 노드로 가는데 들었던 간선 비용 중 가장 큰 값으로 계속 갱신해나간다. 이후 summit만 따로 확인해서 간선 비용이 가장 작은 summit을 답으로 한다.
    */
   
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> check_gate(n + 1, 0);
    vector<int> check_summit(n + 1, 0);
    
    for (int summit : summits) {
        check_summit[summit] = 1;
    }
    
    for (int gate : gates) {
        check_gate[gate] = 1;
    }
    
    vector<vector<pair<int, int>>> graph(n + 1);
    
    for (auto path : paths) {
        int u = path[0], v = path[1], w = path[2];
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    
    sort(summits.begin(), summits.end());
    
    priority_queue<pair<int, int>> pq;
    vector<int> dist(n + 1, MAX_NUM);
    
    for (int gate : gates) {
        dist[gate] = 0;
        pq.emplace(-dist[gate], gate);
    }
    
    while (!pq.empty()) {
        auto [d, pos] = pq.top(); pq.pop();
        
        // 해당 경로 비용이 더 나가면 패스
        if (dist[pos] < -d) continue;
        
        // 산봉우리 도착이면 패스
        if (check_summit[pos]) continue;
        
        
        for (auto [next, W] : graph[pos]) {
            // 게이트면 패스.
            if (check_gate[next]) continue;
            
            // 값이 더 작으면 거리 갱신하고 넣기.
            if (dist[next] > max(-d, W)) {
                dist[next] = max(-d, W);
                pq.emplace(-dist[next], next);
            }
        }
    }
    
    vector<int> answer(2, INT_MAX);
    for (int i = 0; i < summits.size(); i++) {
        if (answer[1] > dist[summits[i]]) { // summits을 오름차순 정렬했기 때문에 answer[1] == dist[summits[i]]인 경우를 확인 안해줘도 됨.
            answer[0] = summits[i];
            answer[1] = dist[summits[i]];
        }
    }
    
    return answer;
}