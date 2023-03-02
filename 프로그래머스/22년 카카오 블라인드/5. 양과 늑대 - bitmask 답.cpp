#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool visit[17][131072];
int n, answer;
vector<int> adj[17], vec;
void dfs(int now, int visited)
{
    visit[now][visited] = true;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    if ((visited & (1 << i)))
    {
        if (vec[i] == 0)
            a++;
        else
            b++;
    }
    if (a <= b)
        return;
    answer = max(answer, a);

    for (int next : adj[now])
    if (!visit[next][visited | (1 << next)])
        dfs(next, visited | (1 << next));
}
int solution(vector<int> info, vector<vector<int>> edges) {
    n = info.size();
    vec = info;
    for (auto x : edges){
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    dfs(1, 1);
    return answer;
}