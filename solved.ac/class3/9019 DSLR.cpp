#include <bits/stdc++.h>
using namespace std;

struct Node {
  int num;
  string cmds;

  Node (int num, string cmds) {
    this->num = num;
    this->cmds = cmds;
  }
};

int T;

bool vis[10010];

Node DSLR(int order, Node node) {
  int temp = node.num;

  switch (order)
  {
  case 0:
    temp *= 2;
    if (temp > 9999) temp %= 10000;
    node.cmds += "D";
    break;
  case 1:
    temp -= 1;
    if (temp <= 0) temp = 9999;
    node.cmds += "S";
    break;
  case 2:
    temp = (temp % 1000) * 10 + temp / 1000; // 123일때 1230 + 0
    node.cmds += "L";
    break;
  case 3:
    temp = (temp % 10) * 1000 + temp / 10; // 123일때 3000 + 123/10 = 3012
    node.cmds += "R";
    break;
  }
  node.num = temp;
  return node;
}

void solve(int n1, int n2) {
    queue<Node> q;
    q.push(Node(n1, ""));

    while (!q.empty()) {
        Node cur = q.front(); q.pop();
        int curNum = cur.num;
        string curCmd = cur.cmds;

        if (curNum == n2) {
          cout << curCmd << '\n';
          return;
        }
        
        for (int i = 0; i < 4; i++) {
            Node result = DSLR(i, cur);

            if (result.num == n2) {
                cout << result.cmds << '\n';
                return;
            }

            if (vis[result.num]) continue;
            vis[result.num] = true;
            q.push(result);
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    int a, b;
    while (T--) {
        cin >> a >> b;
        vis[a] = true;
        solve(a, b);
        memset(vis, false, sizeof(vis));
    }
  return 0;
}

/*
  1 16, dddld
  2 4 8 80 160
*/