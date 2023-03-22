// 커서가 다른 캐릭터로 이동했더라도 엔터를 누르지 않으면 이동이 허용된다는걸 알았다.
#include <bits/stdc++.h>
using namespace std;
// 커서 이동 역할
// 기존의 캐릭과 같으면 뒤집고 아니면 다시 커서 이동

int dx[8] = {1, 0, -1, 0, 1, 0, -1, 0};
int dy[8] = {0, 1, 0, -1, 0, 1, 0, -1};
int isVisited[4][4][131072];

struct Elem {
    pair<int, int> pos;
    int state;
    pair<int, int> character;
    int moveCount;
    int killedCount;
    vector<vector<int>> board;
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
            if (nx < 0 || nx > 3 || ny < 0 || ny > 3) return {{x, y}, true};

            // 다음이 캐릭터면 해당 캐릭터 위치 반환
            if (elem.board[nx][ny] != 0) return {{nx, ny}, true};

            // 벽도 아니고 캐릭터도 아니면 이동
            x = nx, y = ny;
        }
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0x7f7f7f7f;

    Elem elem;
    elem.pos = {r, c};
    elem.state = 1 << (4 * r + c);
    elem.character = {-1, -1};
    elem.killedCount = 0;
    elem.board = board;
    elem.moveCount = 0;

    if (board[r][c] != 0) {
        elem.moveCount = 1;
        elem.character = {r, c};
    }
    isVisited[r][c][1 << (4 * r + c)] = true;

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
        int curState = p.state;
        int moveCount = p.moveCount;
        int killedCount = p.killedCount;

        cout << killedCount << ' ';

        if (killedCount == count) {
            if (answer > moveCount) {
                answer = moveCount;
            }
            continue;
        }

        for (int i = 0; i < 8; i++) {
            pair<pair<int, int>, bool> nPos = getNextPos(p, i);
            if (nPos.second == false) continue;

            int nx = nPos.first.first;
            int ny = nPos.first.second;

            int newState = curState | (1 << (4 * nx + ny));

            if (isVisited[nx][ny][newState]) continue;
            isVisited[nx][ny][newState] = true;

            Elem new_elem;
            new_elem.pos = {nx, ny};
            new_elem.state = newState;

            // 아직 선택된 캐릭이 없을 때
            if (selectedChar.first == -1 && selectedChar.second == -1) {
                if (myBoard[nx][ny] != 0) {
                    new_elem.character = {nx, ny};
                    new_elem.moveCount = moveCount + 2;
                }
                else {
                    new_elem.character = {-1, -1};
                    new_elem.moveCount = moveCount + 1;
                }
                new_elem.killedCount = killedCount;
                new_elem.board = myBoard;
                q.push(new_elem);
            }

            // 선택된 캐릭이 있을 때
            else {
  
                // 나랑 같은 캐릭 만난경우
                if (myBoard[selectedChar.first][selectedChar.second] == myBoard[nx][ny]) {
                    // 나랑 다른 칸이면 삭제
                    if (selectedChar.first != nx || selectedChar.second != ny) {
                        vector<vector<int>> temp = myBoard;

                        for (int i = 0; i < arr[myBoard[selectedChar.first][selectedChar.second]].size(); i++) {
                            auto p = arr[myBoard[selectedChar.first][selectedChar.second]][i];
                            temp[p.first][p.second] = 0;
                        }

                        new_elem.board = temp;

                        new_elem.moveCount = moveCount + 2;
                        new_elem.killedCount = killedCount + 2;
                        new_elem.character = {-1, -1};
                        q.push(new_elem);
                    }
                    // 같은 칸이면 패스
                    else continue;
                }

                // 0 만났으면 그냥 이동
                else if (myBoard[nx][ny] == 0) {
                    new_elem.moveCount = moveCount + 1;
                    new_elem.killedCount = killedCount;
                    new_elem.character = selectedChar;
                    new_elem.board = myBoard;

                    q.push(new_elem);
                }

                // // 다른 캐릭 만났으면 그냥 이동
                // else if (myBoard[nx][ny] != myBoard[selectedChar.first][selectedChar.second]) {
                //     new_elem.moveCount = moveCount + 1;
                //     new_elem.killedCount = killedCount;
                //     new_elem.character = selectedChar;
                //     new_elem.board = myBoard;

                //     q.push(new_elem);
                // }
            }
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> board = {{3, 0, 0, 2}, {0, 0, 1, 0}, {0, 1, 0, 0}, {2, 0, 0, 3}};
    int r = 0, c = 1;
    int ans = solution(board, r, c);
    cout << ans - 1;
}