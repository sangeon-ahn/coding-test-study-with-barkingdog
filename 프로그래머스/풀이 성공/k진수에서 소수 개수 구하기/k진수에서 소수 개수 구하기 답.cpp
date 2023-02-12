#include <string>
#include <vector>

using namespace std;

int isPrime(long long num) {
    if (num == 1)
        return 0;
    if (num == 1)
        return 1;

    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }

    return 1;
}

int solution(int n, int k) {
    int answer = 0;

    string num = "";
    while (n > 0) {
        num = to_string(n % k) + num;
        n /= k;
    }

    string temp = "";
    for (int i = 0; i <= num.length(); i++) {
        if (i != num.length() && num[i] != '0') {
            temp += num[i];
            continue;
        }

        if (temp.length() > 0)
            answer += isPrime(stoll(temp));
        temp = "";
    }

    return answer;
}