#include <bits/stdc++.h>
using namespace std;

int N;
int lc[30];
int rc[30];

char arr[27] = {'.', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P','Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

void preorder(int head) {
  cout << arr[head];
  if (lc[head] != 0) preorder(lc[head]);
  if (rc[head] != 0) preorder(rc[head]);
}

void inorder(int head) {
  if (lc[head] != 0) inorder(lc[head]);
  cout << arr[head];
  if (rc[head] != 0) inorder(rc[head]);
}

void postorder(int head) {
  if (lc[head] != 0) postorder(lc[head]);
  if (rc[head] != 0) postorder(rc[head]);
  cout << arr[head];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  
  for (int i = 1; i <= N; i++) {
    char v1, v2, v3;
    cin >> v1 >> v2 >> v3;

    if (v2 != '.') lc[v1 - 'A' + 1] = v2 - 'A' + 1;
    if (v3 != '.') rc[v1 - 'A' + 1] = v3 - 'A' + 1;
  }

  preorder(1);
  cout << '\n';
  inorder(1);
  cout << '\n';
  postorder(1);
  cout << '\n';
}