/*
  L개 중에 C개를 조합으로 뽑은 후에, 해당 조합이 조건(최소 한개의 모음, 최소 두개의 자음)을
  만족하는지를 확인 후, 만족한다면 문자열 순서로 정렬한 뒤 출력한다.
*/
#include <bits/stdc++.h>
using namespace std;
// 풀이 성공. 20분 소요
int L, C;
char arr[20];

bool check(vector<char> temp) {
  int moum = 0;
  int jaum = 0;
  
  for (int i = 0; i < temp.size(); i++) {
    if (temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] =='o' || temp[i] == 'u') {
      moum++;
    }
    else jaum++;
  }

  if (moum >= 1 && jaum >= 2) return true;
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> L >> C;
  
  vector<string> store;
  for (int i = 0; i < C; i++) {
    cin >> arr[i];
  }

  vector<int> v(C, 1);
  fill(v.begin(), v.begin() + L, 0);
  
  do
  {
    vector<char> temp;

    for (int i = 0; i < v.size(); i++) {
      if (v[i] == 0) {
        temp.push_back(arr[i]);
      }
    }
    
    bool isValid = check(temp);
    
    if (!isValid) continue;
    sort(temp.begin(), temp.end());

    string s = "";
    for (char c: temp) {
      s += c;
    }

    store.push_back(s);

  } while (next_permutation(v.begin(), v.end()));

  sort(store.begin(), store.end());

  for (string s: store) {
    cout << s << '\n';
  }
}