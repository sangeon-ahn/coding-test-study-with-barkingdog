#include <bits/stdc++.h>
// 오답
using namespace std;
vector<pair<int, int>> graph[50001];
bool vis[50001];

int minIntensity;
int minSummit;

void dfs(int pos, int maxDist, int summit) {
    if (summit == pos) {
        // maxDist가 minIntensity보다 작으면 교체
        if (maxDist < minIntensity) {
            minIntensity = maxDist;
            minSummit = summit;
        }
        // 같은데 summit이 더 작으면 교체
        else if (maxDist == minIntensity && summit < minSummit) {
            minSummit = summit;
        }
        return;
    }
    
    for (pair<int, int> p : graph[pos]) {
        if (vis[p.first]) continue;
        vis[p.first] = true;
        int newMaxDist = max(maxDist, p.second);
        dfs(p.first, newMaxDist, summit);
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    
    for (vector<int> path: paths) {
        int v1 = path[0];
        int v2 = path[1];
        int dist = path[2];
        
        graph[v1].push_back({v2, dist});
        graph[v2].push_back({v1, dist});
    }
    
    for (int gate : gates) {
        for (int summit : summits) {
            vis[gate] = true;
            for (auto p: graph[gate]) {
                vis[p.first] = true;
                dfs(gate, p.second, summit);
                vis[p.first] = false;
            }
        }
    }
    
    return {minIntensity, minSummit};
    
    return answer;
}