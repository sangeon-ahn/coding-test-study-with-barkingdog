#include <bits/stdc++.h>
using namespace std;

int N;
int board[10][10];
bool diagonal1[20];
bool diagonal2[20];
vector<pair<int, int>> arr[20];

int ans = 0;

void backtracking(int order, int count) {
  cout << "order: " << order << " count: " << count << '\n';
    if (order == 2 * N ) {
        ans = max(ans, count);
        return;
    }

    for (int i = 0; i < arr[order].size(); i++) {
      pair<int, int> cur = arr[order][i];
      if (diagonal2[cur.first + cur.second]) {
        continue;
      }
      diagonal2[cur.first + cur.second] = true;
      backtracking(order + 1, count + 1);
      diagonal2[cur.first + cur.second] = false;
    }

    backtracking(order + 1, count);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                arr[N - j - 1 + i].push_back({i, j});
            }
        }
    }
    
    backtracking(0, 0);
    
    cout << ans;
}
