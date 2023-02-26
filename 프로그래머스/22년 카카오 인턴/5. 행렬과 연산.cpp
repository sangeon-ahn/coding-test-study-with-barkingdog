#include <bits/stdc++.h>
using namespace std;
// 오답
int board[50001][50001];

void rotate(vector<vector<int>> rc) {
    for (int i = 0; i < rc[0].size() - 1; i++) {
        board[0][i + 1] = rc[0][i];
        board[i + 1][rc[0].size() - 1] = rc[i][rc[0].size() - 1];
        board[rc[0].size() - 1][i] = rc[rc[0].size() - 1][i + 1];
        board[i][0] = rc[i + 1][0];
    }
}

void shiftRow(vector<vector<int>> rc) {
    vector<int> temp = rc[rc[0].size() - 1];
    
    for (int i = 0; i < rc.size() - 1; i++) {
        for (int j = 0; j < rc.size(); j++) {
            board[i + 1][j] = rc[i][j];
        }
    }
    for (int i = 0; temp.size(); i++) {
        board[0][i] = temp[0];
    }
}

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    vector<vector<int>> answer;
    
    for (string op: operations) {
        if (op == "Rotate") {
            rotate(rc);
            
            for (int i = 0; i < rc.size(); i++) {
                for (int j = 0; j < rc.size(); j++) {
                    if (board[i][j] != 0) {
                        rc[i][j] = board[i][j];
                    }
                }
            }
        }
        else if (op == "ShiftRow") {
            shiftRow(rc);
            for (int i = 0; i < rc.size(); i++) {
                for (int j = 0; j < rc.size(); j++) {
                    rc[i][j] = board[i][j];
                }
            }
        }
    }

    answer = rc;
    return answer;
}