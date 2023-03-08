#include <bits/stdc++.h>
using namespace std;

string solution(string new_id) {
    string answer = "";
    
    // 1단계
    for (char c : new_id) {
        if (65 <= c && c <= 90) {
            char temp = c + 32;
            answer += temp;
        }
        else answer += c;
    }
    
    // 2단계
    string s = "";
    for (char c : answer) {
        if (!(97 <= c && c <= 122) && !(0 <= c - '0' && c - '0' <= 9) && c != '-' && c != '_' && c != '.') continue;
        else s += c;
    }
    answer = s;
    
    // 3단계
    string s2 = "";
    bool flag = false;
    
    for (int i = 0; i < answer.size(); i++) {
        if (answer[i] == '.') {
            s2 += '.';
            i++;
            while (i < answer.size()) {
                if (answer[i] == '.') {
                    i++;
                    continue;
                }
                else {
                    s2 += answer[i];
                    break;
                }
            }
        }
        else s2 += answer[i];
    }
    answer = s2;
    
    // 4단계
    if (answer[0] == '.') answer = answer.substr(1, answer.size());
    if (answer[answer.size() - 1] == '.') answer = answer.substr(0, answer.size() - 1);
    
    // 5단계
    if (answer == "") answer += "a";
    
    // 6단계
    if (answer.size() >= 16) {
        answer = answer.substr(0, 15);
        if (answer[14] == '.') answer = answer.substr(0, 14);
    }
    
    // 7단계
    if (answer.size() <= 2) {
        char c = answer[answer.size() - 1];
        while (answer.size() != 3) {
            answer += c;
        }
    }
    
    return answer;
}