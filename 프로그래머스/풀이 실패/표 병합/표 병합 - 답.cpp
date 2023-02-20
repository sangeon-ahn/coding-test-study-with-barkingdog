#include <bits/stdc++.h>
using namespace std;

int uf[2501];
string val[2501];

int uf_find(int a) { // 선택된 셀의 인덱스를 찾는 함수
    return uf[a] == -1 ? a : uf[a] = uf_find(uf[a]); // 재귀적으로 제일 위 조상이 누군지 찾는다. 부모가 아니라 조상이다.
}

bool uf_union(int a, int b) { // A가 B를 먹는다.
    int A = uf_find(a), B = uf_find(b);
    if (A == B) return false;

    uf[B] = A; // B의 부모가 A이다. B는 b의 최고 조상, A는 a의 최고 조상
    if (val[A].empty() && val[B].size()) val[A] = val[B]; // A는 값이 없고 B는 값이 있으면 A는 B의 값을 가진다.
    else val[B] = val[A]; // 그 외의 경우에는 B가 A의 값을 가진다.
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

            for (int i = 0; i < 2500; i++) uf_find(i); // 이거 하는 이유? 이거 하면 uf[i]가 재조정되면서 자기 영역의 최고 조상을 가리키게됨.
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
