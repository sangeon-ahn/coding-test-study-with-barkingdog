#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    int n = edges.size() + 1, T = 0;
    vector adj(n, vector(0, 0));
    for (auto _ : edges) {
        int a = _[0], b = _[1];
        adj[a - 1].push_back(b - 1);
    }
    for (int i = 0; i < n; i++) sort(adj[i].begin(), adj[i].end());

    vector<int> pos(n), cnt(n), C(n), Q;
    for (int i = 0; i < n; i++) if (adj[i].empty() && target[i]) T++;
    while (T) {
        int cur = 0;
        while (adj[cur].size()) cur = adj[cur][pos[cur]++ % adj[cur].size()];
        cnt[cur]++; Q.push_back(cur);
        if (cnt[cur] > target[cur]) return { -1 };
        if (!C[cur] && target[cur] <= 3 * cnt[cur]) C[cur] = 1, T--; // 여기서 타겟만큼 채울 수 있는 상황이 확인되면 T--해준다.
    }

    vector<int> ret;
    for (int i : Q) {
        cnt[i]--;
        for (int val : { 1, 2, 3 }) {
            if (target[i] - val <= 3 * cnt[i] && cnt[i] <= target[i] - val) { // 여기서 우선 카운트값 * 3배 했을 때 남은 타겟값보다 커야하고, 남은 타켓값이 카운트값보다는 같거나 커야한다.
                ret.push_back(val);
                target[i] -= val;
                break;
            }
        }
    }
    return ret;
}