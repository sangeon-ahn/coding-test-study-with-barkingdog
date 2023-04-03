#include <bits/stdc++.h>
using namespace std;

int N, M;
string S;
int idx;
int ps;

void check(int a) {
    int temp = a;
    int p = 0;
    
    while (true) {
        if (temp == M - 1) break;
        
        if (S[temp] == 'I' && S[temp] != S[temp + 1]) {
            temp++;
        }
        else if (S[temp] == 'O' && S[temp] != S[temp + 1]) {
            temp++;
            p++;
        }
        else break;
    }
    idx = temp;
    ps += p - N >= 0 ? p - N + 1 : 0;
    return;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> S;
    
    for (int i = idx; i < M - 2; i++) {
        if (S[i] == 'I') {
            check(i);
            i = idx;
        }
    }
    
    cout << ps;
}