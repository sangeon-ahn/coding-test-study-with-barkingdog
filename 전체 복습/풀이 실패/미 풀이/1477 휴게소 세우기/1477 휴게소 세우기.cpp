#include <bits/stdc++.h>
using namespace std;

int N, M, L;
vector<int> v;

pair<int, int> getInsertedIndex() {
  int idx = 0;
  int pos = 0;
  int dist = 0;

  // 가장 긴 구간 찾기.
  for (int i = 0; i < v.size() - 1; i++) {
    if (dist < v[i + 1] - v[i]) {
      dist = v[i + 1] - v[i];
      idx = i + 1;
      pos = v[i] + (dist+1) / 2;
    }
  }

  return {idx, pos};
}

int getMaxDist() {
  int dist = 0;

  // 가장 긴 구간 찾기.
  for (int i = 0; i < v.size() - 1; i++) {
    if (dist < v[i + 1] - v[i]) {
      dist = v[i + 1] - v[i];
    }
  }

  return dist;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> L;

  // 우선 고속도로의 시작과 끝을 저장.
  v.push_back(0);
  v.push_back(L);

  // 현재 휴개소의 위치를 저장.
  for (int i = 0; i < N; i++) {
    int pos;
    cin >> pos;
    v.push_back(pos);
  }

  // 거리순으로 정렬
  sort(v.begin(), v.end());
  for (int i: v) {
    cout << i << ' ';
  }
  cout << '\n';
  // 새로운 휴게소 넣기.
  while (M--) {
    auto newStation = getInsertedIndex();
    cout << newStation.first << ' ' << newStation.second << '\n';
    v.insert(v.begin() + newStation.first, newStation.second);
  }
  for (int a: v) {
    cout << a << ' ';
  }
  cout << getMaxDist();
}