#include <bits/stdc++.h>
using namespace std;

int answer = 0;
vector<vector<int>> Board;
/*
  시간복잡도가 O(m*n*k)라서 효율성검사에서 실패.
  => 누적합으로 풀어야 함.
*/
void execute(int type, int r1, int c1, int r2, int c2, int degree) {
    // 공격
    if (type == 1) {
        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                Board[i][j] -= degree;
            }
        }
    }
    // 회복
    else {
        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                Board[i][j] += degree;
            }
        }
    }
}

int check() {
    int result = 0;
    for (int i = 0; i < Board.size(); i++) {
        for (int j = 0; j < Board[i].size(); j++) {
            if (Board[i][j] > 0) result++;
        }
    }
    return result;
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    Board = board;
    
    for (vector<int> sk: skill) {
        int type = sk[0];
        int r1 = sk[1], c1 = sk[2];
        int r2 = sk[3], c2 = sk[4];
        int degree = sk[5];
        
        execute(type, r1, c1, r2, c2, degree);
    }
    
    answer = check();
    
    return answer;
}