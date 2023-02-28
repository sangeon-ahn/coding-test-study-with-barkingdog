#include <bits/stdc++.h>
using namespace std;
/*
    0. 소수 구하기(에라토스테네스의 체)
    1. n을 k진수 string으로 전환
    2. string을 '0'을 기준으로 나누고, "1"이나 ""일 때 제외하고 vector<string>에 저장
    3. stoi 결과 소수일 시 result++

    
*/

// bool isPrime[10000];

vector<string> split(string str, char delimiter) {
    stringstream ss(str);
    string temp = "";
    vector<string> result;
    
    while (getline(ss, temp, delimiter)) {
        result.push_back(temp);
    }
    
    return result;
}

bool isPrime(long long num) {
    for (long long i = 2; i <= floor(sqrt(num)); i++) {
        if (num % i == 0) return false;
    }
    return true;
}


string convertToK(int n, int k) {
    string result = "";
    
    while (n > 0) {
        result = to_string(n % k) + result;
        n /= k;
    }
    
    return result;
}

int solution(int n, int k) {
    if (n == 1) return 0;
    int answer = 0;
    
    string s = convertToK(n, k);

    vector<string> stringS = split(s, '0');
    
    vector<long long> result;
    
    for (string ss: stringS) {
        if (ss == "" || ss == "1") continue;
        else {
            result.push_back(stoll(ss));
        }
    }
    
    for (long long num : result) {
        if (isPrime(num)) answer++;
    }
    
    return answer;
}