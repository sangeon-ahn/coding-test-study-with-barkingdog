#include <bits/stdc++.h>
using namespace std;

int N, K;
int arr[300010];

// 보석의 무게가 큰 순서대로 정렬해서 큰 순서부터 가방에 담으려고 했지만 잘못된 그리디 설계였다.
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;

  map<int, vector<int>> mmap;
  vector<int> backs;
  int ans = 0;

  while (N--) {
    int m, v;
    cin >> m >> v;

    mmap[-m].push_back(v);
  }

  while (K--) {
    int c;
    cin >> c;
    backs.push_back(c);
  }

  for (int i = 0; i < backs.size(); i++) {
    auto a = mmap.lower_bound(-backs[i]);
  }

}