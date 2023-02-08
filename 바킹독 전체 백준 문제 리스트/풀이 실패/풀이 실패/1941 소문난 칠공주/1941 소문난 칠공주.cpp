/*
  단순 bfs로 풀면 되는지 의문.
  시간복잡도: 2^10 * 25
*/

#include <bits/stdc++.h>
using namespace std;

char board[5][5];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool vis[5][5];
int ans;
vector<char> v;

bool check(vector<char> vec) {
  int result;

  for (char c : vec) {
    if (c == 'S') result++;
  }

  return result >= 4;
}

void dfs(int x, int y, int count) {
  if (count == 7) {
    // for (char c : v) {
    //   cout << c << ' ';
    // }
    // cout << '\n';
    // S가 4개 이상이면 true.
    if (check(v)) {
      ans++;
    }
    return;
  }

  // dfs를 4방향으로 해야함.
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && !vis[nx][ny]) {
      v.push_back(board[nx][ny]);
      vis[nx][ny] = true;
      dfs(nx, ny, ++count);
      v.pop_back();
      vis[nx][ny] = false;
      count--;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 5; i++) {
      string s;
      cin >> s;

      for (int j = 0; j < s.size(); j++) {
        board[i][j] = s[j];
      }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      v.push_back(board[i][j]);
      vis[i][j] = true;
      dfs(i, j, 1);
      v.pop_back();
      vis[i][j] = false;
    }
  }

  cout << ans;
}