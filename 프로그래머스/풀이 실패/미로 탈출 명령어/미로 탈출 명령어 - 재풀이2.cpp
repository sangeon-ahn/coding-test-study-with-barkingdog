#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char dir[4] = {'d', 'l', 'r', 'u'};

string answer = "z";

bool isValid(int nx, int ny, int n, int m) {
  return nx >= 1 && nx <= n && ny >= 1 && ny <= m;
}

void dfs(int n, int m, int posX, int posY, int destX, int destY, int count, int k, string prev_s) {
  
  // 이동가능한 횟수가 남은 거리보다 작으면 리턴
  if (k - count < abs(destX - posX) + abs(destY - posY)) return;

  // 목적지에 도달했으면 리턴
  if (posX == destX && posY == destY && count == k) {
    answer = prev_s;
    return;
  }

  for (int i = 0; i < 4; i++) {
    int nx = posX + dx[i];
    int ny = posY + dy[i];

    // 새로운 nx, ny가 미로 안에 있고, 아직 answer보다 prev_s가 더 사전순으로 앞서면, dfs 수행.
    if (isValid(nx, ny, n, m) && prev_s < answer) {
      dfs(n, m, nx, ny, destX, destY, count + 1, k, prev_s + dir[i]);
    }
  }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
  
  int dist = abs(r - x) + abs(c - y);

  // 거리가 k보다 크면 불가능
  if (dist > k) return "IMPOSSIBLE";
  
  // k에서 거리 뺀 값이 짝수가 아니면 불가능
  if ((k - dist) % 2 != 0) return "IMPOSSIBLE";

  // dfs 수행
  dfs(n, m, x, y, r, c, 0, k, "");

  return answer;
}