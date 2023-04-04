#include <bits/stdc++.h>
using namespace std;

vector<int> nums;

int lft[1000010];
int rght[1000010];

// 트리의 시작과 끝을 인자로 받음.
// st는 루트고, 끝을 인자로 받는 이유는 자식노드 유무 판단하기 위해서다.
void makeTree(int st, int en) {
  if (st >= en) {
    return;
  }


  // 다음 것 보다 크면 왼쪽 자식이다.
  if (nums[st] > nums[st + 1]) lft[nums[st]] = nums[st + 1];

  // // 다음것보다 작으면 오른쪽 자식이다.
  // else rght[nums[st]] = nums[st + 1];

  // // 크기가 3인 서브트리일 때 
  // if (en - st == 2 && nums[st] < nums[en]) {
  //   cout << "HI" << en << st << '\n';
  //   rght[nums[st]] = nums[en];
  //   return;
  // }
  // 왼쪽 or 오른쪽 정해졌으면 이제 이 자식을 루트로 하는 서브트리를 재귀수행해야한다.

  int temp = st + 1;
  while (temp <= en && nums[st] > nums[temp]) {
    temp++;
  }

  // while문을 탈출한다면 루트보다 더 큰걸 만난거다.
  if (temp <= en) {
    rght[nums[st]] = nums[temp];
  }
  // temp를 기준으로 root보다 작은 노드와 큰 노드가 나뉘었다.
  makeTree(st + 1, temp - 1); // lft subtree
  makeTree(temp, en); // rght subtree
  return;
}

void postOrder(int root) {
  // 자식이 없으면 리턴.
  if (root == 0) return;

  // 왼쪽 서브트리 postOrder 재귀호출
  postOrder(lft[root]);

  // 오른쪽 서브트리 postOrder 재귀호출
  postOrder(rght[root]);

  // 루트 호출
  cout << root << '\n';
  
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num;
    while (cin >> num) {
        if (num != EOF) {
          nums.push_back(num);
        }
    }

    makeTree(0, nums.size() - 1);

    // cout << "50 " << lft[50] << ' ' << rght[50] << '\n';
    // cout << "30 " << lft[30] << ' ' << rght[30] << '\n';
    // cout << "98 " << lft[98] << ' ' << rght[98] << '\n';
    // cout << "24 " << lft[24] << ' ' << rght[24] << '\n';
    // cout << "45 " << lft[45] << ' ' << rght[45] << '\n';
    // cout << "52 " << lft[52] << ' ' << rght[52] << '\n';
    // cout << "5 " << lft[5] << ' ' << rght[5] << '\n';
    // cout << "28 " << lft[28] << ' ' << rght[28] << '\n';
    // cout << "60 " << lft[60] << ' ' << rght[60] << '\n';

    // 후위순회: 왼쪽서브트리-> 오른쪽 서브트리 -> 루트
    postOrder(nums[0]);
}

// 50 30 24 5 28 45 98 52 60