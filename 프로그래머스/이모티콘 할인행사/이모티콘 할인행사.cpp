#include <bits/stdc++.h>
using namespace std;
// 소요시간 1시간 40분
    /*
      시간복잡도 계산.
      브루트 포스 시, user = 100, emoticons = 7, 할인비율: 4가지,
      -> 4^7 * 100 = 2*14 * 100 = 160만.
    */
vector<vector<int>> users = {{40, 10000}, {25, 10000}};
vector<int> emoticons = {7000, 9000};

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
  vector<int> answer;
  
  // 4*emoticons.size() 만큼 필요.
  // if 15라면 4진법 하면 0033
  // emoticons.size() = 2개, 할인율 4가지.라면
  // 0,1,2,3 이 각 칸에서 필요. 4*4 = 16 = 4^2
  int temp;
  vector<vector<int>> v;
  int discount[4] = {10, 20, 30, 40};

  for (int i = 0; i < pow(4, emoticons.size()); i++) {
    temp = i;

    vector<int> temp2;
    for (int j = 0; j < emoticons.size(); j++) {
      int a = temp % 4;
      temp /= 4;
      temp2.push_back(a);
    }
    v.push_back(temp2);
  }

  vector<pair<int, int>> vv;
  
  for (int i = 0; i < v.size(); i++) {
    int usersbuy[100] = {0, };

    // v의 원소는 벡터. {2, 3} 이런식으로 있다.
    for (int j = 0; j < v[i].size(); j++) {

      for (int k = 0; k < users.size(); k++) {
        
        if (discount[v[i][j]] >= users[k][0]) {
          usersbuy[k] += emoticons[j] * (1 - 0.01 * discount[v[i][j]]);
        }
      }
    }

    int emoticon = 0;
    int plus = 0;

    for (int i = 0; i < users.size(); i++) {
      if (usersbuy[i] >= users[i][1]) {
        plus++;
      } else {
        emoticon += usersbuy[i];
      }
    }

    vv.push_back({-1 * plus, -1 * emoticon});
  }

  sort(vv.begin(), vv.end());

  answer.push_back(abs(vv[0].first));
  answer.push_back(abs(vv[0].second));

  return answer;
}

int main() {
  auto a = solution(users, emoticons);
  cout << a[0] << a[1];
}