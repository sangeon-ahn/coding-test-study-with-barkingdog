#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        int temp;
        int count = 0;
        if (M < N) {
            temp = x; // 3
            int diff = N - M; // 2
            while (true) {
                if (temp == y) {
                    cout << count * M + x << '\n';
                    break;
                }
                else if (temp == x && count != 0) {
                    cout << -1 << '\n';
                    break;
                }
                else {
                    temp = temp - diff > 0 ? temp - diff : N + temp - diff;
                    count++;
                }
            }
        }
        else if (M > N) {
            temp = y;
            int diff = M - N;
            while (true) {
                if (temp == x) {
                    cout << count * N + y << '\n';
                    break;
                }
                else if (temp == y && count != 0) {
                    cout << -1 << '\n';
                    break;
                }
                else {
                    temp = temp - diff > 0 ? temp - diff : M + temp - diff;
                    count++;
                }
            }
        }
        else {
            if (x != y) cout << -1 << '\n';
            else cout << x << '\n';
        }
    }
}