#include <bits/stdc++.h>

using namespace std;
/*
    course벡터에서 요리 개수 하나씩 뽑아서 그 숫자대로 각 order에서 요리 뽑아서 맵에 넣는다.
    가장 숫자가 높은 조합을 결과에 넣는다.
*/

vector<string> getComb(string str, int course) {
    vector<string> result;

    vector<int> vec(str.size(), 1);
    for (int i = 0; i < course; i++) {
        vec[i] = 0;
    }
    
    do {
        string temp = "";
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == 0) {
                temp += str[i];
            }
        }
        sort(temp.begin(), temp.end());
        result.push_back(temp);
    } while(next_permutation(vec.begin(), vec.end()));
    
    sort(result.begin(), result.end());
    return result;
}

bool compare(pair<string, int> a, pair<string, int> b) {
  if (a.first < b.first) return true;
  else return false;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    map<string, int> m;

    for (int i = 0; i < course.size(); i++) {
        for (int j = 0; j < orders.size(); j++) {
            if (orders[j].size() < course[i]) continue;
            vector<string> temp = getComb(orders[j], course[i]);
            
            for (string st : temp) {
                m[st] += 1;
            }
        }
    }    

    vector<pair<string, int>> vec(m.begin(), m.end());

    // 지금 vec에는 pair<string, int>가 담겨 있고, 길이가 제각각이다.
    // 그리고 나는 각 길이별 최대값을 찾고 이를 만족하는 string을 찾아야 한다.
    // for문을 3번 돌아야 한다는 것에 좀 짜증이 나긴 하지만 방법이 생각났다.
    // vec을 for문 돌면서 최대값을 찾은 후, 다시 for문을 돌면서 p.second가 해당 길이의 최대값과 같으면 결과 벡터에 넣는 것이다.
    // 그후 결과벡터를 오름차순 정렬하고 리턴하면 끝

    map<int, int> maxCount;

    // 각 코스사이즈 별 최대값 찾기.
    for (auto p: vec) {
      maxCount[p.first.size()] = max(maxCount[p.first.size()], p.second);
    }

    // 최대값이면 결과 벡터에 넣기.
    for (auto p: vec) {
      if (p.second == maxCount[p.first.size()] && p.second >= 2) {
        answer.push_back(p.first);
      }
    }

  sort(answer.begin(), answer.end());
  return answer;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<string> ans = solution({"XYZ", "XWY", "WXA"}, {2,3,4});

  for (string str: ans) {
    cout << str << '\n';
  }
}