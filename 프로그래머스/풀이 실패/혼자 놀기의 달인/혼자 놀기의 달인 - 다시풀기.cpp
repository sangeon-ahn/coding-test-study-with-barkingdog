#include <bits/stdc++.h>

using namespace std;
/*
  그룹은 2개가 있다.
  cards 중 하나를 뽑아서 나온 값을 인덱스로 하고 또 뽑기를 반복하며 이전에 뽑은 숫자가 인덱스로 나올 때까지 계속한다. 숫자들을 box에 넣는다.
  만약 같은 숫자가 나왔을 경우 두번째 박스를 채우는 로직을 수행한다.
  cards를 돌면서 아직 오픈하지 않은 카드가 나왔을 경우 선택을 시작한다. 그리고 box2에 담는다.
  두번째 역시 같은 숫자가 나왔을 경우 중단하고 box1의 크기와 box2의 크기를 곱한 값을 result와 비교해서 더 큰값으로 갱신한다.
  한번 box2가 결정된 이후에는 다시 box2를 비워주고, 한 box1에 대해 모든 box2가 순회되었으면 box1도 초기화 시키고 open 여부도 초기화 한다. box2의 open 여부 초기화는 어디서 해야 할지? -> select 내부에서 recursion 끝나고 하면 된다.
*/
int result = 0;
bool vis[110];

vector<vector<int>> v(2);
vector<int> Cards;
bool isOpened[110];

void select(int n, int boxNum) {
  // 열려있으면 끝.
  if (isOpened[n]) {
    return;
  }

  // 안열려 있으면 오픈 체크하고 박스에 넣고 다음 select 수행
  isOpened[n] = true;
  v[boxNum].push_back(n);
  select(Cards[n - 1], boxNum);
}

int solution(vector<int> cards) {
  int answer = 0;
  Cards = cards;
  // 박스 1에 담는다.
  for (int i = 0; i < cards.size(); i++) {
    // i+1번째 카드를 첫번째 박스에 넣고 선택 시작.
    select(i + 1, 0);

    // 두번째 박스 채우기 시작
    for (int i = 0; i < cards.size(); i++) {
      // 아직 오픈되지 않은 카드를 찾아서 선택을 수행.
      if (!isOpened[i + 1]) {
        select(i + 1, 1);

        // 박스1 크기 X 박스2 크기.
        int multiply = v[0].size() * v[1].size();

        // 최댓값 갱신
        result = max(result, multiply);

        // box2에 속한 숫자에 대해 isOpened 초기화 시켜줌.
        for (int i = 0; i < v[1].size(); i++) {
          isOpened[v[1][i]] = false;
        }

        // box2 초기화 시켜줌.
        v[1].clear();
      }
    }

    // 모든 box2에 대해 수행이 끝나면 box1도 초기화 시켜줌
    for (int i = 0; i < v[0].size(); i++) {
      isOpened[v[0][i]] = false;
    }

    // box1 초기화 시켜줌.
    v[0].clear();
  }

  answer = result;
  return answer;
}