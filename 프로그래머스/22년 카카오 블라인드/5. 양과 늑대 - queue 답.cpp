#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_STATE 17
using namespace std;
typedef struct NODE {
    int cur, sheep, wolf, state;
};
vector<int> adj[20];
vector<int> Info;
bool visited[17][1 << MAX_STATE];

int bfs() 
{
    queue<NODE> q;
    q.push({ 0, 1, 0, 1 });
    visited[0][1] = true;

    int ret = 0;

    while (q.empty() == false)
    {
        NODE cur = q.front();
        q.pop();

        ret = max(ret, cur.sheep);

        for (int i = 0; i < adj[cur.cur].size(); i++)
        {
            int next = adj[cur.cur][i];

            int ns = 0;
            int nw = 0;

            if (Info[next] == 1 && ((cur.state >> next) & 1) == false) nw = 1;
            if (Info[next] == 0 && ((cur.state >> next) & 1) == false) ns = 1;

            if (cur.sheep <= cur.wolf + nw) continue;
            int state = cur.state | (1 << next);

            if (visited[next][state] == true) continue;

            visited[next][state] = true;
            q.push({ next, cur.sheep + ns, cur.wolf + nw, state });
        }
    }

    return ret;
}


int solution(vector<int> info, vector<vector<int>> edges) {
    Info = info;
    for (auto eg : edges) {
        adj[eg[0]].push_back(eg[1]);
        adj[eg[1]].push_back(eg[0]);
    }
    int answer = bfs();
    return answer;
}