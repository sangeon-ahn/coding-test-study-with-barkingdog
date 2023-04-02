#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    priority_queue<long long, vector<long long>> pq;
    
    for (int i = 0; i < N; i++) {
        long long num;
        cin >> num;
            
        if (num != 0) {
            pq.push(num);
        }
        else {
            if (pq.empty()) {
                cout << "0\n";
            } else {
                cout << pq.top() << '\n';
                pq.pop();    
            }           
        }
    }
}
