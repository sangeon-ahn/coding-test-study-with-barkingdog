#include <bits/stdc++.h>

using namespace std;

map<int, int> m;
set<int> s;
priority_queue<pair<int, int>> pq;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    // 맵으로 귤 크기별로 몇개씩 있는지 저장
    // 셋으로 귤 크기 종류 저장
    // 서로 다른 종류의 수를 최소화하려면 많은 귤부터 뽑아내면 된다.
    // 우선순위 큐에 (개수, 크기) 넣고 빼가면서 하기
    
    for (int i = 0; i < tangerine.size(); i++) {
        m[tangerine[i]]++;
        s.insert(tangerine[i]);
    }
    
    for (auto it = s.begin(); it != s.end(); it++) {
        pq.push({m[*it], *it});
    }
    
    int sum = 0;
    while (sum != k) {
        // 최대힙에서 하나 뺀 후에 k랑 비교해서 k가 더 크면 sum에 전체 개수 추가하고,
        // k가 더 작으면 k만큼 빼고 sum에 k만큼 추가 후 빠져나오기
        // 개수는 두 가지 경우 둘다 한개씩 추가되므로 개수를 위한 변수 따로 만들기(answer)
        
        auto p = pq.top();
        pq.pop();
        
        if (p.first < k - sum) {
            sum += p.first;
            answer++;
        }
        else if (p.first == k - sum) {
            sum += p.first;
            answer++;
        }
        else {
            sum += k - sum;
            answer++;
        }
    }
    
    return answer;
}