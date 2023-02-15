#include <bits/stdc++.h>
using namespace std;

bool opened[100];
vector<int> Cards;
vector<vector<int>> box(2);

void select(int card, int box_num) {
  // 카드에 적힌 번호의 상자를 개봉하지 않았다면
  if (!opened[card - 1]) {

    // 현재 그룹의 상자에 그 상자 번호를 저장
    box[box_num].push_back(card - 1);
    opened[card - 1] = true;

    // 현재 상자의 카드 번호를 통해 다시 판별
    select(Cards[card - 1], box_num);

    // 두 번째 그룹의 다른 경우를 체크하기 위해 연 상자를 다시 닫음
    if (box_num == 1) {
      opened[card - 1] = false;
    }
  }
}

int solution(vector<int> cards) {
  int answer = 0;
  Cards = cards;

  // 첫 번째 그룹 시작
  for (int i = 0; i < cards.size(); i++) {
    opened[i] = true;
    box[0].push_back(i);

    // 첫 번째 그룹 모으기
    select(cards[i], 0);

    // 두번째 그룹 시작
    for (int j = 0; j < cards.size(); j++) {
      if (!opened[j]) {
        opened[j] = true;
        box[1].push_back(j);

        // 두 번째 그룹 모으기
        select(cards[j], 1);

        // 점수 계산 후 더 큰 점수를 저장
        answer = max(answer, (int)(box[0].size() * box[1].size()));

        // 다른 경우도 찾아야 하므로 초기화
        opened[j] = false;
        box[1].clear();
      }
    }
    box[0].clear();

    for (int i = 0; i < cards.size(); i++) {
      opened[i] = false;
    }
  }

  return answer;
}