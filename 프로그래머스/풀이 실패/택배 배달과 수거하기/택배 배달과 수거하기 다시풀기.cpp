#include <bits/stdc++.h>
using namespace std;
/*
    배달과 수거를 위한 스택을 따로 만든 후에 집1부터 집5까지 배달과 수거 개수를 스택에 각각 넣는다.
    이후 while문을 수행하고 조건은 배달과 수거 스택이 모두 비어있을 때 while문을 빠져나간다.
    while 내에서는 우선 두 스택에서 값을 빼내서 값이 0이면 패스하고, 0이 아니면 로직을 수행한다.
    로직은 cap에서 해당 값을 빼면 된다. 먼저 배달스택부터 시작하고 cap이 0이 되면 수거 스택을 시작한다.
    cap과 해당 값을 비교해서, 해당 값이 더 크면 cap이 0이 되면서 다시 while문이 시작된다.
    그리고 배달 스택과 수거 스택의 크기를 비교해서 더 큰 값 * 2를 이동한 총 거리에 더한다.
*/
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    stack<int> dels;
    stack<int> pics;

    // 스택에 배달 수거 개수 넣기.
    // for (int i = 0; i < deliveries.size(); i++) {
    //     dels.push(deliveries[i]);
    //     pics.push(pickups[i]);
    // }

    // 스택에 다 넣기.
    for (int i: deliveries) {
      dels.push(i);
    }

    for (int i: pickups) {
      pics.push(i);
    }

    // 스택 빌 때까지 거리 구하기
    while (!dels.empty() || !pics.empty()) {
        // dels top 값 0이면 빼고 패스
        if (!dels.empty() && dels.top() == 0) {
          dels.pop();
          continue;
        }

        // pics top 값 0이면 빼고 패스
        if (!pics.empty() && pics.top() == 0) {
          pics.pop();
          continue;
        }

        // 이제 두 스택 다 top이 0이 아니다.

        // 가장 멀리 배달해야 할 집의 거리
        int max_deli_dist = dels.size();

        // 가장 멀리 수거해야 할 집의 거리
        int max_pics_dist = pics.size();

        // 둘 중 큰 값 * 2가 해당 턴에 이동한 거리.
        answer += max(max_deli_dist, max_pics_dist) * 2;

        int temp = cap;

        // 배달하기, 비어있지 않고 아직 배달 물건 남아있으면
        while (!dels.empty() && temp != 0) {
            int d = dels.top();

            // cap보다 큰 경우, 같은 경우, 작은 경우 3가지로 나눔
            if (d > temp) {
                dels.pop();
                dels.push(d - temp);
                temp = 0;
            }else {
                dels.pop();
                temp -= d;
            }
        }
        temp = 0;
        // 수거하기, 현재 temp = 0이고 temp == cap이 될 때까지 수거 가능
        while (!pics.empty() && temp != cap) {
            int p = pics.top();

            // cap - temp보다 큰 경우, 같은 경우, 작은 경우 3가지로 나눔
            // 한번에 다 수거 못하는 집인 경우
            if (p > cap - temp) {
                pics.pop();
                pics.push(p - (cap - temp));
                temp = cap;
            }else {
                pics.pop();
                temp += p;
            }
        }
    }
    return answer;
}

int main() {
  int ans = solution(4, 5, {1, 0, 3, 1, 2}, {0, 3, 0, 4, 0});
  cout << ans;
}
