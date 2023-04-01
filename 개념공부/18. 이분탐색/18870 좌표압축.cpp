#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1000010];
set<int> s;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        arr[i] = n;
        s.insert(n);
    }
    
    vector<int> temp(s.begin(), s.end());
    
    sort(temp.begin(), temp.end());
    
    map<int, int> m;
    
    for (int i = 0; i < temp.size(); i++) {
        m[temp[i]] = i;
    }
    
    for (int i = 0; i < N; i++) {
        cout << m[arr[i]] << ' ';
    }
}