#include <bits/stdc++.h>
using namespace std;

/*
    graph는 양방향으로 만들기
    현재 노드와 상태를 담는 2차원 배열을 만들기 
    queue에 현재 노드, 양, 늑대, 상태를 가지는 pair를 넣고 돌리기
    큐에서 뽑아서 상태와 1을 비트마스킹 하면서 양과 늑대 수를 센다.
    양이 늑대보다 많으면 최댓값과 비교 후 더 크면 갱신한다.
    양이 늑대와 같거나 적으면 패스.
    
    이제 다음 노드로 가야한다.
    현재 노드에서 다음 노드로 갈 때, 이미 (현재 노드, 새로운 상태)에 진입한 적이 있는 경우,
    큐에 그냥 넣고 돌린다.
    처음 진입이면 상태에 해당 노드에 해당하는 인덱스를 1로 바꾸고 큐에 넣는다.
    
*/

bool visited[17][1<<17];
vector<int> graph[17];

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    
    sort(edges.begin(), edges.end());
    
    for (auto edge : edges) {
        int u = edge[0], v = edge[1];
        
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // 현재 노드, 상태, 양, 늑대
    queue<pair<pair<int, int>, pair<int, int>>> q;
    visited[0][1] = true;
    q.push({{0, 1}, {1, 0}});
    
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int cur_node = p.first.first;
        int status = p.first.second;
        int sheep = p.second.first;
        int wolf = p.second.second;
        
        // 양이 더 많을 때만 정답 갱신
        if (sheep > wolf) answer = max(answer, sheep);
        
        // 늑대가 더 많으면 패스.
        else continue;
        
        // 현재 노드에서 갈 수 있는 곳을 확인.
        for (int i = 0; i < graph[cur_node].size(); i++) {
            // 이미 방문한 노드와 상태라면 패스
            if (visited[graph[cur_node][i]][status | (1 << graph[cur_node][i])]) continue;
            
            // 처음 방문하는 상태다.
            
            // 상태에 노드가 있으면,
            if (status & (1 << graph[cur_node][i])) {
                // 그냥 큐에 넣고 돌리기
                visited[graph[cur_node][i]][status] = true;
                q.push({{graph[cur_node][i], status}, {sheep, wolf}});
            }
            
            // 새로운 상태면 추가하고 돌리기
            else {
                int new_status = status | (1 << graph[cur_node][i]);
                
                // 방문체크.
                visited[graph[cur_node][i]][new_status] = true;
                
                // 양이면 양 + 1
                if (info[graph[cur_node][i]] == 0) {
                    q.push({{graph[cur_node][i], new_status}, {sheep + 1, wolf}});
                }
                
                // 늑대면 늑대 + 1
                else q.push({{graph[cur_node][i], new_status}, {sheep, wolf + 1}});
            }
        }
    }
    
    return answer;
}