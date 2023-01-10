#include <bits/stdc++.h>
using namespace std;

int n = 2;
vector<int> info = {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0};

vector<vector<int>> V;

void dfs(vector<int> &v, int n) {
  if (n == v.size()) {
    vector<int> new_v;

    for (int i = 0; i < v.size(); i++) {
      new_v.push_back(v[i]);
    }

    V.push_back(new_v);
    return;
  }

  for (int i = 0; i <= 10; i++) {
    v.push_back(i);
    dfs(v, n);
    v.pop_back();
  }
}

bool compare(vector<int> &a, vector<int> &b) {
  if (a[11] < b[11]) {
    return true;
  }

  else if (a[11] == b[11]) {
    for (int i = a.size() - 2; i >= 0; i--) {
      if (b[i] > a[i]) return true;
      else if (b[i] == a[i]) continue;
      else return false;
    }
  }

  else return false;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    /*
      그냥 11개의 구역 중에서 중복을 포함해서 n개를 고르는 경우의 수를 구해서 각각의 위치에 화살을 넣은 후에, info와 비교를 한 후 더 크면 기존에 가장 컸던 값과 비교하는 함수에 넣은 후 더 크면 최대값을 갱신한다. 이후 모든 경우의 수가 끝나면 최대값을 출력하고 만족하는 값이 없는 경우 [-1]을 출력한다.
    */
    // dfs로 어떻게 1~11 중 n개를 중복을 포함해서 고를까?
    vector<int> v;
    dfs(v, n);
    vector<int> ret(12, -1);

    for (int i = 0; i < V.size(); i++) {
      vector<int> arrows(12, 0);
      int score = 0;

      for (int j = 0; j < V[i].size(); j++) {
        arrows[V[i][j]]++;
      }

      for (int j = 0; j < 11; j++) {
        if (info[j] != 0 && info[j] >= arrows[j]) {
          score -= 10 - j;
        } else if (info[j] < arrows[j]) {
          score += 10 - j;
        }
      }

      // for (int a: arrows) {
      //   cout << a;
      // }
      // cout << '\n';
      // cout << score;
      // cout << '\n';
      if (score <= 0) continue;
      
      arrows[11] = score;
      if (compare(ret, arrows)) {
        ret = arrows;
      }
    }

    if (ret[11] == -1) {
      vector<int> nodap(1, -1);
      answer = nodap;
    }

    else {
      ret.resize(11);
      answer = ret;
    }

    return answer;
}

// int main() {
//   vector<int> v = solution(n, info);
//   for (int aa: v) {
//     cout << aa;
//   }
// }