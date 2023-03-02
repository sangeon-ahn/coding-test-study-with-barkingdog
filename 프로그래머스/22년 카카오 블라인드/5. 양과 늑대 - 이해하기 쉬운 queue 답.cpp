#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> V[17];

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    for (int i = 0; i < edges.size(); i++){
        int from = edges[i][0], to = edges[i][1];
        V[from].push_back(to);
        V[to].push_back(from);
    }
    bool visit[1<<17][17];
    queue<pair<pair<int,int>,pair<int,int>>> Q;
    visit[1][0] = true;
    Q.push({{1<<0,0},{1,0}});
    while(!Q.empty()){
        int state = Q.front().first.first;
        int cur = Q.front().first.second;
        int sheep = Q.front().second.first;
        int wolf = Q.front().second.second;
        if (cur == 0){
            answer = max(answer,sheep);
        }
        Q.pop();
        for (int i = 0; i < V[cur].size(); i++){
            int des = V[cur][i];
            int c_state = state | (1 << des);
            if (!info[des]){ // 양
                if (!visit[c_state][des]){
                    visit[c_state][des] = true;
                    if (state & (1 << des)){
                        Q.push({{c_state,des},{sheep,wolf}});
                    }
                    else{
                        Q.push({{c_state,des},{sheep+1,wolf}});
                    }
                }
            }
            else{ // 늑대
                if (!visit[c_state][des]){
                    visit[c_state][des] = true;
                    if (state & (1 << des)){
                        Q.push({{c_state,des},{sheep,wolf}});
                    }
                    else{
                        if (wolf+1 < sheep){
                            Q.push({{c_state,des},{sheep,wolf+1}});
                        }
                    }
                }
            }
        }
    }

    return answer;
}