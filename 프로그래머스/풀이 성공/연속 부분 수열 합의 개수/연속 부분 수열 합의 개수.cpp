#include <bits/stdc++.h>
//14분컷
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> s;
    vector<int> new_v;
    
    for (int i = 0; i < elements.size(); i++) {
        new_v.push_back(elements[i]);
    }
    
    for (int i = 0; i < elements.size(); i++) {
        new_v.push_back(elements[i]);
    }
    
    int size = 1;
    
    while (size <= elements.size()) {
        for (int i = 0; i < elements.size(); i++) {
            int sum = 0;
            
            for (int j = 0; j < size; j++) {
                sum += new_v[i + j];
            }
            
            s.insert(sum);
        }
        size++;
    }
    
    answer = s.size();
    return answer;
}