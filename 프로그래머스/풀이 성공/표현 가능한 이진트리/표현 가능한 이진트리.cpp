#include <bits/stdc++.h>
using namespace std;
/*
  1. 숫자가 주어진다.
  2. 숫자를 이진수로 변환한다.
  3. 0과 1의 개수가 2^n-1개가 될때까지 맨앞에 0을 붙인다. 
  4. 이 값이 이진트리로 구현 가능한지 확인한다.
  x
*/

bool canTree(deque<int> d) {
  if (d.size() == 1) return true;
  
  // mid 인덱스.
  int mid = d.size() / 2;

  if (d[mid] != 1) {
    bool flag = true;

    for (int i = 0; i < d.size(); i++) {
      if (d[i] != 0) flag = false;
    }
    
    if (flag) return true;
    return false;
  }

  deque<int> left;
  deque<int> right;

  for (int i = 0; i < mid; i++) {
    left.push_front(d[i]);
    right.push_front(d[d.size()- 1 - i]);
  }

  bool l = canTree(left);
  bool r = canTree(right);

  return l && r;
}

int check(long long n) {
  deque<int> binarys;

  while (n > 0) {
    binarys.push_front(n % 2);
    n /= 2;
  }
  // for (int a: binarys) {
  //   cout << a;
  // }
  // size + 2이 2 ^x이어야 하고 트리 가운데 값이 1이어야 함.
  int temp = binarys.size();
  // cout << temp;
  int i = 1;

  while (true) {
    int x = pow(2, i) - 1;

    if (x == temp) {
      break;
    }
    else if (x < temp) {
      i++;
      continue;
    }
    else {
      int diff = x - temp;
      cout << diff;
      while (diff--) {
        binarys.push_front(0);
      }
      break;
    }
  }
  
  return canTree(binarys) ? 1 : 0;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for (long long n: numbers) {
      answer.push_back(check(n));
    }
    return answer;
}

int main() {
  vector<long long> nums = {184};
  vector<int> v = solution(nums);
  for (int a: v) {
    cout << a;
  }
}