#include <bits/stdc++.h>
using namespace std;

int N;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int clothes;
        cin >> clothes;
        
        int sorts = 0;
        map<string, int> m;
        
        for (int i = 0; i < clothes; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            if (m[s2] == 0) {
                sorts++;
            }
            m[s2]++;
        }
        
        vector<pair<string, int>> vec(m.begin(), m.end());
        int sum = 1;
        for (auto p : vec) {
            sum *= (p.second + 1);
        }
        cout << sum - 1 << '\n';
    }
}