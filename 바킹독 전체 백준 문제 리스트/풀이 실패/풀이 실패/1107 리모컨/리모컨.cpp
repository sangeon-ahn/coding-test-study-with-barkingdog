#include <bits/stdc++.h>
using namespace std;

bool canPress[10] = {true, };

int getSize(int n) {
  if (n == 0) return 1;
    int result = 0;
    while (n > 0) {
        n /= 10;
        result++;
    }
    return result;
}

bool check(int n) {
    // n 자릿수가 canPress에서 false 하나라도 있으면 false 반환
    int size = getSize(n);
    while (size > 0) {
        int a = n / pow(10, size - 1);
        if (!canPress[a]) return false;
        n -= pow(10, size - 1) * a;
        size--;
    }
    return true;
}

int getAnswer(int n1, int n2) {
    return abs(n1 - n2) + getSize(n1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    
    // memset(canPress, true, sizeof(canPress));
    fill(canPress, canPress + 10, true);
    
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        canPress[a] = false;
    }
    
    // 목표 숫자와 가장 가까이 간 후, + 혹은 -를 한다.
    // 초기 숫자 : 100
    // 목표 숫자: 5500
    // 0~9(특정 숫자 제외) 로 5500에 가장 가깝게 숫자를 만드는 법
    // 브루트포스: 모든 4자리 숫자 만든 후 차이가 가장 작은 수를 구하기
    // N = 50,000, 10^5 = 100,000 
    
    /*
        1. 제시된 숫자의 자릿수 구하기
        2. 자릿수에 맞춰 임시 수 구하기
        3. 차이 비교 후 더 작으면 교체
        4. 3 반복 수행 후 결과 수 + 차이 = 답
    */
    int size = getSize(N);
    int minDiff = 0x7f7f7f7f;
    int num = -1;
    for (int i = 0; i < pow(10, size); i++) {
        if (!check(i)) continue;
        int diff = abs(N - i);
        if (minDiff > diff) {
            num = i;
            minDiff = diff;
        }    
    }
    
    // cout << num << '\n';
    if (num != -1) {
      int tempAnswer = getAnswer(num, N);
      if (tempAnswer > abs(100 - N)) {
        cout << abs(100 - N);
      }
      else cout << tempAnswer;
    }
    else cout << abs(100 - N);
}
