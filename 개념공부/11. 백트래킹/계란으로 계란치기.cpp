#include <bits/stdc++.h>
using namespace std;

int N; // 계란 개수
vector<pair<int, int>> eggs; // (내구도, 무게)
int ans = 0;

void backtracking(int order, int cnt) {
    // 마지막 달걀 집었으면 깨진달걀 갱신.
    if (order == N) {
        ans = max(ans, cnt);
        return;
    }

    if (eggs[order].first <= 0 || cnt == N - 1) {
      backtracking(order + 1, cnt);
      return;
    }

    // 부딪힐 달걀 고르기
    for (int i = 0; i < N; i++) {
        // 같은 달걀이면 패스
        // 내구도 -인 달걀이면 패스
        if (i == order || eggs[i].first <= 0) continue;

        // 충격실험 시작
        auto a = eggs[order];
        auto b = eggs[i];

        int a_health = a.first - b.second;
        int b_health = b.first - a.second;

        eggs[order] = {a_health, a.second};
        eggs[i] = {b_health, b.second};

        int adds = 0;
        if (a_health <= 0) adds++;
        if (b_health <= 0) adds++;

        backtracking(order + 1, cnt + adds);
        eggs[order] = a;
        eggs[i] = b;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for (int i = 0 ; i < N; i++) {
        int a, b;
        cin >> a >> b;
        eggs.push_back({a, b});
    }

    backtracking(0, 0);
    cout << ans;
}