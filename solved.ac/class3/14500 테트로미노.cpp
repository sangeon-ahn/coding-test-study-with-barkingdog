#include <bits/stdc++.h>
using namespace std;


int board[501][501];
int ans = 0;
bool vis[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;
void dfs(int x, int y, int count, int sum) {
    if (count == 4) {
        ans = max(ans, sum);
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (vis[nx][ny]) continue;
        vis[nx][ny] = true;
        dfs(nx, ny, count + 1, sum + board[nx][ny]);
        vis[nx][ny] = false;
    }
}

void check(int x, int y) {
    vector<int> nums;
    int sum = board[x][y];
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        nums.push_back(board[nx][ny]);
        sum += board[nx][ny];
    }
    
    if (nums.size() == 3) {
        ans = max(ans, sum);
    }
    else if (nums.size() == 4) {
        for (int i = 0; i < nums.size(); i++) {
            int temp = sum - nums[i];
            ans = max(ans, temp);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    
    // ㅗ 모양을 제외한 테트로미노들은 dfs로 구하기 가능
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            vis[i][j] = true;
            dfs(i, j, 1, board[i][j]);
            vis[i][j] = false;
        }
    }
    
    // ㅗ 모양 구하기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            check(i, j);
        }
    }
    
    cout << ans;
}