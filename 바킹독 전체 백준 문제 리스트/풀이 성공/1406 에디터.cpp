#include <bits/stdc++.h>
using namespace std;
// 소요시간: 40분
/*
  데큐에서 앞에 추가할지, 뒤에 추가할지, 앞을 뺄지, 뒤를 뺄지를 생각하는게 어려웠다.
*/
string s;
int N;
deque<char> dq;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s >> N;
  stack<char> st;
  
  // 스택에 문자열 넣기
  for (int i = 0; i < s.size(); i++) {
    st.push(s[i]);
  }

  // 명령어 받아서 하나씩 실행.
  for (int i = 0; i < N; i++) {
    char a;
    cin >> a;
    // L이면 스택에서 빼서 dq에 넣기.
    if (a == 'L') {
      if(st.size() != 0) {
        dq.push_back(st.top());
        st.pop();
      } 
    }

    // D 입력받으면 데큐에서 하나 빼서 스택에 넣기.
    else if (a == 'D') {
      if (dq.size() != 0) {
        st.push(dq.back());
        dq.pop_back();
      }
    }

    // B 입력받으면 스택에서 하나 없애기.
    else if (a == 'B') {
      if (st.size() != 0) {
        st.pop();
      }
    }

    // P면 두번째 문자를 받아서 스택에 넣음.
    else if (a == 'P') {
      char b;
      cin >> b;
      st.push(b);
    }
  }

  // 명령이 끝났으면 데큐에 있는 문자를 다시 넣어줌.
  int dqSize = dq.size();
  for (int i = 0; i < dqSize; i++) {
    st.push(dq.back());
    dq.pop_back();
  }

  // 스택에 있는 문자를 모두 꺼낸 후 거꾸로 출력한다.
  vector<char> v;
  while (!st.empty()) {
    v.push_back(st.top());
    st.pop();
  }
  v.insert(v.begin(), 'u');
  for (int i = v.size() - 1; i >= 0; i--) {
    cout << v[i];
  }
}