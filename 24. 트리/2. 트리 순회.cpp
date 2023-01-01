#include <bits/stdc++.h>
using namespace std;

int N;

// 이진트리의 왼쪽, 오른쪽 자식 정보가 필요하기 때문에 이를 배열에 넣기
int lc[30];
int rc[30];
int parent[30];
char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O','P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

// 전위순회
void preorder(int cur) {
  cout <<alphabet[cur-1];
  if (lc[cur] != 0) preorder(lc[cur]);
  if (rc[cur] != 0) preorder(rc[cur]);
}

// 중위순회
void inorder(int cur) {
  if (lc[cur] != 0) inorder(lc[cur]);
  cout << alphabet[cur-1];
  if (rc[cur] != 0) inorder(rc[cur]);
}

// 후위순회
void postorder(int cur) {
  if (lc[cur] != 0) postorder(lc[cur]);
  if (rc[cur] != 0) postorder(rc[cur]);
  cout << alphabet[cur-1];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 1; i <= N; i++) {
    // 현재 노드, 왼쪽 자식, 오른쪽 자식.
    char c, l, r;
    cin >> c >> l >> r;

    // l과 r이 대문자 알파벳이므로 'A'를 빼주면 인덱스 처리가 가능하다.
    if (l != '.') lc[c - 'A' + 1] = l - 'A' + 1;
    if (r != '.') rc[c - 'A' + 1] = r - 'A' + 1;
  }
  preorder(1);
  cout << '\n';
  inorder(1);
  cout << '\n';
  postorder(1);
}
