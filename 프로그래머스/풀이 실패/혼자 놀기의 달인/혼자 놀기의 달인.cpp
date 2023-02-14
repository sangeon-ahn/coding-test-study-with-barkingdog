#include <bits/stdc++.h>

using namespace std;
/*
  풀이 실패
*/
int result = 0;
bool vis[110];

int solution(vector<int> cards) {
    int answer = 0;
    
    for (int i = 0; i < cards.size(); i++) {
        vector<int> v;
        int count = 0;
        int a = i;
        
        while (true) {
            if (vis[a]) {
                if (v.size() < 2) {
                    v.push_back(count);  
                    count = 0;
                    
                    for (int i = 0; i < cards.size(); i++) {
                        if (!vis[cards[i]]) {
                            a = cards[i];
                            break;
                        }
                    }
                    continue;
                } else {
                    fill(vis, vis + 110, false);
                    break;
                } 
            }
            
            count++;
            vis[a] = true;
            a = cards[a];
        }
        result = max(result, v[0] * v[1]);
    }
    
    
    answer = result;
    
    return answer;
}