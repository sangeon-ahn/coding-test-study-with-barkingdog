#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    set<int> s1;
    int arr[1000001] = {0, };
    set<int> s2;

    for (int i = 0; i < topping.size(); i++) {
        s1.insert(topping[i]);
        arr[topping[i]]++;
    }


    // 토핑을 자르면서 하나씩 s2에 추가시킨다. arr에서 토핑의 개수를 -1 시키고 해당 토핑이 0개면 s1에서 해당 토핑을 제거한다.
    for (int i = 0; i < topping.size() - 1; i++) {
        s2.insert(topping[i]);
        arr[topping[i]]--;

        if (arr[topping[i]] <= 0) s1.erase(topping[i]);
        if (s1.size() == s2.size()) answer++;
    }

    return answer;
}