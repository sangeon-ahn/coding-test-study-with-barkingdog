#include <bits/stdc++.h>
using namespace std;

int M;
bool isIn[21];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M;
    
    for (int i = 0; i < M; i++) {
      string cmd;
      int num;

      cin >> cmd;
      
      if (cmd != "all" && cmd != "empty") {
        cin >> num;
      }

        if (cmd == "add" && !isIn[num]) {
            isIn[num] = true;
        }
        else if (cmd == "remove" && isIn[num]) {
            isIn[num] = false;
        }
        else if (cmd == "check") {
            cout << isIn[num] << '\n';
        }
        else if (cmd == "toggle") {
            isIn[num] = isIn[num] ? false : true;
        }
        else if (cmd == "all") {
            memset(isIn, true, sizeof(isIn));
        }
        else {
            memset(isIn, false, sizeof(isIn));
        }
    }
}