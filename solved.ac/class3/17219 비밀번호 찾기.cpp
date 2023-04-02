#include <bits/stdc++.h>
using namespace std;

int N, M;
unordered_map<string, string> m; // 정렬 안해주는 맵 사용시 더 빠르다.

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        m[s1] = s2;
    }
    
    for (int i = 0; i < M; i++) {
        string s3;
        cin >> s3;
        cout << m[s3] << '\n';
    }
}