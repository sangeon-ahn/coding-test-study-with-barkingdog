#include <bits/stdc++.h>
using namespace std;

int N, M;
// vector<int> nums;
int nums[10];
// vis는 숫자의 사용 여부를 판단함.
bool vis[10];

void backtracking(int order) {
    if (order == M) {
        for (int i = 0; i < order; i++) {
          cout << nums[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = 1; i <= N; i++) {
      if (vis[i]) continue;

      nums[order] = i;
      vis[i] = true;
      backtracking(order + 1);
      vis[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    
    backtracking(0);
}