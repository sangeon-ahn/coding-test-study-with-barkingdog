#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<int> info) {
  vector<int> ans(11);
  int mx = 0;

  // 0~10의 칸 중에 이길 칸을 고르는 for문.
  for (int i = 0; i < 2048; i++) {
    vector<int> result(11);
    int shoot_sum = 0;
    int score = 0;

    for (int j = 0; j < 11; j++) {
      if (i & 1 << j) {
        result[10 - j] = info[10 - j] + 1;
        shoot_sum += result[10 - j];
        score += j;
      } else score -= info[10 - j] ? j : 0;
    }

    // 화살 다 쓰고 보니 가지고 있는 것보다 많이 썼다면 패스.
    if (shoot_sum > n) continue;
    
    // 더 조금 썻다면 0점에 몰아넣기.
    result[10] += n - shoot_sum;

    // 어피치한테 졌거나 스코어가 현재 최대 스코어보다 낮다면 패스
    if (score <= 0 || mx > score) continue;

    // 스코어가 현재 맥스보다 크면 결과 갱신.
    if (mx < score) ans = result;

    // 점수가 같으면 가장 낮은 점수에 맞춘 화살이 많은걸로 갱신.
    else if (mx == score) {
      bool flag = true;

      for (int j = 11; j >= 0; j--) {
        if (ans[j] < result[j]) break;
        if (ans[j] > result[j]) {
          flag = false;
          break;
        }
      }

      if (flag) ans = result;
    }
    mx = score;
  }

  if (mx) return ans;
  return {-1};
}
int n = 2;
vector<int> info = {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0};
int main() {
  vector<int> answer = solution(n, info);
  for (int i : answer) {
    cout << i;
  }
}