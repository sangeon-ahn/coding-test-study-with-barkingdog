#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

bool compare(pair<int,int>& a, pair<int,int>& b) {
    if (a.second == b.second) 
        return a.first < b.first;
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0, sum = 0;
    map<int, int> ma;

    for(int i = 0; i < tangerine.size(); i++){
        ma[tangerine[i]]++;
    }

    vector<pair<int,int>> vec(ma.begin(), ma.end());
    sort(vec.begin(), vec.end(), compare);

    for(int i = 0; i < vec.size(); i++){
        if(sum >= k)
            break;
        sum += vec[i].second;
        answer++;
    }

    return answer;
}