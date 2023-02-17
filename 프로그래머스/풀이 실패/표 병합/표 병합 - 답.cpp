#include <bits/stdc++.h>
using namespace std;

int uf[2501];
string val[2501];

int uf_find(int a) { return uf[a] == -1 ? a : uf[a] = uf_find(uf[a]); }
bool uf_union(int a, int b) {
    int A = uf_find(a), B = uf_find(b);
    if (A == B) return false;
    uf[B] = A;
    if (val[A].empty() && val[B].size()) val[A] = val[B];
    else val[B] = val[A];
    return true;
}

vector<string> solution(vector<string> commands) {
    memset(uf, -1, sizeof(uf));
    vector<string> answer;
    for (string str : commands) {
        stringstream ss(str);

        string com; ss >> com;

        if (com == "UPDATE") {
            if (count(str.begin(), str.end(), ' ') == 3) {
                int r, c; string value;
                ss >> r >> c >> value;
                r--;c--;

                int pos = uf_find(r * 50 + c);
                val[pos] = value;
            } else {
                string val1, val2;
                ss >> val1 >> val2;

                for (int i = 0; i < 2500; i++) {
                    int pos = uf_find(i);
                    if (val[pos] == val1) val[pos] = val2;
                }
            }
        } else if (com == "MERGE") {
            int r1, c1, r2, c2;
            ss >> r1 >> c1 >> r2 >> c2;
            r1--; r2--; c1--; c2--;

            uf_union(r1 * 50 + c1, r2 * 50 + c2);
        } else if (com == "UNMERGE") {
            int r, c;
            ss >> r >> c;
            r--; c--;

            int x = uf_find(r * 50 + c);
            string tmp = val[x];

            for (int i = 0; i < 2500; i++) uf_find(i);
            for (int i = 0; i < 2500; i++) {
                if (uf_find(i) == x) {
                    val[i] = "";
                    uf[i] = -1;
                }
            }

            val[r * 50 + c] = tmp;
        } else {
            int r, c; ss >> r >> c;
            r--; c--;

            int pos = uf_find(r * 50 + c);
            if (val[pos].empty()) answer.push_back("EMPTY");
            else answer.push_back(val[pos]);
        }
    }
    return answer;
}
