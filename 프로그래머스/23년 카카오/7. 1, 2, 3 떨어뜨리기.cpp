#include <bits/stdc++.h>

using namespace std;
vector<int> graph[102];
vector<int> DP[101][101];
int idx[101];
int DFS(int node) {
    if (graph[node].empty()) return node;
    
    int next = graph[node][idx[node]];
    idx[node] = (idx[node] + 1) % graph[node].size();
    
    return DFS(next);
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer;

    // 그래프에 오름차순으로 넣기 위해 정렬
    sort(edges.begin(), edges.end());
    
    // 그래프 만들기
    for (vector<int> edge: edges) {
        graph[edge[0]].push_back(edge[1]);
    }

    DP[0][0] = {0};
    DP[1][1] = {1};
    DP[1][2] = {2};
    DP[1][3] = {3};
    
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            for (int k = 1; k <= 3; k++) {
                // 이전 dp에 k를 더한 값을 사용
                if (j >= k && !DP[i - 1][j - k].empty()) {
                    vector<int> temp;
                    
                    if (i != 1) temp = DP[i - 1][j - k];
                    temp.push_back(k);
                    
                    if (DP[i][j].empty() || temp < DP[i][j]) {
                      DP[i][j] = temp;  
                    }
                }
            }
        }
    }
    bool flag = true;
    int count[102] = {0};
    int position[102] = {0, };
    vector<int> order;
    
    do {
        // 해당하는 dp가 있을 때까지 DFS를 거쳐서 삽입할 숫자 구해서 처리
        flag = true;
        int node = DFS(1);
        order.push_back(node);
        count[node]++;
        
        for (int i = 1; i <= target.size(); i++) {
            // target[i] : 리프노드 i + 1에 떨어진 숫자의 합
            /// 떨어진 횟수보다 숫자가 작으면 불가
            if (count[i] > target[i - 1]) return {-1};
            
            if (DP[count[i]][target[i - 1]].empty()) flag = false; // 한번이라도 비어있는 DP가 나온다면 다시 do 수행 => 모두 DP값이 있으면 빠져나감.
        }
        
    } while(!flag);
    
    for (int v : order) {
        answer.push_back(DP[count[v]][target[v - 1]][position[v]++]);
    }
    
    
    return answer;
}