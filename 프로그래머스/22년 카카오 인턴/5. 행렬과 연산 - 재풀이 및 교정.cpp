#include <bits/stdc++.h>

using namespace std;
/*
    두가지 기능을 구현해야 한다.
    첫번째 기능: 행 한칸씩 내리기
    두번째 기능: 보드 테두리 한칸 시계방향 회전

    보드의 첫번째 열과 마지막 열을 원소로 가지는 데큐를 각각 하나씩 만든다.
    위 두 열을 제외한 나머지 행의 원소에 대해서 각 행당 데큐 하나씩을 가지고,
    이 데큐들을 요소로 가지는 상위 데큐를 만들어서 2차원 데큐 구조로 만든다.
    내부 데큐는 포인터로 선언되어야 한다.

    그리고 시프트 연산은 단순히 마지막꺼 빼서 push_front 해주면 된다.
    회전 연산은 각 꼭지점에서 넣고 빼고 해서 회전 연산을 구현하면 된다.

    우선 어떻게 푸는지 답을 알고 있기 때문에 문제해결은 된 상태이다.
    이제 이걸 구현하면 된다.

    포인터 사용법 미숙으로 인해 풀이 실패
*/

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    vector<vector<int>> answer;
    answer.resize(rc.size());

    deque<int> leftDq(rc.size(), 0);
    deque<int> rightDq(rc.size(), 0);
    deque<deque<int>*> middleDq;
    vector<int> v;
    //이렇게 초기화해주는게 아니다.
    // deque<deque<int>*> middleDq(new deque(rc.size()));
    // for (vector<int> v : answer) {
    //     v.resize(rc[0].size());
    // }

    for (int i = 0; i < rc.size(); i++) {
      middleDq.push_back(new deque<int>(rc[0].size() - 2));
    }


    // 이미 0으로 초기화가 되어있어서 push 해주면 안됨

    // for (int i = 0; i < rc.size(); i++) {
    //     leftDq.push_back(rc[i][0]);
    //     rightDq.push_back(rc[i][rc.size() - 1]);
    // }

    // // middleDq에 dq 넣기
    // for (int i = 0; i < rc.size(); i++) {
    //     for (int j = 1; j < rc[i].size() - 2; j++) {
    //         middleDq[i]->push_back(rc[i][j]);
    //     }
    // }

    // leftDq, rightDq, middleDq에 삽입
    for (int i = 0; i < rc.size(); i++) {
      leftDq[i] = rc[i][0];
      rightDq[i] = rc[i][rc[0].size() - 1];

      for (int j = 1; j < rc[0].size() - 1; j++) {
        middleDq[i]->at(j - 1) = rc[i][j];
      }
    }

    for (string op : operations) {
      if (op == "ShiftRow") {
          leftDq.push_front(leftDq.back());
          leftDq.pop_back();

          rightDq.push_front(rightDq.back());
          rightDq.pop_back();

          // 가운데 열 shift
          middleDq.push_front(middleDq.back());
          middleDq.pop_back();
      }
      else if (op == "Rotate") {
          // 왼쪽 위
        middleDq[0]->push_front(leftDq.front());
        leftDq.pop_front();

        // 오른쪽 위
        rightDq.push_front(middleDq[0]->back());
        middleDq[0]->pop_back();

        // 오른쪽 아래
        middleDq[middleDq.size() - 1]->push_back(rightDq.back());
        rightDq.pop_back();

        // 왼쪽 아래
        leftDq.push_back(middleDq[middleDq.size() - 1]->front());
        middleDq[middleDq.size() - 1]->pop_front();
      }

    }

    // rc에 넣기
    for (int i = 0; i < rc.size(); i++) {
      rc[i][0] = leftDq[i];
      rc[i][rc[0].size() - 1] = rightDq[i];

      for (int j = 1; j <rc[0].size() - 1; j++) {
        rc[i][j] = middleDq[i]->at(j - 1);
      }
    }

    return rc;
}