#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;


// 못풀었다. 구현문제 어렵다. 삼성a형.
int N, M;
int office[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cover[4];
int zeros;
int ans;
vector<pair<int, int>> v;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> office[i][j];
      if (office[i][j] >= 1 && office[i][j] <= 5) {
        v.push_back({i, j});
      }
      if (office[i][j] == 0) {
        zeros++;
      }
    }
  }
  queue<pair<int, int>> Q;
  // 1번: 0, 1, 2, 3 중 하나
  // 2번: 0, 1 중 하나
  // 3번: 0, 1, 2, 3중 하나
  // 4번: 0 하나
  // 만약 1 1 2 3 5 이렇게 있으면
  // 경우의수 4*4*2*4*1이다.
  // 각 숫자별 개수를 구해서 5중 for문으로 돌리기
  for (auto n: v) {
    if (office[n.first][n.second] == 1) {
      for (int i = 0; i < 4; i++) {
        if (i == 0) {
          for (int j = n.first+1; j < N; j++) {
            if (office[j][n.second] == 6) break;
            if (office[j][n.second] != 0) continue;
            
          }
        }
        else if (i == 1) {
          for (int j = n.second + 1; j < M; j++) {
            if (office[n.first][j] == 6) break;
            if (office[n.first][j] != 0) continue;
            cover[i] += 1;
          }
        }
        else if (i == 2) {
          for (int j = n.first - 1; j >= 0; j--) {
            if (office[j][n.second] == 6) break;
            if (office[j][n.second] != 0) continue;
            cover[i] += 1;
          }
        }
        else if (i == 3) {
          for (int j = n.second - 1; j >= 0; j--) {
            if (office[n.first][j] == 6) break;
            if (office[n.first][j] != 0) continue;
            cover[i] += 1;
          }
        }
      }
    }
    // else if (office[n.first][n.second] == 2) {

    // }
    // else if (office[n.first][n.second] == 3) {

    // }
    // else if (office[n.first][n.second] == 4) {

    // }
    // else if (office[n.first][n.second] == 5) {

    // }
  }
  int maxnum = cover[0];

  for (int n: cover) {
    if (maxnum < n) {
      maxnum = n;
    }
  }
  ans = zeros - maxnum;
  cout << ans << ' ';
}

