#include <bits/stdc++.h>
using namespace std;
/*
    민맥스 알고리즘 사용.
    우선 for문 돌려서 새로운 위치로 a가 이동하고, a가 이동한 후 b에 대한 solve를 호출해서 결과를 받는다.
    결과가 b의 승리면 최대값 lose_count 갱신, a의 승리면 최솟값 win_count 갱신
    for문 끝나고 나서 a가 한번이라도 이겼으면 win_count를 사용.
    모두 졌으면 lost_count 사용
*/


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

pair<int, int> solve(vector<vector<int>> board, vector<int> a, vector<int> b) {
    int x0 = a[0];
    int y0 = a[1];
    
    int win_case = 0x7f7f7f7f, lose_case = 0;
    bool can_move = false;
    
    for (int i = 0; i < 4; i++) {
        int nx = x0 + dx[i];
        int ny = y0 + dy[i];
        
        if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size()) continue;
        
        if (board[nx][ny] == 0) continue;
        
        can_move = true;
        
        if (b[0] == x0 && b[1] == y0) {
            return {1, 1};
        }
        
        board[x0][y0] = 0;
        a[0] = nx;
        a[1] = ny;
        
        auto b_result = solve(board, b, a);
        
        // 되돌리기
        a[0] = x0;
        a[1] = y0;
        board[x0][y0] = 1;
        
        // b가 이겼으면 a가 졌으니까 제일 늦게 지도록
        if (b_result.first == 1) {
            lose_case = max(lose_case, b_result.second);
        }
        
        // a가 이겼으면 제일 일찍 이기도록
        else {
            win_case = min(win_case, b_result.second);
        }
    }
    
    if (can_move == false) {
        return {0, 0};
    }
    
    if (win_case != 0x7f7f7f7f) {
        return {1, win_case + 1};
    }
    else {
        return {0, lose_case + 1};
    }
}
int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    return solve(board, aloc, bloc).second;
}