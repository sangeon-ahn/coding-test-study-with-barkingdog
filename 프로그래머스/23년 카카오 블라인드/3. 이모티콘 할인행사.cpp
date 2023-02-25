#include <bits/stdc++.h>
using namespace std;

/*
  할인 퍼센트 수열로 구하기
  dfs와 brute 방식
  dfs 방식으로 해보자.

  각 이모티콘 당 할인율을 설정한 후, 각 유저별로 해당 이모티콘을 사거나 보류한다.
  구매가 끝났을 때 한도보다 크면 멤버쉽 가입, 작으면 결제
  결과를 계속 answer와 비교해서 더 좋은 결과면 업데이트

  수열 끝나면 answer 반환.
*/
// 할인율로 물건가격을 계산하는 실수로 30분 낭비
int discount[4] = {10, 20, 30, 40};

vector<int> result = {0, 0};
vector<int> discounts;
vector<int> Emoticons;
vector<vector<int>> Users;

void dfs(int order, int size) {
  if (order == size) {
    vector<int> res(2, 0);

    // 구매.
    for (int i = 0; i < Users.size(); i++) {
      int sum = 0;

      for (int j = 0; j < discounts.size(); j++) {
        if (Users[i][0] <= discounts[j]) {
          sum += Emoticons[j] * (100 - discounts[j]) * 0.01;
        }
      }
      
      if (sum >= Users[i][1]) {
        res[0] += 1;
      } else {
        res[1] += sum;
      }
    }

    result = max(result, res);
    return;
  }

  for (int i = 0; i < 4; i++) {
    discounts.push_back(discount[i]);
    dfs(order + 1, size);
    discounts.pop_back();
  }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
  vector<int> answer;
  Emoticons = emoticons;
  Users = users;
  dfs(0, emoticons.size());

  return result;
}