#include <bits/stdc++.h>
using namespace std;

int max_user = -1;
int max_value = -1;
int discounts[7];
vector<int> answer(2, 0);

void getComb(int pos, vector<vector<int>> &users, vector<int> &emoticons) {
    if (pos == emoticons.size()) {
        int total_price = 0;
        int total_user = 0;

        for (int i = 0; i < users.size(); i++) {
            int tmp = 0;
            for (int j = 0; j < emoticons.size(); j++) {
                if (discounts[j] >= users[i][0])
                    tmp += emoticons[j] * (100 - discounts[j]) / 100;
            }

            if (tmp >= users[i][1]) total_user++;
            else total_price += tmp;
        }

        answer = max(answer, {total_user, total_price});
        return;
    }

    for (int i = 1; i <= 4; i++) {
        discounts[pos] = i * 10;
        getComb(pos + 1, users, emoticons);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    getComb(0, users, emoticons);
    return answer;
}
