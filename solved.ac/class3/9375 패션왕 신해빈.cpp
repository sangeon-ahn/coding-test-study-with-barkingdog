#include <bits/stdc++.h>
using namespace std;

int N;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int clothes;
        cin >> clothes;
        
        int sorts = 0;
        map<string, int> m;

        for (int i = 0; i < clothes; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            if (m[s2] == 0) {
                sorts++;
            }
            m[s2]++;
        }
        int sum = 0;
        vector<pair<string, int>> vec(m.begin(), m.end());

        for (int i = 1; i <= sorts; i++) {
            // sorts개 종류 중 i개 입을 때,
            if (i == 1) sum += clothes;
            // 2개 이상 입을 때.
            else {
                vector<int> temp;
                temp.assign(sorts, 1);
                for (int j = 0; j < i; j++) {
                    temp[j] = 0;
                }
                do {
                    int num = 1;
                    for (int i = 0; i < temp.size(); i++) {
                        if (temp[i] == 0) {
                            num = num * vec[i].second;
                        }
                    }
                    sum += num;
                } while (next_permutation(temp.begin(), temp.end()));
            }
        }
        cout << sum << '\n';
    }
}