#include <bits/stdc++.h>
using namespace std;

int N, M;

map<string, int> m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        m[name]++;
    }
    
    for (int i = 0; i < M; i++) {
        string name;
        cin >> name;
        m[name]++;
    }
    
    vector<pair<string, int>> vec(m.begin(), m.end());
    int sum = 0;
    vector<string> names;
    for (auto p : vec) {
        if (p.second == 2) {
            sum++;
            names.push_back(p.first);
        }
    }
    cout << sum << '\n';
    sort(names.begin(), names.end());
    for (string s : names) {
        cout << s << '\n';
    }
}