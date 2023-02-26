#include <string>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
set<pair<int, int>> arr[50001];
int ans[50001];
char tmp[50001];
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    for (int i = 1; i <= n; ++i)
        ans[i] = 100000000, tmp[i] = 0;
    for (auto& gate : gates)
        tmp[gate] = 'g';
    for (auto& summit : summits)
        tmp[summit] = 's';
    for (auto& path : paths)
        if (tmp[path[0]] == 'g' || tmp[path[1]] == 's')       // 시작점이 입구거나 도착점이 산봉우리인 경우
            arr[path[0]].insert(make_pair(path[1], path[2]));
        else if (tmp[path[0]] == 's' || tmp[path[1]] == 'g')  // 시작점이 산봉우리거나 도착점이 입구인 경우
            arr[path[1]].insert(make_pair(path[0], path[2]));
        else
            arr[path[0]].insert(make_pair(path[1], path[2])), arr[path[1]].insert(make_pair(path[0], path[2]));

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;    // pair<소요시간,정점>
    for (auto& gate : gates)
        q.push(make_pair(0, gate)), ans[gate] = 0;
    while (!q.empty()) {
        auto p = q.top(); q.pop();
        auto x = p.second, t1 = p.first;
        if (ans[x] < t1)
            continue;
        for (auto& temp : arr[x]) {
            auto y = temp.first, t2 = temp.second;
            if (ans[y] > max(t1, t2))
                ans[y] = max(t1, t2), q.push(make_pair(ans[y], y));
        }
    }

    sort(summits.begin(), summits.end());       // 산봉우리 입력값이 정렬되어 있지 않음.. ㅂㄷㅂㄷ
    vector<int> answer{0, 100000000};
    for (auto& sm : summits)
        if (ans[sm] < answer[1])
            answer[0] = sm, answer[1] = ans[sm];
    return answer;
}