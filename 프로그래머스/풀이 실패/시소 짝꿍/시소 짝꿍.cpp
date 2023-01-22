#include <bits/stdc++.h>
// 20분, 테케 5개 맞고 나머지 시간초과

using namespace std;
/*
    1. 두명 조합을 구한다.
    2. 2,3,4m에 대한 순열을 구한다.
    3. A무게 * A거리 == B무게 * B거리일 때 ans++ 한다.
*/
long long solution(vector<int> weights) {
    long long answer = 0;
    vector<int> v(weights.size(), 1);
    v[0] = 0;
    v[1] = 0;
    int dist[3] = {2, 3, 4};
    
    do {
        vector<int> temp;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 0) {
                temp.push_back(weights[i]);
            }
        }
        
        for (int j = 0; j < 9; j++) {
            int brute = j;
            vector<int> orders;
            
            for (int k = 0; k < 2; k++) {
                int idx = brute % 3;
                brute /= 3;
                orders.push_back(dist[idx]);
            }
            
            if (temp[0] * orders[0] == temp[1] * orders[1]) {
                answer++;
                break;
            }
        }
    } while(next_permutation(v.begin(), v.end()));

    return answer;
}