#include <string>
#include <vector>
#include <math.h>
using namespace std;
    // 0번째: 1 : 1
    // 1번째: 11011 : 5
    // 2번째: 11011 11011 00000 11011 11011 : 1번째 + 1번째 + 00000 * 1개 + 1번째 + 1번째
    // 3번째: 11011 11011 00000 11011 11011 : 2번째 + 2번째 + 00000 * 5개 + 2번째 + 2번째                                 : 125
    // n번째:                                 : 5^n
    // 테스트케이스 6~10번 시간초과

string dp[21];
string dpZeros[21];

int solution(int n, long long l, long long r) {
    int answer = 0;
    
    dp[0] = "1";
    dp[1] = "11011";
    dpZeros[1] = "0";
    
    for (int i = 2; i <= n; i++) {
        dpZeros[i] = dpZeros[i - 1] + dpZeros[i - 1] + dpZeros[i - 1] + dpZeros[i - 1] + dpZeros[i - 1];
        dp[i] = dp[i - 1] + dp[i - 1] + dpZeros[i] + dp[i - 1] + dp[i - 1];
    }
    
    for (int i = l - 1; i < r; i++) {
        if (dp[n][i] == '1') answer++;
    }
    
    return answer;
    

}