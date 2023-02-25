#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    long long sum1 = 0;
    long long sum2 = 0;
    
    queue<int> q1;
    queue<int> q2;
    
    for (int num: queue1) {
        q1.push(num);
        sum1 += num;
    }
    
    for (int num: queue2) {
        q2.push(num);
        sum2 += num;
    }
    
    int count = 0;
    
    while (sum1 != sum2) {
        if (count > 1000000) return -1;
        if (sum1 < sum2) {
            int n = q2.front(); q2.pop();
            q1.push(n);
            sum2 -= n;
            sum1 += n;
        }
        else if (sum1 > sum2) {
            int n = q1.front(); q1.pop();
            q2.push(n);
            sum1 -= n;
            sum2 += n;
        }
        count++;
    }
    answer = count;
    return answer;
}