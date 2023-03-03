#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct state {
    pair<int, int> a;
    pair<int, int> b;
    int count;
    int turn;
    vector<vector<bool>> isVisited;
};

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer = 0;

    queue<state> q;
    vector<vector<bool>> v(5, vector<bool>(5, false));
    q.push({{aloc[0], aloc[1]}, {bloc[0], bloc[1]}, 0, 0, v});
    
    while (!q.empty()) {
        state p = q.front(); q.pop();
        auto [ax, ay] = p.a;
        auto [bx, by] = p.b;
        int count = p.count;
        int turn = p.turn;
        
        
        answer = max(answer, count);
        
        for (int i = 0; i < 4; i++) {
            vector<vector<bool>> isvisited = p.isVisited;
            // a턴 -> a를 움직임
            if (turn == 0) {
                int nax = ax + dx[i];
                int nay = ay + dy[i];
                
                // 보드 밖이면 패스.
                if (nax < 0 || nax >= board.size() || nay < 0 || nay >= board[0].size()) continue;
                
                // 이미 방문한 곳이면 패스.
                if (isvisited[nax][nay]) continue;
                
                // 원래 보드값이 0이면 패스.
                if (board[nax][nay] == 0) continue;      
                
                isvisited[ax][ay] = true;
                
                // 다음칸 가려는데 a랑 b랑 같은 곳에 있었으면 게임 끝
                if (ax == bx && ay == by) {
                    answer = max(answer, count + 1);
                    continue;
                }
                
                q.push({{nax, nay}, {bx, by}, count + 1, 1, isvisited});
            }
            
            // b턴
            else {
                int nbx = bx + dx[i];
                int nby = by + dy[i];
                
                // 보드 밖이면 패스.
                if (nbx < 0 || nbx >= board.size() || nby < 0 || nby >= board[0].size()) continue;
                
                // 이미 방문한 곳이면 패스.
                if (isvisited[nbx][nby]) continue;
                
                // 원래 보드값이 0이면 패스.
                if (board[nbx][nby] == 0) continue;      
                
                isvisited[bx][by] = true;
                
                // a랑 b가 같은 곳에 있었으면 게임 끝
                if (bx == ax && by == ay) {
                    answer = max(answer, count + 1);
                    continue;
                }
                
                q.push({{ax, ay}, {nbx, nby}, count + 1, 0, isvisited});
            }
        }
    }
    return answer;
}