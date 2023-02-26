#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ShiftRow(vector<vector<int>> rc) {
  vector<vector<int>> answer;
  answer.resize(rc.size());

  for (size_t i = 0; i < rc.size(); ++i) {
    if (i + 1 == rc.size())
      answer[0] = rc[i];
    else
      answer[i + 1] = rc[i];
  }

  return answer;
}

vector<vector<int>> Rotate(vector<vector<int>> rc) {
  vector<vector<int>> answer = rc;
  size_t row = rc.size();
  size_t column = rc[0].size();

  // 윗쪽
  for (size_t i = 1; i < column; ++i) {
    answer[0][i] = rc[0][i - 1];
  }

  // 오른쪽
  for (size_t i = 1; i < row; ++i) {
    answer[i][column - 1] = rc[i - 1][column - 1];
  }

  // 아래쪽
  for (size_t i = 1; i < column; ++i) {
    answer[row - 1][i - 1] = rc[row - 1][i];
  }

  // 왼쪽
  for (size_t i = 1; i < row; ++i) {
    answer[i - 1][0] = rc[i][0];
  }

  return answer;
}

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
  vector<vector<int>> answer = rc;

  for (string operation : operations) {
      if (operation == "ShiftRow") {
          answer = ShiftRow(answer);
      }

      else if (operation == "Rotate") {
          answer = Rotate(answer);
      }
  }

  return answer;
}