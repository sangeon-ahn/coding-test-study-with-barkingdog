#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> d;
int c;
int r_b;
int r_e;

bool compare(vector<int> v1, vector<int> v2) {
        if (v1[c - 1] < v2[c - 1]) return true;
        else if (v1[c - 1] > v2[c - 1]) return false;
        else return v1[0] > v2[0];
}

int cal(int row) {
        int sum = 0;
        for (int i = 0; i < d[row - 1].size(); i++) {
            sum += d[row - 1][i] % (row);
        }
        return sum;
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    d = data, c = col, r_b = row_begin, r_e = row_end;


    sort(d.begin(), d.end(), compare);

    // for (auto v: d) {
    //     for (int n: v) {
    //         cout << n << ' ';
    //     }
    //     cout << '\n';
    // }
    int result = 0;
    for (int i = r_b; i <= r_e; i++) {
        result = result ^ cal(i);
    }

    answer = result;
    return answer;
}