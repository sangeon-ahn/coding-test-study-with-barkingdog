#include <bits/stdc++.h>
using namespace std;
// 풀이 소요 시간: 17분 40초
int T;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;

  for (int i = 0; i < T; i++) {
    int M, N, K;
    cin >> M >> N >> K;
    
    // 보드와 방문여부 0으로 초기화
    int board[60][60] = {0, };
    int vis[60][60] = {0, };
    /*
      특정 값으로 초기화 하는 법
      for (int i = 0; i < 100; i++) {
      fill(board[i], board[i]+99, 0);
      fill(vis[i], vis[i]+99, 0);
    }
    */
    int ans = 0;

    // 벌레 위치를 담을 벡터 선언
    vector<pair<int, int>> bug;
    
    // 벌레 위치를 보드에 표시하고 bug 벡터에 넣기.
    for (int i = 0; i < K; i++) {
      int x, y;
      cin >> x >> y;
      board[x][y] = 1;
      bug.push_back({x, y});
    }

    // 테스트 케이스 K개 수행
    for (int i = 0; i < K; i++) {
      auto b = bug[i];

      // 벌레 위치를 빼내고 이미 방문했으면 다음으로 넘어가기
      if (vis[b.first][b.second]) continue;
      ans++;
      queue<pair<int, int>> q;
      q.push(b);

      // 처음 방문한 배추면 q에 넣어서 bfs 수행
      while (!q.empty()) {
        auto p = q.front(); q.pop();
        
        // 상하좌우 네 방향에 걸쳐서 보기
        for (int i = 0; i < 4; i++) {
          int nx = p.first + dx[i];
          int ny = p.second + dy[i];

          // 만약 새로운 칸이 board 바깥이면 패스
          if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

          // 이미 방문한 곳이거나 빈 공간이면 패스
          if (vis[nx][ny] || board[nx][ny] == 0) continue;

          // 그외의 경우 배추가 있으니까 방문하고 큐에 다시 넣기
          vis[nx][ny] = 1;
          q.push({nx, ny});
        }
      }
    }
    cout << ans << '\n';
  }
}