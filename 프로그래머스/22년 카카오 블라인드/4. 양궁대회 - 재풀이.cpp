#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<int> info) {
    vector<int> ans(11);
    int mx = 0;
    
    // 0 ~ 10의 칸 중에 이길 칸을 고르는 for문.
    for (int i = 0; i < 2048; i++) {
        vector<int> result(11);
        int shoot_sum = 0;
        int score = 0;
        
        for (int j = 0; j <= 10; j++) {
            // 해당 비트열 순서가 1이면 라이언이 이김
            if (i & 1 << j) {
                result[10 - j] = info[10 - j] + 1;
                shoot_sum += result[10 - j];
                score += j;
            }
            // 0이면 어피치가 1개 이상 쐈을 땐 라이언이 짐
            else {
                if (info[10 - j] > 0) score -= j;
            }
        }
        
        // 쏜 화살이 n보다 크면 패스
        if (shoot_sum > n) continue;
        
        // 쏜 화살이 n보다 작으면 남은거 다 0점에 넣기
        else if (shoot_sum < n) result[10] += n - shoot_sum;
        
        // 졌거나 최대 스코어보다 작으면 패스
        if (score <= 0 || score < mx) continue;
        // 스코어가 현재 최대값보다 크면 갱신
        if (mx < score) ans = result;
        
        // 점수가 같으면 가장 낮은 점수에 맞춘 화살이 많은 경우로 갱신.
        else if (mx == score) {
            bool flag = true;
            
            for (int j = 11; j >= 0; j--) {
                if (ans[j] > result[j]) {
                    flag = false;
                    break;
                }
                if (ans[j] < result[j]) break;
            }
            
            if (flag) ans = result;
        }
        mx = score;
    }
    
    if (mx > 0) return ans;
    return {-1};
}