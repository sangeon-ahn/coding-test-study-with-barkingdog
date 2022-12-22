#include <iostream>
#include <queue>
using namespace std;

int stair[1000];
int N;
int max_score = -100;


// 메모리 초과로 실패, 예시는 풀리긴 함.
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  queue<pair<int, pair<int, int>>> Q;

  for (int i = 1; i <= N; i++) {
    cin >> stair[i];
  }

  // {점수, {현재 계단 차례, 연속 몇 번}}
  Q.push({0, {0, 0}});

  while (!Q.empty()) {
    auto q = Q.front(); Q.pop();
    auto idxes = q.second;
    int cur_score = q.first;
    int new_score = cur_score + stair[idxes.first];

    // 맨 위를 넘어가거나 3번 연속 한칸이면 무시
    if (idxes.first > N || idxes.second == 3) {
      continue;
    }

    // 맨 위에 도착한 경우.
    if (idxes.first == N) {
      max_score = max(max_score, new_score);
      continue;
    }

    // 아직 안 도착한 경우.
    Q.push({new_score, {idxes.first + 1, idxes.second + 1}});
    Q.push({new_score, {idxes.first + 2, 1}});
  }

  cout << max_score;
}