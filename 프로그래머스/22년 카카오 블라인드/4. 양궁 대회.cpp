#include <bits/stdc++.h>
using namespace std;
/*
    과녁: 11칸, 0점~10점
    이긴 과녁을 고르고 최소로 이기는 경우를 파악
    1~n번 이겼을 때를 다 파악?
    풀이실패
    
*/
int shoot[11];
vector<int> winPos;
vector<int> Info;
int N;
vector<int> answer(11, 0);
int pastScoreSum = 0;
int apichScore = 0;

void dfs(int count, int win) {
    if (count == win) {
        int trialSum = 0;
        int scoreSum = 0;
        vector<int> temp(11, 0);
        
        for (int i = 0; i < winPos.size(); i++) {
            temp[10 - winPos[i]]+= Info[10 - winPos[i]] + 1;
            trialSum += Info[10 - winPos[i]] + 1;
            scoreSum = i;
        }
        
        if (trialSum == N && ) {
            if (scoreSum > pastScoreSum) {
                answer = temp;
                pastScoreSum = scoreSum;
            }
            else if (scoreSum == pastScoreSum) {
                answer = answer < temp ? temp : answer;
            }
        }
        
        return;
    }
    
    for (int i = count; i <= 10; i++) {
        winPos.push_back(i);            
        dfs(i + 1, win);
        winPos.pop_back();
    }
    
}
vector<int> solution(int n, vector<int> info) {
    vector<int> ans;
    Info = info;
    N = n;
    
    for (int i = 1; i <= n; i++) {
        dfs(0, i);
    }
    
    for (int i = 0; i < 11; i++) {
        ans.push_back(answer[10 - i]);
    }
    return ans;
}