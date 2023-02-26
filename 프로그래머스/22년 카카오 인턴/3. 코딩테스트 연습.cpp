#include <bits/stdc++.h>
using namespace std;
// 오답
int dp[451][451];
int INF = 1e9;

pair<int, int> getGoal(vector<vector<int>> problems) {
    int maxAlp = 0;
    int maxCop = 0;
    
    for (int i = 0; i < problems.size(); i++) {
        maxAlp = max(maxAlp, problems[i][0]);
        maxCop = max(maxCop, problems[i][1]);
    }
    
    return {maxAlp, maxCop};
}

void solveProblems(int i, int j, vector<vector<int>> problems) {
    for (auto problem : problems) {
        // 해당 문제를 못풀면 패스
        int algo = problem[0], cop = problem[1], getAlgo = problem[2], getCop = problem[3], cost = problem[4];
        
        if (i - getAlgo >= algo && j - getCop >= cop) {
            dp[i][j] = min(dp[i][j], dp[i-getAlgo][j-getCop] + cost);    
        }
    }
}

int getAnswer(int a, int b) {
    int result = 99999999;
    for (int i = a; i < 451; i++) {
        for (int j = b; j < 451; j++) {
            result = min(result, dp[i][j]);
        }
    }
    
    return result;
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    // 목표치를 구한다.
    pair<int, int> goal = getGoal(problems);

    // 초기 알고력, 코딩력이 목표치보다 크면 0 리턴
    if (alp >= goal.first && cop >= goal.second) return 0;
    
    for (int i = 0; i < 451; i++) {
        fill(dp, dp + 451, INF);
    }
    dp[alp][cop] = 0;
    // dp를 수행하며 최소 비용을 계산한다.
    
    for (int i = alp; i < 451; i++) {
        for (int j = cop; j < 451; j++) {
            if (i == alp && j == cop) continue;
            
            if (i - 1 >= 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            }
            if (j - 1 >= 0) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
            
            solveProblems(i, j, problems);
        }
    }
    
    int result = getAnswer(goal.first, goal.second);
    answer = result;
    return answer;
}
