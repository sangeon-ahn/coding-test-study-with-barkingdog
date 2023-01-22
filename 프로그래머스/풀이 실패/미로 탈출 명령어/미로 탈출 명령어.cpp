#include <bits/stdc++.h>
using namespace std;
// 테스트케이스는 맞지만 제출시 시간초과
int board[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string compare(string s1, string s2) {
  if (s1.size() == 0) {
    return s2;
  }

  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] - s2[i] == 0) continue;
    return s1[i] - s2[i] > 0 ? s2 : s1;
  }
}

bool alreadyFalse(string s1, string s2) {
  if (s1.size() == 0) return false;
  for (int i = 0; i < s2.size(); i++) {
    if (s2[i] - s1[i] == 0) continue;
    if (s2[i] - s1[i] > 0) return true;
    if (s2[i] - s1[i] < 0) return false;
  }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    board[r][c] = 1;

    queue<pair<pair<int, int>, pair<int, string>>> q;
    q.push({{x, y}, {0, ""}});
    string dir[4] = {"d", "r", "u", "l"};

    while (!q.empty()) {
      auto p = q.front(); q.pop();
      int x = p.first.first;
      int y = p.first.second;

      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if (p.second.first + 1 > k) continue;

        string new_str = p.second.second + dir[i];
        if (alreadyFalse(answer, new_str)) continue;
        if (p.second.first + 1 == k) {
          if (board[nx][ny] == 1) {
            answer = compare(answer, new_str);
          }
        }
        else {
          q.push({{nx, ny}, {p.second.first + 1, new_str}});
        }
      }
    }

    return answer.size() == 0 ? "impossible" : answer;
}

int main() {
  string ans = solution(3, 4, 2, 3, 3, 1, 5);
  cout << ans;
}