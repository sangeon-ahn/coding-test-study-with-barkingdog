#include <bits/stdc++.h>
using namespace std;

int T;

deque<string> split(string str, char delimiter) {
    stringstream ss(str);
    string temp;
    deque<string> result;
    
    while (getline(ss, temp, delimiter)) {
        result.push_back(temp);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        string cmd;
        int n;
        string nums;
        cin >> cmd >> n >> nums;
        
        deque<int> dq;
        
        nums = nums.substr(1, nums.size() - 2);
        deque<string> temp = split(nums, ',');
        bool flag = true;
        int dir = 0;

        for (int i = 0; i < cmd.size(); i++) {
            if (cmd[i] == 'R') {
                dir++;
            }

            else if (cmd[i] == 'D') {
                if (temp.size() > 0) {
                    if (dir % 2 == 0) temp.pop_front();
                    else temp.pop_back();
                }

                else {
                    cout << "error\n";
                    flag = false;
                    break;
                }
            }
        }
        
        

        if (flag) {
            string ans = "[";
            if (temp.size() > 1) {
                if (dir % 2 == 0) {
                    for (int i = 0; i < temp.size() - 1; i++) {
                        ans += temp[i] + ',';
                    }
                    ans += temp[temp.size() - 1] + ']';
                }
                else {
                    for (int i = temp.size() -1; i > 0; i--) {
                        ans += temp[i] + ',';
                    }
                    ans += temp[0] + ']';
                }
            }
            else if (temp.size() == 1) ans += temp[0] + ']';
            else ans += ']';
            cout << ans << '\n';
        }
    }
}