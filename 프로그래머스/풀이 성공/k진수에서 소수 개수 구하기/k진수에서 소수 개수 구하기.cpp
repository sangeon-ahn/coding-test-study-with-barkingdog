#include <bits/stdc++.h>

using namespace std;
/*
    n을 k진수로 바꾸기
    0을 기준으로 숫자 분리
    소수 판별
*/

bool sosu(long long n) {
    for (long long i = 2; i <= floor(sqrt(n)); i++) {
        if (n % i == 0) return false;
    }
    return true;
}


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

string tenToK(int number, int k) {
    string result = "";
    
    int a = number;
    int b;
    while (a > 0) {
        b = a % k;
        a = a / k;
        result += to_string(b);
    }
    
    reverse(result.begin(), result.end());
    return result;
}

int solution(int n, int k) {
    int answer = 0;
    
    string knum = tenToK(n, k);
    vector<string> nums = split(knum, '0');
    
    string s = "";
    for (int i = 0; i < knum.size(); i++) {
        if (knum[i] != '0') {
            s += knum[i];
            
            if (i == knum.size() - 1 && s != "1" && sosu(stoll(s))) {
                answer++;
            }
            
            continue;
        }
        
        if (s != "" && s != "1" && sosu(stoll(s))) {
            answer++;
        }
        s = "";
        
    }
    

    return answer;
}