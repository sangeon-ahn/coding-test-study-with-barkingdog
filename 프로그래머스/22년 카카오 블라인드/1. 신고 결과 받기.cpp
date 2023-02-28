#include <bits/stdc++.h>
using namespace std;
/*
    1. 유저별로 신고당한 횟수를 저장하는 reported map 생성
    2. report 벡터의 원소를 split으로 신고자-당한자로 분리해서 reported map에 저장
    3. 유저별로 신고한 아이디를 저장하는 reporting map 생성 후 2번 과정에서 저장 
    4. reported map 순회하면서 id가 k 이상인 경우 reporting에서 신고한 아이디 얻어서 emails map에 저장
    5. result 출력

    20분 소요, 시간복잡도 O(N^2)
*/
map<string, int> reportedCount;

// <신고당한id, 신고한id>
map<string, vector<string>> reporting;

map<string, int> emails;
vector<int> answer;


vector<string> split(string str, char delimiter) {
    stringstream ss(str);
    string temp;
    vector<string> result;
    
    while (getline(ss, temp, delimiter)) {
        result.push_back(temp);
    }
    
    return result;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    for (string rp : report) {
        vector<string> rep = split(rp, ' ');
        
        auto it = find(reporting[rep[1]].begin(), reporting[rep[1]].end(), rep[0]);
        
        // 이미 신고했으면 패스
        if (it != reporting[rep[1]].end()) continue;
        
        reportedCount[rep[1]]++;
        reporting[rep[1]].push_back(rep[0]);        
    }
    
    for (string id : id_list) {
        if (reportedCount[id] >= k) {
            for (int i = 0; i < reporting[id].size(); i++) {
                emails[reporting[id][i]]++;
            }
        }
    }
    
    for (string id : id_list) {
        answer.push_back(emails[id]);
    }
    
    return answer;
}
