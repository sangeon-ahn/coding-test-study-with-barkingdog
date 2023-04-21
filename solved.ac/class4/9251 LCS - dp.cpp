#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int board[1010][1010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s1 >> s2;
    
    for (int i = 0; i < s1.size(); i++) {
        for (int j = 0; j < s2.size(); j++) {
            if (s1[i] == s2[j]) board[i][j] = 1;
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    
    int sum1 = 0;
    int idx1 = 0;
    for (int i = 0; i < s1.size(); i++) {
      if (idx1 == s2.size()) break;
        for (int j = idx1; j < s2.size(); j++) {
            if (board[i][j] == 1) {
                sum1 += 1;
                idx1 = j + 1;
                break;
            }
        }
    }

    int sum2 = 0;
    int idx2 = 0;
    for (int i = 0; i < s2.size(); i++) {
      if (idx2 == s1.size()) break;
      for (int j = idx2; j < s1.size(); j++) {
        if (board[j][i] == 1) {
          sum2++;
          idx2 = j + 1;
          break;
        }
      }
    }
    cout << max(sum1, sum2);
}
