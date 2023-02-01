#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;

    long long sum = 0;
    long long sum1 = 0;
    long long sum2 = 0;
    queue<int> q1;
    queue<int> q2;

    for (int i = 0; i < queue1.size(); i++) {
        sum += queue1[i];
        sum += queue2[i];

        sum1 += queue1[i];
        sum2 += queue2[i];

        q1.push(queue1[i]);
        q2.push(queue2[i]);
    }

    // 합이 홀수면 못나눔.
    if (sum % 2 != 0) {
        return -1;
    }

    int max_trial = queue1.size() * 10;

    while (max_trial > 0) {
        max_trial -= 1;
        // 두 큐중 하나 비어있으면 끝
        if (q1.empty() || q2.empty()) {
            return -1;
        }

        // 합이 같으면 끝.
        if (sum1 == sum2) {
            break;
        }

        if (sum1 > sum2) {
            int p = q1.front(); q1.pop();
            q2.push(p);
            sum1 -= p;
            sum2 += p;
            answer++;
        }

        else if (sum1 < sum2) {
            int p = q2.front(); q2.pop();
            q1.push(p);
            sum1 += p;
            sum2 -= p;
            answer++;
        }
    }
    if (max_trial == 0) return -1;

    return answer;
}