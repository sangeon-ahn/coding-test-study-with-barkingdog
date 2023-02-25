#include <bits/stdc++.h>

using namespace std;
/*
    유니온 결합, 유니온 파인드 이용
*/
// 틀림 => =을 ==으로 잘못 쓴 부분 고치니까 정답
vector<string> split(string str, char delimiter) {
    stringstream ss(str);
    string temp;
    vector<string> result;
    
    while (getline(ss, temp, delimiter)) {
        result.push_back(temp);
    }
    
    return result;
}

string board[51][51]; // (1, 1) 부터 시작
pair<int, int> uf[51][51];

pair<int, int> uf_find(int x, int y) {
    if (uf[x][y].first == 0 && uf[x][y].second == 0) return {x, y};
    else {
        uf[x][y] = uf_find(uf[x][y].first, uf[x][y].second);
        return uf[x][y];
    }
}

void uf_union(int x1, int y1, int x2, int y2) {
    auto p1 = uf_find(x1, y1);
    auto p2 = uf_find(x2, y2);
    
    if (p1 == p2) return;
    if (board[p1.first][p1.second].empty() && board[p2.first][p2.second].size()) uf[p1.first][p1.second] = p2;
    
    else uf[p2.first][p2.second] = p1;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    for (string command : commands) {
        vector<string> cmd = split(command, ' ');
        
        if (cmd[0] == "UPDATE") {
            if (cmd.size() == 4) {
                // uf_find로 최고 조상 찾아서 값 변경
                int x = stoi(cmd[1]), y = stoi(cmd[2]);
                string value = cmd[3];
                pair<int, int> np = uf_find(x, y);
                
                board[np.first][np.second] = value;
            }
            else if (cmd.size() == 3) {
                string val1 = cmd[1], val2 = cmd[2];
                // update val1 val2 => val1를 val2로 업데이트한다.
                for (int i = 1; i <= 50; i++) {
                    for (int j = 1; j <= 50; j++) {
                        auto p = uf_find(i, j);
                        if (board[p.first][p.second] == val1) {
                            board[p.first][p.second] = val2;
                        } 
                    }
                }
            }
        }
        else if (cmd[0] == "MERGE") {
            // merge x1 y1 x2 y2 => x2, y2가 x1, y1에 머지된다.
            // x1, y1의 조상을 x2, y2의 조상으로 바꾸고 x2,y2 값 없애기
            // uf_union으로 결합. uf 업데이트
            uf_union(stoi(cmd[1]), stoi(cmd[2]), stoi(cmd[3]), stoi(cmd[4]));
        }
        else if (cmd[0] == "UNMERGE") {
            // uf_find 해서 조상 찾고 이 셀을 조상으로 가지는 셀들을 전부 초기화
            auto p = uf_find(stoi(cmd[1]), stoi(cmd[2]));
            string val = board[p.first][p.second];
            
            for (int i = 1; i <= 50; i++) {
                for (int j = 1; j <= 50; j++) {
                    uf_find(i, j);
                }
            }
            
            for (int i = 1; i <= 50; i++) {
                for (int j = 1; j <= 50; j++) {
                    auto pp = uf_find(i, j);
                    if (pp.first == p.first && pp.second == p.second) {
                        board[i][j] = "";
                        uf[i][j] = {0, 0};
                    }
                }
            }
            board[stoi(cmd[1])][stoi(cmd[2])] = val;
        }
        else {
            // 해당 셀의 조상을 찾아서 값을 answer에 넣기 
            auto p = uf_find(stoi(cmd[1]), stoi(cmd[2]));
            if (board[p.first][p.second].empty()) answer.push_back("EMPTY");
            else answer.push_back(board[p.first][p.second]);
        }
    }
    
    return answer;
}