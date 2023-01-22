#include <bits/stdc++.h>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;

    /*
        일단 단순한 방법으로 풀어보자.
        y = 0에서부터 x를 증가시켜가며 d 안에 있으면 answer++
        d보다 커지면 while 빠져나온 후 y증가 후 다시 시작
        y가 d보다 커지면 while 빠져나옴
        -> 이 풀이는 시간초과.
    */

    long long y = 0;
    long long b = 0;

    while (y <= d) {
        long long remained_dist = (long long)d * d - (long long)y * y;

        answer += ((long long)sqrt(remained_dist) / (long long)k) + 1;
        y = ++b * k;
    }

    return answer;
}