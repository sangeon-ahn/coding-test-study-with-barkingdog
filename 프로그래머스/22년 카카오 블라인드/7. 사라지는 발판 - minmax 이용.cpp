#include <vector>
#include <utility>

using namespace std;

// 상하좌우
const pair<int,int> dps[] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

// a가 움직일 차례
// @return [a승리여부, 가장 빠르게 이기는 이동횟수/가장 느리게 지는 이동횟수]
pair<int,int> solve(vector<vector<int>> &board, vector<int> &a, vector<int> &b )
{
    const int y0 = a[0];
    const int x0 = a[1];
    int win_case = 99999, loose_case=0;
    bool can_move = false;
    for( auto dp : dps ) {
        int x = x0 + dp.first;
        int y = y0 + dp.second;
        if( x<0 || x>=board[0].size() || y<0 || y>=board.size() ){ continue; }
        if( board[y][x] == 0 ){ continue; }
        can_move = true;
        // a가 (x0,y0) -> (x,y) 로 움직임

        // 만약 b가 (x0,y0)에 서있었다면 a승  -->  한번 이동으로 이길수있고 이게 최소 이동횟수임.
        if( b[0]==y0 && b[1]==x0 ){ return {1,1}; }

        board[y0][x0] = 0;
        a[0] = y;
        a[1] = x;
        // b가 움직일 차례
        auto r = solve(board,b,a);
        a[0] = y0;
        a[1] = x0;
        board[y0][x0] = 1;

        if( r.first )
        {
            // b가 이긴다면 턴이 가장 길어지도록
            loose_case = max(loose_case,r.second);
        }else
        {
            // a가 이길수있다면 턴이 가장 짧아지도록
            win_case = min(win_case,r.second);
        }

    }

    // 움직일곳이 없었으면 a패
    if( can_move == false )
    {
        return {0,0};
    }
    if( win_case != 99999 )
    {
        // a가 이기는 경우가 하나라도 있다면 그거 선택
        return {1,win_case+1};
    }else
    {
        return {0,loose_case+1};
    }
}
int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    return solve(board,aloc,bloc).second;
}