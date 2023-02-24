#include <bits/stdc++.h>
using namespace std;

bool check(deque<int> binary) {
  if (binary.size() == 1) return true;

  int root = binary.size() / 2;

  if (binary[root] == 0) {

    // 트리 노드가 모두 0이 아닌 이상 false
    bool flag = true;

    for (int i = 0; i < binary.size(); i++) {
      if (binary[i] == 1) {
        flag = false;
        break;
      }
    }

    if (!flag) return false;
    return true;
  }

  deque<int> left;
  deque<int> right;

  for (int i = 0; i < root; i++) {
    left.push_back(binary[i]);
    right.push_back(binary[binary.size() - root + i]);
  }

  return check(left) && check(right);
}

bool canTree(long long number) {
  deque<int> binary;

  while (number > 0) {
    binary.push_front(number % 2);
    number /= 2;
  }

  long long size = binary.size();
  long long temp = 1;

  // temp - 1과 비교해야 하는 이유는 포화 이진트리의 크기는 2^n - 1이기 때문에 해당 값보다 클 때 새롭게 n++ 해줘야 하기 때문이다. -> 1시간 이상 낭비
  while (size > temp - 1) {
    temp <<= 1;
  }

  long long diff = (temp - 1) - size;

  while (diff--) {
    binary.push_front(0);
  }

  return check(binary);
}

vector<int> solution(vector<long long> numbers) {
  vector<int> answer;

  for (long long number : numbers) {
    if (canTree(number)) answer.push_back(1);
    else answer.push_back(0);
  }

  return answer;
}