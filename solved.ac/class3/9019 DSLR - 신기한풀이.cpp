#include<bits/stdc++.h>
using namespace std;

constexpr int FROM_A = 1, FROM_B = 0, NONE = -1;
const char OP[5] = { 'D','D','S','L','R' };
char op_pred[10000];
int pred[10000], neighbors[5];
int visitor[10000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int TC, A, B;

    cin >> TC;
    while (TC--) {
        queue<int> Q;
        memset(visitor, NONE, sizeof visitor);
        cin >> A >> B;
        visitor[A] = FROM_A; Q.push(A);
        visitor[B] = FROM_B; Q.push(B);

        bool done = false;
        while (!done) {
            int n = Q.front(); Q.pop();
            int v = visitor[n];
            if (v == FROM_A) {
                neighbors[1] = (n << 1) % 10000;
                neighbors[2] = n ? n - 1 : 9999;
                neighbors[3] = (n % 1000) * 10 + n / 1000;
                neighbors[4] = (n % 10) * 1000 + n / 10;
            }
            else {
                neighbors[0] = n >> 1;
                neighbors[1] = neighbors[0] + 5000;
                neighbors[2] = (n + 1) % 10000;
                neighbors[3] = (n % 10) * 1000 + n / 10;
                neighbors[4] = (n % 1000) * 10 + n / 1000;
            }
            for (int i = v; i < 5; ++i) {
                if (i < 2 && (n & 1) && v == FROM_B)
                    continue;
                int nn = neighbors[i];
                if (visitor[nn] == v)
                    continue;
                else if (visitor[nn] == NONE) {
                    visitor[nn] = v;
                    pred[nn] = n;
                    op_pred[nn] = OP[i];
                    Q.push(nn);
                }
                else {
                    int a = n, b = nn;
                    string s;
                    if (v == FROM_B)
                        swap(a, b);
                    while (a != A) {
                        s.push_back(op_pred[a]);
                        a = pred[a];
                    }
                    for (auto rit = s.rbegin(); rit != s.rend(); ++rit)
                        cout << *rit;
                    cout << OP[i];
                    while (b != B) {
                        cout << op_pred[b];
                        b = pred[b];
                    }
                    cout << '\n';
                    done = true;
                    break;
                }
            }
        }
    }

    return 0;
}
