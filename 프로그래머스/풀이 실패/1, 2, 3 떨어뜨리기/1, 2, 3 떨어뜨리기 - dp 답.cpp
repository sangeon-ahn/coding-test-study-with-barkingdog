#include <vector>
#include <algorithm>

using namespace std;

int idx[101]={0,}; // idx[i] : 노드 i가 현재 방문해야 할 자식 노드
vector<int> rel[101]; // rel[i] : 노드 i의 자식들 (오름차순 정렬)

int DFS(int cur)
{
    if (rel[cur].empty()) return cur;

    int nxt = rel[cur][idx[cur]];
    idx[cur] = (idx[cur] + 1) % rel[cur].size();

    return DFS(nxt);
}

vector<int> solution(vector<vector<int>> edges, vector<int> target)
{
    vector<int> answer;

    int n=target.size(), cnt[102]={0,}, pos[101]={0,}; // n : 노드 갯수, cnt[i] : 노드 i를 방문하는 횟수, pos[i] : 노드 i가 1, 2, 3 중 현재 선택해야 하는 것이 있는 idx
    bool flag;
    vector<int> order, DP[101][101]; // DP[i][j] : i개의 1, 2, 3을 가지고 값 j를 만들 때 사전 순으로 가장 빠른 조합

    sort(edges.begin(), edges.end());
    for(vector<int> edge : edges) rel[edge[0]].push_back(edge[1]);

    DP[0][0]={0}, DP[1][1]={1}, DP[1][2]={2}, DP[1][3]={3};

    for(int i=1; i<=100; i++)
    {
        for(int j=1; j<=100; j++)
        {
            for(int k=1; k<=3; k++)
            {
                if(j>=k && !DP[i-1][j-k].empty())
                {
                    vector<int> tmp;
                    if(i != 1) tmp = DP[i - 1][j - k];
                    tmp.push_back(k);
                    if(DP[i][j].empty() || tmp < DP[i][j]) DP[i][j] = tmp;
                }
            }
        }
    }

    do
    {  
        int v = DFS(1);
        order.push_back(v);
        cnt[v]++;
        flag = true;

        for (int k = 1; k <= n; k++)
        {
            if (cnt[k] > target[k - 1]) return {-1}; // upper bound 조건.
            if (DP[cnt[k]][target[k-1]].empty()) flag = false; // 해당 count수와 target값으로 숫자 표현이 가능해질 때까지 while문을 돈다.
        }
    }
    while (!flag);

    for (int v : order) // 떨어지는 노드 순서 ex) 1, 9, 2, 5, 1, 4
        answer.push_back(DP[cnt[v]][target[v-1]][pos[v]++]); // answer은 1, 2, 3 으로 이루어짐. v = 9이고 노드 9의 카운트값 4 타겟값이 5면 dp에는 원소가 4개 있을거다. 하지만 노드 9는 전체 order에 퍼져있기 때문에 post[v]++를 해줘서 해당 노드 9가 나타날 때마다 dp원소 4개를 그때마다 선택해준다.

    return answer;
}