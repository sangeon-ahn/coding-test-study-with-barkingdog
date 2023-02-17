#include <bits/stdc++.h>
using namespace std;

vector<string> split(string str, char delimiter) {
  string tmp;
  stringstream st(str);
  vector<string> result;

  while (getline(st, tmp, delimiter)) {
    result.push_back(tmp);
  }

  return result;
}


string board[51][51];
int sector[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    // 구역을 나눠준다
    for (int i = 1; i <= 50; i++) {
      for (int j = 1; j <= 50; j++) {
        sector[i][j] = 50 * i + j;
      }
    }

    // 명령어를 받는다.
    for (int i = 0; i < commands.size(); i++) {
      string cmd = commands[i];
      auto splited = split(cmd, ' ');
      
      // update인 경우.
      // 셀을 골라서 바꾸는 경우
      if (splited[0] == "UPDATE") {
        if (splited.size() == 4) {
          int r = stoi(splited[1]);
          int c = stoi(splited[2]);
          string s = splited[3];

          queue<pair<int, int>> q;
          int vis[51][51] = {0, };
          q.push({r, c});
          vis[r][c] = 1;

          while(!q.empty()) {
            auto p = q.front(); q.pop();
            
            board[p.first][p.second] = s;

            for (int i = 0; i < 4; i++) {
              int nr = p.first + dx[i];
              int nc = p.second + dy[i];

              if (nr <= 0 || nr > 50 || nc <= 0 || nc > 50) continue;
              if (vis[nr][nc] == 1) continue;
              if (sector[nr][nc] != sector[p.first][p.second]) continue;
              vis[nr][nc] = 1;
              q.push({nr, nc});
            }
          }
        }

        else if (splited.size() == 3) {
          string a = splited[1];
          string b = splited[2];

          for (int i = 1; i <= 50; i++) {
            for (int j = 1; j <= 50; j++) {
              if (board[i][j] == a) {
                board[i][j] = b;
              }
            }
          }
        }
      }
      // merge인 경우.
      if (splited[0] == "MERGE") {
        int r1 = stoi(splited[1]);
        int c1 = stoi(splited[2]);
        int r2 = stoi(splited[3]);
        int c2 = stoi(splited[4]);

        string s1 = board[r1][c1];
        string s2 = board[r2][c2];
        
        int sector1 = sector[r1][c1];
        int sector2 = sector[r2][c2];

        string stdString = s1;
        if (s1.size() == 0 && s2.size() != 0) {
          stdString = s2;
        }

        queue<pair<int, int>> q;
        int vis[51][51] = {0, };
        q.push({r1, c1});
        vis[r1][c1] = 1;
        board[]
        while (!q.empty()) {
          auto p = q.front(); q.pop();

          board[p.first][p.second] = stdString;
          
          for (int i = 0; i < 4; i++) {
            int nr = p.first + dx[i];
            int nc = p.second + dy[i];

            if (nr <= 0 || nr > 50 || nc <= 0 || nc > 50) continue;
            if (vis[nr][nc] == 1) continue;
            // r2, c2와 섹터가 같은 곳에 한해서 섹터와 값 바꿔주기.
            if (sector[nr][nc] == sector[r2][c2]) {
              sector[nr][nc] = sector[r1][c1];
              board[nr][nc] = board[r1][c1];

              // 방문체크 후 넣어주기.
              vis[nr][nc] = 1;
              q.push({nr, nc});
            }
          }
        }

        
        
      }
      // unmerge인 경우

      // print인 경우.
    }
    return answer;
}

int main() {
  solution({"UPDATE 1 1 menu", "UPDATE 1 2 category", "UPDATE 2 1 bibimbap", "UPDATE 2 2 korean", "UPDATE 2 3 rice", "UPDATE 3 1 ramyeon", "UPDATE 3 2 korean", "UPDATE 3 3 noodle", "UPDATE 3 4 instant", "UPDATE 4 1 pasta", "UPDATE 4 2 italian", "UPDATE 4 3 noodle", "MERGE 1 2 1 3", "MERGE 1 3 1 4", "UPDATE korean hansik", "UPDATE 1 3 group", "UNMERGE 1 4", "PRINT 1 3", "PRINT 1 4"});
}