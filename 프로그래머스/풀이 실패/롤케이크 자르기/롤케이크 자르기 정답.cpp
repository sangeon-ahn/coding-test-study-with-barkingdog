#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> m1;
    map<int, int> m2;
    for (int& i : topping) {
        m2[i]++;
    }
    for (int i = 0; i < topping.size() - 1; i++) {
        m1[topping[i]]++;
        m2[topping[i]]--;
        if (m2[topping[i]] == 0) {
            m2.erase(topping[i]);
        }
        if (m1.size() == m2.size()) answer++;
    }
    return answer;
}