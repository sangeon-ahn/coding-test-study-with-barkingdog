#include <bits/stdc++.h>
using namespace std;

vector<string> split(string str, char delimiter) {
  string tmp;
  stringstream st(str);
  vector<string> result;

  while (getline(st, tmp, delimiter)) {
    result.push_back(tmp);
  }

  return result;
}

int getDiff(string s1, string s2) {
    int result = 0;
    int str_size = s1.size();
    for (int i = 0; i < s1.size(); i++) {
        result += pow(10, str_size - 1) * (s1[i] - s2[i]);
        str_size--;
    }

    return result;
}

bool determineDeleting(string today, vector<string> v, string duration) {
    // 지나간 날 확인
    vector<string> tday = split(today, '.');
    vector<string> firstDay = split(v[0], '.');

    int year = getDiff(tday[0], firstDay[0]);
    int month = getDiff(tday[1], firstDay[1]);
    int day = getDiff(tday[2], firstDay[2]);
    cout << year << ' ' << month << ' ' << day << '\n';
    int totalPassedDay = year * (12 * 28) + month * 28 + day;
    int permittedDay = stoi(duration) * 28;

    // cout << totalPassedDay << ' ' << permittedDay << '\n';
    return totalPassedDay >= permittedDay;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    /*
        privacies를 받는다.
        파기 해야하는지 확인한다.
        파기해야하면 answer에 넣는다.
    */

   map<string, string> mmap;

    // 조항 별 기간 저장.
   for (int i = 0; i < terms.size(); i++) {
    vector<string> v = split(terms[i], ' ');
    mmap[v[0]] = v[1];
   }

    // 프라이버시별로 계산.
   for (int i = 0; i < privacies.size(); i++) {
    vector<string> v = split(privacies[i], ' ');
    
    if (determineDeleting(today, v, mmap[v[1]])) {
        answer.push_back(i+1);
    }
   }

   // 오름차순 정렬
   sort(answer.begin(), answer.end());

    return answer;
}

int main() {
    string s = "2020.01.01";
    vector<string> v1 = {"Z 3", "D 5"};
    vector<string> v2 = {"2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"};
    vector<int> ans = solution(s, v1, v2);
    for (int s: ans) {
        cout << s;
    }
}