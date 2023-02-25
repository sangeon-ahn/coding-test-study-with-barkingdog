#include <bits/stdc++.h>

using namespace std;
map<char, int> m;
int arr[8] = {0, 3, 2, 1, 0, 1, 2, 3};

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    for (int i = 0; i < survey.size(); i++) {
        char a = survey[i][0];
        char b = survey[i][1];
        
        if (choices[i] < 4) {
            m[a] += arr[choices[i]];
        } else if (choices[i] > 4) {
            m[b] += arr[choices[i]];
        }
    }
    
    if (m['R'] < m['T']) answer += 'T';
    else answer += 'R';
    
    if (m['C'] < m['F']) answer += 'F';
    else answer += 'C';
    
    if (m['J'] < m['M']) answer += 'M';
    else answer += 'J';
    
    if (m['A'] < m['N']) answer += 'N';
    else answer += 'A';
    return answer;
}