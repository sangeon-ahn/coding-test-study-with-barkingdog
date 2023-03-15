#include <bits/stdc++.h>
using namespace std;
/*
  처음에는 다익스트라가 필요할 것 같아서 바킹독 다익스트라를 공부했었는데, 생각해보니 둘이 같이 택시를 타고 내려서 각자 택시타고 가는건데, 이러면 그냥 모든 정점에서 모든 정점으로 가는 최단거리를 구하는게 편해보여서 플로이드를 공부한 후 풀었다.
*/
long long graph[201][201];
int INF = 0x3f3f3f3f;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    long long answer = INF;
    
    for (int i = 1; i <= n; i++) {
        fill(graph[i], graph[i] + n + 1, INF);
        graph[i][i] = 0;
    }
    
    for (int i = 0; i < fares.size(); i++) {
        int u = fares[i][0];
        int v = fares[i][1];
        int w = fares[i][2];
        
        graph[u][v] = w;
        graph[v][u] = w;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (answer > graph[s][i] + graph[i][a] + graph[i][b]) {
            answer = graph[s][i] + graph[i][a] + graph[i][b];
        }
    }
    
    return answer;
}