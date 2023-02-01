#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0ll);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0ll);
    int idx1 = 0, idx2 = 0;
    int MAX = queue1.size()*2 + queue2.size()*2;
    while (sum1 != sum2) {
        answer++;
        if (answer > MAX)
            return -1;
        if (sum1 < sum2) {
            sum1 += queue2[idx2];
            queue1.push_back(queue2[idx2]);
            sum2 -= queue2[idx2++];
        }
        else {
            sum2 += queue1[idx1];
            queue2.push_back(queue1[idx1]);
            sum1 -= queue1[idx1++];
        }
    }
    return answer;
}