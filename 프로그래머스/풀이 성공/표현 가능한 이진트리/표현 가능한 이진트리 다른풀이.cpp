#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool chk;

bool sol(string s, int cur, int left, int right) {
    if(left == right) {
        if(s[cur] == '1') return true;
        else return false;
    }
    else {
        int l = left, r = cur-1;
        bool c1 = sol(s, (l+r)/2, l, r);
        l = cur+1, r = right;
        bool c2 = sol(s, (l+r)/2, l, r);

        if(s[cur] == '0' && (c1 || c2)) chk = false;
        if(c1 || c2 || s[cur] == '1') return true;
        else return false;
    }
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for(int i=0; i<numbers.size(); i++) {
        long long num = numbers[i];
        string s = "";
        chk = true;

        while(num) {
            if(num % 2) s.push_back('1');
            else s.push_back('0');
            num /= 2;
        }
        int len = s.length(), cnt = 1, j = 2;
        while(len > cnt) {
            cnt += j;
            j *= 2;
        }
        for(j=0; j<cnt-len; j++) s.push_back('0');
        reverse(s.begin(), s.end());
        len = s.length();

        int l = 0, r = len-1;
        sol(s, (l+r)/2, l, r);
        if(chk) answer.push_back(1);
        else answer.push_back(0);
    }

    return answer;
}