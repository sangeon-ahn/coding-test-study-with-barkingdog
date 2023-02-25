#include <bits/stdc++.h>
using namespace std;

map<string, int> m;

// 1. 문자열 delimiter로 나누기.
vector<string> split(string str, char delimiter) {
  string tmp;
  stringstream st(str);
  vector<string> result;

  while (getline(st, tmp, delimiter)) {
    result.push_back(tmp);
  }

  return result;
}

vector<int> parseDate(string date) {
  vector<int> result;

  result.push_back(stoi(date.substr(0, 4)));
  result.push_back(stoi(date.substr(5, 2)));
  result.push_back(stoi(date.substr(8, 2)));

  return result;
}

int getDiff(vector<int> today, vector<int> date) {
  int totalTodayDays = today[0] * 12 * 28 + today[1] * 28 + today[2];
  int totalDateDays = date[0] * 12 * 28 + date[1] * 28 + date[2];

  return totalTodayDays - totalDateDays;
}

bool isOver(vector<int> today, vector<int> date, string P) {
  if (getDiff(today, date) >= m[P] * 28) return true;
  return false;
}


vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
  vector<int> answer;

  // 오늘 날짜 구하기
  vector<int> Today = parseDate(today);
  
  // 약관 map에 넣기
  for (int i = 0; i < terms.size(); i++) {
    vector<string> term = split(terms[i], ' ');
    m[term[0]] = stoi(term[1]);
  }

  // 개인정보 약관 계약날짜와 약관 구하기
  for (int i = 0; i < privacies.size(); i++) {
    vector<string> privacy = split(privacies[i], ' ');
    vector<int> date = parseDate(privacy[0]);
  
    if (isOver(Today, date, privacy[1])) answer.push_back(i + 1);
  }

  sort(answer.begin(), answer.end());

  return answer;
}

int main() {
  vector<int> a = solution("2022.06.19", {}, {});
}