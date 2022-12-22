#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int board[100][100];
int min_dist_sum = 1000000;
int chicken_count;
vector<pair<int, int>> chickens;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
      if (board[i][j] == 2) {
        chickens.push_back({i, j});
        chicken_count++;
      }
    }
  }

  vector<int> v;
  for (int i = 0; i < chicken_count; i++) {
    if (i < M) {
      v.push_back(0);
    } else {
      v.push_back(1);
    }
  }

  do {
    int dist_sum = 0;
    vector<pair<int, int>> v2;
    
    for (int i = 0; i < v.size(); i++) {
      if (v[i] == 0) {
        v2.push_back(chickens[i]);
      }
    }

    for (int i = 0; i< N; i++) {
      for (int j = 0; j < N; j++) {
        if (board[i][j] == 1) {
          int min_dist = 1000;

          for (int k = 0; k < v2.size(); k++) {
            min_dist = min(min_dist, (abs(v2[k].first - i) + abs(v2[k].second - j)));
          }
          dist_sum += min_dist;
        }
      }
    }
    min_dist_sum = min(min_dist_sum, dist_sum);

  } while (next_permutation(v.begin(), v.end()));
  cout << min_dist_sum;
}