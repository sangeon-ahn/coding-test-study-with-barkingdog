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
    cupNoodles_by_deadline[deadLine].push_back(cupNoodleCount);
  }

  for (int cur = 200000; cur > 0; cur--) {
    for (int noodle: cupNoodles_by_deadline[cur]) {
      cupNoodles_candiate.push(noodle);
    }

    if (cupNoodles_candiate.empty()) continue;

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
  */