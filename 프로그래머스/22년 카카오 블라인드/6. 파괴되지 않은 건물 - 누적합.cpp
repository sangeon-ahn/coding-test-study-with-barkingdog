#include <bits/stdc++.h>
using namespace std;



int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    vector<vector<int>> accumul_board(board.size() + 1, vector<int>(board[0].size() + 1, 0));
    
    for (vector<int> sk : skill) {
        int type = sk[0];
        int r1 = sk[1], c1 = sk[2];
        int r2 = sk[3], c2 = sk[4];
        int degree;
        
        if (type == 2) degree = sk[5];
        else degree = -sk[5];
        
        accumul_board[r1][c1] += degree;
        accumul_board[r1][c2 + 1] -= degree;
        accumul_board[r2 + 1][c1] -= degree;
        accumul_board[r2 + 1][c2 + 1] += degree;
    }
    
    for (int i = 0; i < accumul_board.size() - 1; i++) {
        for (int j = 0; j < accumul_board[i].size(); j++) {
            accumul_board[i + 1][j] += accumul_board[i][j];
        }
    }
    
    for (int i = 0; i < accumul_board.size(); i++) {
        for (int j = 0; j < accumul_board[i].size() - 1; j++) {
            accumul_board[i][j + 1] += accumul_board[i][j];
        }
    }
    
    
    
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            
            if (board[i][j] + accumul_board[i][j] > 0) answer++;
        }
    }
    
    
    return answer;
}