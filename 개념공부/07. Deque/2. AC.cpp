#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  while (N--) {
    string S1, S2;
    int N2;
    deque<int> DQ;
    cin >> S1 >> N2 >> S2;

    for (int i = 1; i < S2.length(); i+=2) {
      if (S2.length() == 2) break;
      DQ.push_back(S2[i]-'0');
    }

    for (int i = 0; i < S1.length(); i++) {
      S1.c_str();
      if (c_str(S1[i]) == "D") {
        if (!DQ.size()) {
          cout << "error" << '\n';
          break;
        }
        else DQ.pop_front();
      } else {
        while (N2--) {
          DQ.push_back(DQ.front());
          DQ.pop_front();
        }
      }
    }
    cout << '[';
    for (int i = 0; i < DQ.size(); i++) {
      cout << DQ[i] << ",";
      if (i == DQ.size() - 1) cout << DQ[i];
    }
    cout << "]";
  }
}

void parse(string& tmp, deque<int>& d) {
  int cur = 0;
  for (int i = 1; i < tmp.size() - 1; i++) {
    // 따옴표 1개로 ',' 이렇게 하면 char형 타입으로 만들어짐.
    if (tmp[i] == ',') {
      d.push_back(cur);
      cur = 0;
    }
    // '0' 빼서 int형으로 바꾸는거 까먹음
    else cur = 10 * cur + (tmp[i] - '0');
  }
  // for문 나왔을때 cur 있는거 d에 넣어줘야 함.
  if (cur != 0) d.push_back(cur);
}

void print_result(deque<int>& d) {
  cout << '[';
  for (int i = 0; i < d.size(); i++) {
    cout << d[i] << ',';
    if (i == d.size() - 1) cout << d[i] << ']' << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  bool isWrong = false;
  cin >> N;

  for (int i = 0; i < N; i++) {
    string S1, S2;
    int N2;
    int rev = 0;
    deque<int> DQ;

    cin >> S1 >> N2 >> S2;
    parse(S2, DQ);

    for (char c: S1) {
      if (c == 'R') {
        rev = 1 - rev;
      } else {
        if (DQ.empty()) isWrong = true; break;
        // 거꾸로 유무에 따라 앞에서 뺄건지 뒤에서 뺄건지를 나눠줘야 함.
        if (!rev) DQ.pop_front();
        else DQ.pop_back();
      }
    }
    if (isWrong) cout << "error" << '\n';
    else {
      if (rev) reverse(DQ.begin(), DQ.end());
      print_result(DQ);
    }
  }
}


// 바킹독 풀이
// reverse 함수 사용해서 거꾸로 하기
// 함수로 빼서 코드작성
// 숫자가 10의자리일 경우 고려
void parse(string& tmp, deque<int>& d){
  int cur = 0;
  for(int i = 1; i+1 < tmp.size(); i++)
  {
    if(tmp[i] == ','){
      d.push_back(cur);
      cur = 0;
    }
    else{
      cur = 10 * cur + (tmp[i] - '0');
    }
  }
  if(cur != 0)
    d.push_back(cur);
}

void print_result(deque<int>& d){
  cout << '[';
  for(int i = 0; i < d.size(); i++)
  {
    cout << d[i];
    if(i+1 != d.size())
      cout << ',';
  }
  cout << "]\n";
}

int t;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--){
    deque<int> d;
    int rev = 0;
    int n;
    bool isWrong = false;
    string query, tmp;
    cin >> query;
    cin >> n;
    cin >> tmp;
    parse(tmp, d);
    for(char c : query)
    {
      if(c == 'R')
        rev = 1 - rev;
      else{
        if(d.empty()){
          isWrong = true;
          break;
        }
        if(!rev) d.pop_front();
        else d.pop_back();
      }
    }
    if(isWrong)
      cout << "error\n";
    else{
      if(rev) reverse(d.begin(), d.end());
      print_result(d);
    }
  }
}