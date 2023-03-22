#include <bits/stdc++.h>
using namespace std;
// 커서가 다른 캐릭터로 이동했더라도 엔터를 누르지 않으면 이동이 허용된다는걸 알았다.
// 커서 이동 역할
// 기존의 캐릭과 같으면 뒤집고 아니면 다시 커서 이동

int dx[8] = {1, 0, -1, 0, 1, 0, -1, 0};
int dy[8] = {0, 1, 0, -1, 0, 1, 0, -1};

// 현재 위치, 선택된 캐릭의 위치, 잡은 캐릭터들
bool isVisited[4][4][5][5][1<<6];
// bool isVisited[1][1][132][5][5][1<<6];

struct Elem {
    pair<int, int> pos;
    // int state;
    pair<int, int> character;
    int moveCount;
    int killedCount;
    vector<vector<int>> board;
    vector<pair<int, int>> histories;
    int killState;
};

pair<pair<int, int>, bool> getNextPos(Elem elem, int dir) {
    if (dir < 4) {
        int nx = elem.pos.first + dx[dir];
        int ny = elem.pos.second + dy[dir];

        // 벽이 아닌 이상 다 갈 수 있음.
        if (nx < 0 || nx > 3 || ny < 0 || ny > 3) return {{-1, -1}, false};

        return {{nx, ny}, true};
    }
    // 4~7구간은 다음이 벽이거나 캐릭터일 때까지 갈 수 있음.
    else {
        int x = elem.pos.first;
        int y = elem.pos.second;
        
        while (true) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            
            // 다음이 벽이면 현재 위치 반환
            if (dir == 4 && nx > 3) {
              return {{x, y}, true};
            }
      
            // 다음이 오른쪽 벽이면 현재 위치 반환.
            else if (dir == 5 && ny > 3) {
                return {{x, y}, true};
            }
            // 다음이 위쪽 벽이면 현재 위치 반환.
            else if (dir == 6 && nx < 0) {
                return {{x, y}, true};
            }
            // 다음이 왼쪽 벽이면 현재 위치 반환.
            else if (dir == 7 && ny < 0) {
                return {{x, y}, true};
            }
            
            // 다음이 캐릭터면 해당 캐릭터 위치 반환
            else if (elem.board[nx][ny] != 0) return {{nx, ny}, true};

            // 0이면 이동
            else if (elem.board[nx][ny] == 0) {
              x = nx, y = ny;
            }
        }
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0x7f7f7f7f;

    Elem elem;
    elem.pos = {r, c};
    // elem.state = 1 << (4 * r + c);
    elem.character = {4, 4};
    elem.killedCount = 0;
    elem.board = board;
    elem.moveCount = 0;
    elem.histories = {{r, c}};
    elem.killState = 0;

    if (board[r][c] != 0) {
        elem.moveCount = 1;
        elem.character = {r, c};
        isVisited[r][c][r][c][0] = true;
    }
    else isVisited[r][c][4][4][0] = true;

    queue<Elem> q;
    q.push(elem);

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

        pair<int, int> cur = p.pos;
        pair<int, int> selectedChar = p.character;
        vector<vector<int>> myBoard = p.board;
        // int curState = p.state;
        int moveCount = p.moveCount;
        int killedCount = p.killedCount;
        vector<pair<int, int>> histories = p.histories;
        int killState = p.killState;

        // if (killedCount == count && moveCount <= 10) {
        //     cout << "MC: " << moveCount << ' ' << "STATE: " << curState << '\n';
        //     for (int i = 0; i < histories.size(); i++) {
        //         cout << histories[i].first << ' ' << histories[i].second << '\n';
        //     }
        //     cout << '\n';
        // }
        if (killedCount == count) {
            answer = min(answer, moveCount);
            continue;
        }

        for (int i = 0; i < 8; i++) {
            pair<pair<int, int>, bool> nPos = getNextPos(p, i);
            // if (cur.first == 0 && cur.second == 0 && nPos.first.first == 3 && nPos.first.second == 0 && moveCount == 7 && killedCount == 2 && selectedChar.first == 0 && selectedChar.second == 3) {
            //     cout << "===\n";
            //     for (int i = 0; i < histories.size(); i++) {
            //         cout << histories[i].first << ' ' << histories[i].second << '\n';
            //     }
            //     cout << "canGo: " << nPos.second << '\n';
            //     cout << "nextPos: " << nPos.first.first << "," << nPos.first.second << '\n';
            //     cout << "state: " << curState << '\n'; 
            //     cout << "===\n";
            // }
            if (nPos.second == false) continue;

            int nx = nPos.first.first;
            int ny = nPos.first.second;



            // int newState = curState | (1 << (4 * nx + ny));
            if (isVisited[nx][ny][selectedChar.first][selectedChar.second][killState]) continue;
            // if (cur.first == 0 && cur.second == 0 && nPos.first.first == 3 && nPos.first.second == 0 && moveCount == 7 && killedCount == 2 && selectedChar.first == 0 && selectedChar.second == 3) {
            //     cout << "===\n";
            //     for (int i = 0; i < histories.size(); i++) {
            //         cout << histories[i].first << ' ' << histories[i].second << '\n';
            //     }
            //     cout << "canGo: " << nPos.second << '\n';
            //     cout << "nextPos: " << nPos.first.first << "," << nPos.first.second << '\n';
            //     cout << "===\n";
            // }
            isVisited[nx][ny][selectedChar.first][selectedChar.second][killState] = true;

            Elem new_elem;
            new_elem.pos = {nx, ny};
            // new_elem.state = newState;
            new_elem.killState = killState;
            vector<pair<int, int>> tmpHistories = p.histories;
            tmpHistories.push_back({nx, ny});
            new_elem.histories = tmpHistories;
            // 아직 선택된 캐릭이 없을 때
            if (selectedChar.first == 4 && selectedChar.second == 4) {
                // 다음 위치에 캐릭이 있으면 선택
                if (myBoard[nx][ny] != 0) {
                    // if (nx == 0 && ny == 3 && moveCount == 4) cout << "MC: 4, HI\n";
                    new_elem.character = {nx, ny};
                    new_elem.moveCount = moveCount + 2;
                }
                // 캐릭 없으면 그냥 움직이기.
                else {
                    new_elem.character = {4, 4};
                    new_elem.moveCount = moveCount + 1;
                }
                // 킬카운트랑 보드 는 그대로
                new_elem.killedCount = killedCount;
                new_elem.board = myBoard;
                q.push(new_elem);
            }

            // 선택된 캐릭이 있을 때
            else {
                // if (cur.first == 0 && cur.second == 0 && nPos.first.first == 3 && nPos.first.second == 0 && moveCount == 7 && killedCount == 2 && selectedChar.first == 0 && selectedChar.second == 3) {
                //     cout << "record start.\n";
                //     for (int i = 0; i < histories.size(); i++) {
                //         cout << histories[i].first << ' ' << histories[i].second << '\n';
                //     }
                //     cout << "record end\n";
                //     cout << "---\n";
                //     cout << selectedChar.first << ' ' << selectedChar.second << '\n';
                //     cout << nx << ' ' << ny << '\n';
                //     cout << "---\n";
                // };
                // 나랑 같은 캐릭 만난경우
                if (myBoard[selectedChar.first][selectedChar.second] == myBoard[nx][ny]) {
                    // 나랑 다른 칸이면 삭제(x,y중 하나라도 다르면 다른 칸이다.)
                    if (selectedChar.first != nx || selectedChar.second != ny) {
                        vector<vector<int>> temp = myBoard;
                        for (int i = 0; i < arr[myBoard[selectedChar.first][selectedChar.second]].size(); i++) {
                            auto p = arr[myBoard[selectedChar.first][selectedChar.second]][i];
                            temp[p.first][p.second] = 0;
                        }

                        // if (nx == 3 && ny == 3 && moveCount == 2) {
                        //     for (int i = 0; i < temp.size(); i++) {
                        //         for (int j = 0; j < temp[i].size(); j++) {
                        //             cout << temp[i][j] << ' ';
                        //         }
                        //         cout << '\n';
                        //     }
                        // }
                        // 보드에서 해당 캐릭터 지우기
                        new_elem.board = temp;

                        new_elem.moveCount = moveCount + 2;
                        new_elem.killedCount = killedCount + 2;
                        // if (nx == 3 && ny == 3 && moveCount == 2) {
                        //     cout << "MC: " << new_elem.moveCount << "KC: " << new_elem.killedCount << '\n';
                        // }

                        // 킬스테이트 갱신.
                        new_elem.killState = killState | (1 << myBoard[nx][ny]);
                        // 잡았으므로 다시 아무것도 선택 안한상태로 복구
                        new_elem.character = {4, 4};
                        q.push(new_elem);
                    }
                    // 같은 칸이면 패스
                    else continue;

                }

                // 그 외의 경우는 그냥 이동
                else {
                    // if (nx == 0 && ny == 0 && moveCount == 6 && killedCount == 2) {
                    //     for (int i = 0; i < histories.size(); i++) {
                    //         cout << histories[i].first << ' ' << histories[i].second << '\n';
                    //     }
                    //     cout << '\n';
                    // }
                    new_elem.moveCount = moveCount + 1;
                    new_elem.killedCount = killedCount;
                    new_elem.character = selectedChar;
                    new_elem.board = myBoard;

                    q.push(new_elem);
                }
            }
        }
    }
    return answer;
}


int main() {
    vector<vector<int>> board = {{1, 0, 0, 2}, {0, 0, 3, 0}, {0, 3, 0, 0}, {2, 0, 0, 1}};
    int r = 1, c = 0;
    
    int ans = solution(board, r, c);
    cout << ans;
}
