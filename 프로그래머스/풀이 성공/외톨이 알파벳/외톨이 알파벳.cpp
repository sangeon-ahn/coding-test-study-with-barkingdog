#include <bits/stdc++.h>

using namespace std;

map<char, int> mmap;
map<char, bool> can;
set<char> sset;
vector<char> v;

string solution(string input_string) {
    string answer = "";
    
    // can 맵 초깃값 설정.
    for (int i = 0; i < input_string.size(); i++) {
        char c = input_string[i];
        
        can[c] = true;
        sset.insert(c);
    }
    
    for (int i = 0; i < input_string.length(); i++) {
        char c = input_string[i];
        
        if (can[c]) {
            mmap[c]++;
            
            for (auto it = can.begin(); it != can.end(); it++) {
                can[it->first] = true;
            }
            
            can[c] = false;
        }
    }
    
    // mmap이 2 이상인 것만 v에 추가.
    for (auto it = sset.begin(); it != sset.end(); it++) {
        if (mmap[*it] >= 2) {
            v.push_back(*it);            
        }
    }

    // 사전순 정렬.
    sort(v.begin(), v.end());
    for (char c: v) {
        answer += c;
    }
    
    return answer == "" ? "N" : answer;
}