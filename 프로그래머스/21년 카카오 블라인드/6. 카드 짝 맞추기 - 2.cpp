#include <bits/stdc++.h>
using namespace std;
// 풀이실패
int dx[8] = {1, 0, -1, 0, 1, 0, -1, 0};
int dy[8] = {0, 1, 0, -1, 0, 1, 0, -1};
bool isVisited[4][4][131072];

struct Elem {
    pair<int, int> pos;
    int state;
    pair<int, int> character;
    int moveCount;
    int killedCount;
    vector<vector<int>> board;
};

pair<pair<int, int>, pair<bool, bool>> getNextPos(Elem elem, int dir) {
    if (dir < 4) {
        int nx = elem.pos.first + dx[dir];
        int ny = elem.pos.second + dy[dir];
        
        // 보드 밖이면 패스
        if (nx < 0 || nx > 3 || ny < 0 || ny > 3) return {{0, 0}, {false, false}};
        
        // 캐릭터 있는 상태. 
        if (elem.board[elem.character.first][elem.character.second] != 0) {
            // 다른 캐릭터 밟았으면 패스
            if (elem.board[nx][ny] != 0 && elem.board[nx][ny] != elem.board[elem.character.first][elem.character.second]) return {{0, 0}, {false, true}}; 
            // 나를 다시 밟았으면 패스
            if (elem.character.first == nx && elem.character.second == ny) return {{0, 0}, {false, false}};
        }
        
        // 그 외엔 제대로 반환
        return {{nx, ny}, {true, false}};
    }
    
    // 4~7은 ctrl 활성화
    else {
        // 우선 다음으로 갈 수 있는 상태인지를 체크한다.
        int nx = elem.pos.first + dx[dir];
        int ny = elem.pos.second + dy[dir];
        
        // 그냥 보드 밖이면 패스(원래는 자기를 반환해야 하지만 어차피 같은 위치이기 때문에
        // 같은 위치, 상태를 이전에 방문한 상태이고, 따라서 false로 리턴해줘도 똑같다.)
        if (nx < 0 || nx > 3 || ny < 0 || ny > 3) return {{-1, -1}, {false, false}};
        
        // 캐릭터 있는 상태. 
        if (elem.board[elem.character.first][elem.character.second] != 0) {
            // 계속 옆칸으로 가다가 다음칸이 벽이면 해당칸 리턴.
            // 계속 옆칸으로 가다가 다음칸이 나면 false 리턴.
            // 계속 옆칸으로 가다가 다음칸이 다른 캐릭터면 false 리턴.
            // 계속 옆칸으로 가다가 다음칸이 나랑 다른 위치의 같은 캐릭터면 해당칸 리턴.
            
            while (true) {
                int nnx = nx + dx[dir];
                int nny = ny + dy[dir];
                
                // 벽 만나면 리턴
                if (nnx < 0 || nnx > 3 || nny < 0 || nny > 3) return {{nx, ny}, {true, false}};
                
                // 같은 칸 캐릭터 만나면 패스
                if (nnx == elem.character.first && nny == elem.character.second) return {{-1, -1}, {false, false}};
                
                // 다른 캐릭터 만나면 패스
                if (elem.board[nnx][nny] != 0 && elem.board[nnx][nny] != elem.board[elem.character.first][elem.character.second]) return {{-1, -1}, {false, false}};
                
                // 같은 캐릭터 다른 칸 만나면 리턴
                if (elem.board[nnx][nny] == elem.board[elem.character.first][elem.character.second] && nnx != elem.character.first || nny != elem.character.second) return {{nnx, nny}, {true, true}};
                
                nx = nnx;
                ny = nny;
            }
        }
        
        // 캐릭터 없는 상태
        else {
            // 캐릭터가 없으면 다음칸이 벽이거나 캐릭터를 만날 때까지 가기
            while (true) {
                // 캐릭터를 만나면 리턴
                if (elem.board[nx][ny] != 0) return {{nx, ny}, {true, true}};
                
                int nnx = nx + dx[dir];
                int nny = ny + dy[dir];
                
                // 다음칸이 벽이면 리턴
                if (nnx < 0 || nnx > 3 || nny < 0 || nny > 3) return {{nx, ny}, {true, false}};
                
                // 그외엔 다음칸 진행
                nx = nnx;
                ny = nny;
            }
        }   
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0x3f3f3f3f;

    // 위치, 상태, 캐릭터, 움직인 횟수, 맞춘 캐릭 숫자, 보드
    queue<Elem> q;
    
    Elem elem;
    elem.pos = {r, c};
    elem.state = 1 << (4 * r + c);
    elem.character = {r, c};
    
    if (board[r][c] != 0) elem.moveCount = 1;
    elem.killedCount = 0;
    
    elem.board = board;
    
    q.push(elem);
    isVisited[r][c][1 << (4 * r + c)] = true;
    
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
        
        auto cur = p.pos;
        int curState = p.state;
        pair<int, int> selectedChar = p.character;
        int moveCount = p.moveCount;
        int killedCount = p.killedCount;
        vector<vector<int>> myBoard = p.board;
        
        // 다 잡았으면 답 갱신하고 패스.
        if (killedCount == count) {
            answer = min(answer, moveCount);
            continue;
        }
        else {
        }
        
        for (int i = 0; i < 8; i++) {
            pair<pair<int, int>, pair<bool, bool>> nPos = getNextPos(p, i);
            
            // 불가능하면 패스
            if (nPos.second.first == false) continue;
            
            int nx = nPos.first.first;
            int ny = nPos.first.second;
            
            // 이전에 도달했었던 (위치,상태)이면 패스
            if (isVisited[nx][ny][curState | 1 << (4 * nx + ny)]) continue;
            
            int newState = curState | (1 << (4 * nx + ny));
            isVisited[nx][ny][newState] = true;
            
            Elem new_elem;
            new_elem.pos = {nx, ny};
            new_elem.state = newState;
            
            // 캐릭터 지정이 안된 상태였을 때 
            if (board[selectedChar.first][selectedChar.second] == 0) {
                // 캐릭터를 밟았으면 뒤집기
                if (board[nx][ny] != 0) new_elem.moveCount = moveCount + 1;
                // 안밟았으면 그냥 가기
                else new_elem.moveCount = moveCount;
                
                new_elem.character = {nx, ny};
                new_elem.killedCount = killedCount;
                new_elem.board = myBoard;
                q.push(new_elem); 
            }
            
            // 캐릭터 지정이 된 상태였을 때
            else {
                // 해당 지점과 같은 캐릭터면 캐릭터 지우기
                if ((selectedChar.first != nx || selectedChar.second != ny) && board[selectedChar.first][selectedChar.second] == board[nx][ny]) {
                    // 보드에서 해당 캐릭터 지우기
                    vector<vector<int>> temp = myBoard;
                    
                    for (int i = 0; i < arr[board[selectedChar.first][selectedChar.second]].size(); i++) {
                        auto p = arr[board[selectedChar.first][selectedChar.second]][i];
                        temp[p.first][p.second] = 0;
                    }    

                    new_elem.board = temp;

                    // Enter 눌러야 하므로 moveCount += 1
                    new_elem.moveCount = moveCount + 2;
                    new_elem.killedCount = killedCount + 2;
                    new_elem.character = {nx, ny};
                    
                    // q에 넣기
                    q.push(new_elem);
                }
                // 0이면 그냥 넣기
                else if (board[nx][ny] == 0) {
                    new_elem.board = myBoard;
                    new_elem.moveCount = moveCount + 1;
                    new_elem.killedCount = killedCount;
                    new_elem.character = {nx, ny};
                    
                    // q에 넣기
                    q.push(new_elem);
                }
            }
        }
    }
    return answer;
}