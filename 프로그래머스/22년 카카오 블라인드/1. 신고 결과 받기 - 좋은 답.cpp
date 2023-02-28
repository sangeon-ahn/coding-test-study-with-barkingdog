#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
/*
  시간복잡도 O(N),
  1. 각각의 id에 번호를 매핑해준다.
  2. report를 정렬한 후, unique와 erase로 중복된 report를 삭제해 준다.
  3. report string을 잘라서 (신고한자의 번호, 신고당한자의 번호)를 짝지어서 v 벡터에 넣어준다.
  4. v를 돌면서 cnt 벡터에 각 id별 신고당한 수를 넣고, 다시 v를 돌면서 cnt 값이 k 이상이면 해당 id에 매핑된 번호에 대해 이메일 카운트를 증가시킨다.
*/
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    // 1.
    const int n = id_list.size();
    map<string, int> Conv;
    for (int i = 0; i < n; i++) Conv[id_list[i]] = i;

    // 2.
    vector<pair<int, int>> v;
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    for (const auto& s : report) {
        stringstream in(s);
        string a, b; in >> a >> b;
        v.push_back({ Conv[a], Conv[b] });
    }

    // 3.
    vector<int> cnt(n), ret(n);
    for (const auto& [a, b] : v) cnt[b]++;
    for (const auto& [a, b] : v) if (cnt[b] >= k) ret[a]++;
    return ret;
}