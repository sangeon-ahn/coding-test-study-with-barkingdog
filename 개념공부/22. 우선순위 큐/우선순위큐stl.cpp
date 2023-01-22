#include <bits/stdc++.h>
using namespace std;

int main(void) {
  priority_queue<int> pq; // 초기는 최대힙.
  priority_queue<int, vector<int>, greater<int>> pq2; // 최소힙.
  pq.push(10), pq.push(10); // 이런식으로 푸시 가능.
  cout << pq.top(); // top은 맨윗값 리턴함.
  cout << pq.size(); // 사이즈 구하기 가능.
  if (!pq.empty()) cout << "not empty."; // 비어있나 확인 가능.
}