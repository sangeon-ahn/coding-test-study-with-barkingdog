#include <bits/stdc++.h>
// 50% 정답, 나머지 시간초과
using namespace std;
vector<pair<int, int>> graph[50001];
bool vis[50001];

int minIntensity = 10000100;
int minSummit = 100000;
vector<int> Gates;
vector<int> Summits;
bool isGate(int pos) {
    for (int i = 0; i < Gates.size(); i++) {
        if (Gates[i] == pos) return true;
    }
    return false;
}

bool isSummit(int pos) {
    for (int i = 0; i < Summits.size(); i++) {
        if (Summits[i] == pos) return true;
    }
    return false;
}

void dfs(int pos, int maxDist) {
    if (isSummit(pos)) {
        // maxDist가 minIntensity보다 작으면 교체
        if (maxDist < minIntensity) {
            minIntensity = maxDist;
            minSummit = pos;
        }
        // 같은데 summit이 더 작으면 교체
        else if (maxDist == minIntensity && pos < minSummit) {
            minSummit = pos;
        }
        return;
    }
    
    for (auto p : graph[pos]) {
        if (vis[p.first] || isGate(p.first)) continue;
        vis[p.first] = true;
        int newMaxDist = max(maxDist, p.second);
        dfs(p.first, newMaxDist);
        vis[p.first] = false;
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    sort(paths.begin(), paths.end());
    sort(gates.begin(), gates.end());
    sort(summits.begin(), summits.end());
    Gates = gates;
    Summits = summits;
    
    for (vector<int> path: paths) {
        int v1 = path[0];
        int v2 = path[1];
        int dist = path[2];
        
        graph[v1].push_back({v2, dist});
        graph[v2].push_back({v1, dist});
    }
    
    for (int gate : gates) {
        vis[gate] = true;
        for (auto p: graph[gate]) {
            if (isGate(p.first)) continue;
            vis[p.first] = true;
            dfs(p.first, p.second);
            vis[p.first] = false;
        }
        vis[gate] = false;
    }
    
    return {minSummit, minIntensity};
    
    return answer;
}