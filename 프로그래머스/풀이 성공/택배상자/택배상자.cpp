#include <bits/stdc++.h>
/*
    order에 4, 3, 1, 2, 5가 있다면, 4번째 상자, 3번째 상자, 1번째 상자, 2번째 상자, 5번째 상자를 순서대로 실어야 한다.
    5 4 3 2 1 영재 이렇게 되어 있다.
    1. 스택 1과 스택 2의 top 확인 후 둘다 아니면 스택 1에서 스택 2로 옮김
    2. 찾으면 그 상자 뺌, answer++
*/

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    stack<int> st1;
    stack<int> st2;
    
    for (int i = 0; i < order.size(); i++) {
        st1.push(order.size() - i);
    }
    int idx = 0;
    
    while (true) {
        if (!st1.empty() && st1.top() == order[idx]) {
            answer++;
            idx++;
            st1.pop();
            continue;
        }
        
        else if (!st2.empty() && st2.top() == order[idx]) {
            answer++;
            idx++;
            st2.pop();
            continue;
        } 
        
        if (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        } else break;
        
    }
    return answer;
}