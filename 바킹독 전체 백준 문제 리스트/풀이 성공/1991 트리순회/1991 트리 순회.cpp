#include <bits/stdc++.h>
using namespace std;


int N;
vector<int> graph[100];
char arr[100];

void preorder(int head) {
  cout << arr[head];
  if (graph[head].size() >= 1) {
    preorder(graph[head][0]);
  }
  if (graph[head].size() == 2) {
    preorder(graph[head][1]);
  }
}

void inorder(int head) {
  if (graph[head].size() >= 1) {
    inorder(graph[head][0]);
  }
  cout << arr[head];
  if (graph[head].size() == 2) {
    inorder(graph[head][1]);
  }
}

void postorder(int head) {
  if (graph[head].size() >= 1) {
    postorder(graph[head][0]);
  }
  if (graph[head].size() == 2) {
    postorder(graph[head][1]);
  }
  cout << arr[head];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;

  for (int i = 1; i <= N; i++) {
    char v1, v2, v3;
    cin >> v1 >> v2 >> v3;
    arr[v1 - 'A' + 1] = v1;

    if (v2 != '.') {
      arr[v2 - 'A' + 1] = v2;
      graph[v1 - 'A' + 1].push_back(v2 - 'A' + 1);
    }

    if (v3 != '.') {
      arr[v3 - 'A' + 1] = v3;
      graph[v1 - 'A' + 1].push_back(v3 - 'A' + 1);
    }
  }

  preorder(1);
  cout << '\n';
  inorder(1);
  cout << '\n';
  postorder(1);
}