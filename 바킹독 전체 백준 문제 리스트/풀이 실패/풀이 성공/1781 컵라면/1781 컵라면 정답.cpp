#include <bits/stdc++.h>
using namespace std;

int N;
unsigned int cupNoodles;
priority_queue<unsigned int> cupNoodles_candiate;
vector<unsigned int> cupNoodles_by_deadline[200001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++) {
    int deadLine, cupNoodleCount;

    cin >> deadLine >> cupNoodleCount;

    // 데드라인별 컵라면 개수를 모아서 벡터에 저장.
    cupNoodles_by_deadline[deadLine].push_back(cupNoodleCount);
  }

  // 데드라인 많이 남은 순서부터 순회.
  for (int cur = 200000; cur > 0; cur--) {

    // 데드라인이 가장 큰 문제부터 뽑아서 최대힙에 넣기.
    for (int noodle: cupNoodles_by_deadline[cur]) {
      cupNoodles_candiate.push(noodle);
    }

    // 해당 데드라인인 문제가 없으면 패스.
    if (cupNoodles_candiate.empty()) continue;

    // 지금까지 넣은 문제 중 컵라면을 가장 많이 주는걸 빼서 더하기.
    cupNoodles += cupNoodles_candiate.top();
    cupNoodles_candiate.pop();
  }

  cout << cupNoodles;
}

/*
  데드라인이 큰 문제는 풀릴 기회가 더 많다.
  따라서 데드라인이 큰 순서대로 최대힙에 넣어서 가장 많은 컵라면을 주는 문제를 뽑아서 푼다.
  예를 들어 데드라인이 1인 문제는 맨 마지막에 최대힙에 들어가게 되고, 따라서 풀릴 기회는 1번 뿐이다.
  하지만 데드라인이 N인 문제는 N번 기회를 받는다.

  단순히 데드라인이나 컵라면 개수를 정렬해서 그리디로 풀면 안풀린다.
*/

