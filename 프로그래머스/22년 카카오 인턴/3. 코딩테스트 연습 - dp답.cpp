#include <bits/stdc++.h>
using namespace std;

// d[i][j] : 알고력 i, 코딩력 j를 달성하기 위한 시간
// 마지막 테스트케이스 시간초과
int d[505][505];

const int MX = 0x7f7f7f7f;

int solution(int alp, int cop, vector<vector<int>> problems) {
    for(int i = 0; i <= 502; i++) fill(d[i], d[i]+503, MX);
    d[alp][cop] = 0;
    int mxalp = -1, mxcop = -1;
    for(auto& problem : problems){
        mxalp = max(mxalp, problem[0]);
        mxcop = max(mxcop, problem[1]);
    }
    //cout << mxalp << ' ' << mxcop << '\n';
    int ans = MX;
    for(int i = alp; i <= 500; i++){
        for(int j = cop; j <= 500; j++){
            if(i >= mxalp && j >= mxcop) continue;
            // d[i][j]에는 이미 제대로된 값이 들어가있음
            d[i+1][j] = min(d[i+1][j], d[i][j]+1);
            d[i][j+1] = min(d[i][j+1], d[i][j]+1);
            for(auto& problem : problems){
                int alp_req, cop_req, alp_rwd, cop_rwd, cost;
                alp_req = problem[0];
                cop_req = problem[1];
                alp_rwd = problem[2];
                cop_rwd = problem[3];
                cost = problem[4];
                if(alp_req > i || cop_req > j) continue;
                int alp_nxt = i + alp_rwd;
                int cop_nxt = j + cop_rwd;
                if(alp_nxt >= mxalp && cop_nxt >= mxcop){
                    ans = min(ans, d[i][j] + cost);
                    continue;
                }
                if(alp_nxt > 500 || cop_nxt > 500) continue;
                d[alp_nxt][cop_nxt] = min(d[alp_nxt][cop_nxt], cost + d[i][j]);                
            }
        }
    }
    for(int i = mxalp; i <= 500; i++){
        for(int j = mxcop; j <= 500; j++){
            ans = min(ans, d[i][j]);
        }
    }

//     cout << d[80][0] << '\n';
//     cout << d[80][10] << '\n';

    return ans;
}
