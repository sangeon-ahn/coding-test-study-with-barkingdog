#include <bits/stdc++.h>
using namespace std;

int N, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    
    vector<string> vec1;
    vec1.resize(N); // 이렇게 크기 설정하는게 선언할 때 (N) 이렇게 하는 것보다 빠르다.
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        vec1[i] = s;
    }
    sort(vec1.begin(), vec1.end());
    vector<string> vec2;
    string s; // 루프마다 선언하는 것보다 빠르다.
    for (int i = 0; i < M; i++) {
        cin >> s;
        if (binary_search(vec1.begin(), vec1.end(), s)) {
            vec2.push_back(s);
        } 
    }
    
    sort(vec2.begin(), vec2.end());
    cout << vec2.size() << '\n';
    for (auto name : vec2) {
        cout << name << '\n';
    }
}