#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0, 1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1, 0, 1, 0, -1};
bool isVisited[4][4][131072];

// isVisited도 각 
int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;
    
    
    // 초기위치, 초기상태, 선택된 캐릭터(없으면0), 조작한 횟수
    queue<pair<pair<pair<x, y>, int>, pair<int, int>>> q;
    q.push({{{r, c}, 1}, {board[r][c], 0}});
    isVisited[r][c][1] = true;
    
    int count = 0;
    
    vector<pair<int, int>> arr[10];
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] != 0) {
                count++;
                arr[board[i][j]].push_back({i, j});
            }
        }
    }
    
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        pair<int> cur = p.first.first;
        int curState = p.first.second;
        int selectedChar = p.second.first;
        int moveCount = p.second.second;
        
        for (int i = 0; i < 8; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if (i < 4) {            
                // 보드 밖이면 패스
                if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
                
                // 다른 캐릭터에 도달했으면 패스
                if (selectedChar != 0 && board[nx][ny] != selectedChar) continue;
                
                // 이미 도달했었던 위치-상태면 패스
                if (isVisited[nx][ny][curState & (4 * nx + ny)]) continue;
                
                // 가도 된다.
                else {
                    int newState = curState & (4 * nx + ny);
                    isVisited[nx][ny][newState] = true;
                    
                    // 캐릭터 지정이 안된 상태였을 때
                    if (selectedChar == 0) {
                        // 해당 지점 값을 선택하고 push
                        q.push({{{nx, ny}, newState}, {board[nx][ny], moveCount + 1}});
                    }
                    
                    // 캐릭터 지정이 된 상태였을 때
                    else {
                        // 해당 지점과 같은 캐릭터면 count -= 2 하고 캐릭터 지우기
                        if (selectedChar == board[nx][ny]) {
                            for (int i = 0; i < arr[selectedChar].size(); i++) {
                                auto p = arr[selectedChar][i];
                                board[p.first][p.second] = 0;
                            }    
                            count -= 2;
                            
                            // q에 넣기
                            q.push({{{nx, ny}, newState, {0, moveCount + 2}}});
                        }
                    }
                }
            }
            
            else {
                // 해당 위치가 벽이 아니거나 캐릭터가 아니면 계속 이동
                while (!((nx == 0 && (0 <= ny && ny < 4)) || ((0 <= nx && nx < 4) && ny == 3) || (nx == 3 && (0 <= ny && ny < 4) || (0 <= nx && nx < 4) && ny == 0)) || board[nx][ny] == 0) {
                    nx += dx[i];
                    ny += dy[i];
                }
                
                // 일단 상태 체크
                if (isVisited[nx][ny][curState & (4 * nx + ny)]) continue;
                
                // 밟은 땅의 값이 0일 때
                if (board[nx][ny] == 0) {
                    // 움직인 횟수만 증가시키고 다시 넣으면 된다.
                    int newState = curState & (4 * nx + ny);
                    isVisited[nx][ny][newState] = true;
                    q.push({{{nx, ny}, newState, {selectedChar, moveCount + 1}}})
                }
                // 밟은 땅의 값이 0이 아닐 때
                else {
                    // 지금 내가 가지고 있는 값과 같으면 count 빼고 board에서 지우고 q에 넣기
                    if (selectedChar == board[nx][ny]) {
                        for (int i = 0; i < arr[selectedChar].size(); i++) {
                                auto p = arr[selectedChar][i];
                                board[p.first][p.second] = 0;
                            }    
                        count -= 2;
                        q.push({{{nx, ny}, newState, {0, moveCount + 2}}});
                    }
                }
            }
        }
    }
    return answer;
}