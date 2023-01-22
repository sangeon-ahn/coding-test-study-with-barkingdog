#include <bits/stdc++.h>
using namespace std;
// 풀이 소요시간 26분
int N;
set<string> s;
vector<string> v;

bool compare(string a, string b) {
  if (a.length() > b.length()) {
    return false;
  }

  if (a.length() < b.length()) {
    return true;
  }

  else {
    for (int i = 0; i < a.length(); i++) {
      int temp = a[i] - b[i];

      if (temp > 0) {
        return false;
      } else if (temp < 0) {
        return true;
      } else continue;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  // 문자열 입력받아서 set에 넣어서 중복 제거.
  for (int i = 0; i < N; i++) {
    string a;
    cin >> a;
    s.insert(a);
  }

  // 정렬하기 위해 벡터에 넣기.
  for (auto a: s) {
    v.push_back(a);
  }

  sort(v.begin(), v.end(), compare);

  for (auto a: v) {
    cout << a << '\n';
  }
  /*
    unique와 resize의 조합으로 중복 제거 가능
    unique 함수는 벡터 내 원소를 중복되지 않은 것들을 앞으로 보내고, 중복이 시작되는 원소들을 뒤로 보내고 중복 시작점을 가리키는 iterator를 반환한다.
    resize 함수는 0번째 원소부터 인자로 받은 크기까지로 크기를 줄이는 함수다.
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin()) 이렇게 해주면 된다.
  */
}