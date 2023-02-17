#include <bits/stdc++.h>
// 테스트 케이스 통과, 제출 50% 통과
using namespace std;
string board[51][51];
// 머지를 저장해야함
// 1. 맵에 셋 넣기
map<int, string> M;
int group[51][51];
int groupCount = 1;
/*
    일단 그룹에 속해 있는지를 파악한 후, 속해 있으면 그룹값을 update, print, merge한다.
    그룹값은 map으로 파악하며, map<int, string> M;으로 수정한다. 이후 merge를 할 때 앞쪽 셀이 그룹에 속해 있는지 확인 후 속해 있으면 해당 그룹값을 다음 셀 or 그룹의 그룹값으로 바꾼다.
    이때 그룹과 그룹이 합쳐질 경우, 뒤 그룹에 속하는 모든 셀의 그룹을 새로운 그룹으로 바꿔준다.
*/

// 문자열 delimiter로 나누기.
vector<string> split(string str, char delimiter) {
  string tmp;
  stringstream st(str);
  vector<string> result;

  while (getline(st, tmp, delimiter)) {
    result.push_back(tmp);
  }

  return result;
}

vector<string> solution(vector<string> commands) {
  vector<string> answer;
    
  // 커맨드 1개씩 실행
  for (int i = 0; i < commands.size(); i++) {
        vector<string> command = split(commands[i], ' ');
        
        // update인 경우
        if (command[0] == "UPDATE") {
            // command.size() == 4인 경우
            if (command.size() == 4) {
                int x = stoi(command[1]);
                int y = stoi(command[2]);
                string value = command[3];
                
                // 그룹이 있는 경우.
                if (group[x][y] != 0) {
                    // 해당 그룹의 값을 update 해준다.
                    M[group[x][y]] = value;
                }
                // 그룹이 없으면 해당 셀 값 갱신
                else {
                    board[x][y] = value;
                }
            }
            
            // command.size() == 3인 경우
            else if (command.size() == 3) {
                // 그룹 중 해당 값이 있으면 update
                for (auto it = M.begin(); it != M.end(); it++) {
                    if (it->second == command[1]) {
                        it->second = command[2];
                    }
                }
                // 셀 중 해당 값이 있으면 update
                for (int i = 1; i <= 50; i++) {
                    for (int j = 1; j <= 50; j++) {
                        if (group[i][j] == 0 && board[i][j] == command[1]) {
                            board[i][j] = command[2];
                        }
                    }
                }
            }
        }
        
        // merge인 경우
        else if (command[0] == "MERGE") {
            int r1 = stoi(command[1]);
            int c1 = stoi(command[2]);
            int r2 = stoi(command[3]);
            int c2 = stoi(command[4]);
            
            // 같은 셀인 경우 무시
            if (r1 == r2 && c1 == c2) continue;
            
            // r1, c1이 그룹에 속한 경우
            if (group[r1][c1] != 0) {
                // r2, c2가 그룹에 속하지 않은 경우
                if (group[r2][c2] == 0) {
                    // board[r2][c2] = M[group[r1][c1]];
                    group[r2][c2] = group[r1][c1];
                    board[r2][c2] = "";
                } 
                // r2, c2가 그룹에 속한 경우
                else {
                    // r2, c2 그룹 삭제
                    // M[group[r2][c2]] = M[group[r1][c1]];
                    M.erase(group[r2][c2]);
                    
                    // r2, c2가 속한 그룹의 셀들의 그룹을 갱신
                    for (int i = 1; i <= 50; i++) {
                        for (int j = 1; j <= 50; j++) {
                            if (group[r2][c2] == group[i][j]) {
                                group[i][j] = group[r1][c1];
                            }
                        }
                    }
                } 
            }
            
            // 그룹에 속하지 않은 경우
            else {
                // r2, c2가 그룹에 속한 경우
                if (group[r2][c2] != 0) {
                    // r1, c1을 해당 그룹에 넣고, 그룹값을 바꾼다.
                    group[r1][c1] = group[r2][c2];
                    M[group[r2][c2]] = board[r1][c1];
                    board[r1][c1] = "";
                }
                // r2, c2도 그룹에 속하지 않은 경우
                else {
                    // r1, c1에 값이 있으면 무조건 r1, c1의 값으로 갱신
                    if (!board[r1][c1].empty()) {
                        group[r1][c1] = groupCount;
                        group[r2][c2] = groupCount;
                        
                        M[group[r1][c1]] = board[r1][c1];
                        board[r2][c2] = "";
                        groupCount++;
                    } 
                    // r1, c1에는 없고 r2, c2에만 있으면 r2, c2로 갱신
                    else if (!board[r2][c2].empty()) {
                        group[r1][c1] = groupCount;
                        group[r2][c2] = groupCount;
                        
                        M[group[r1][c1]] = board[r2][c2];
                        groupCount++;
                    }
                }
            }
        } 
        // unmerge인 경우
        else if (command[0] == "UNMERGE") {
            int x = stoi(command[1]);
            int y = stoi(command[2]);
            
            int group_id = group[x][y];
            
            // 그룹을 없앤다.
            if (group_id != 0) {
              // 해당 그룹에 속한 셀의 값을 전부 ""로 초기화하고, (x,y)에 그룹값을 넣는다.
              for (int i = 1; i <= 50; i++) {
                for (int j = 1; j <= 50; j++) {
                  if (group[i][j] == group_id) {
                    board[i][j] = "";
                    group[i][j] = 0;
                  }
                }
              }
              board[x][y] = M[group_id];
              M.erase(group_id);
              group[x][y] = 0;
            }
        }
        
        // print인 경우
        else if (command[0] == "PRINT") {
            int x = stoi(command[1]);
            int y = stoi(command[2]);
            
            // 그룹에 속한 경우
            if (group[x][y]) {
                answer.push_back(M[group[x][y]]);
            }
            
            // 셀인 경우    
            else if (!board[x][y].empty()) {
                answer.push_back(board[x][y]);
            }
            
            // 값이 없는 경우
            else {
                answer.push_back("EMPTY");
            }
        }
    }
  return answer;
}
    
    
