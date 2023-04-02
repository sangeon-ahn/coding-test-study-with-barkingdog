#include <bits/stdc++.h>
using namespace std;

int two[501]; // two[i] i 소인수분해 시 2의 개수
int five[501]; // five[i] i 소인수분해 시 5의 개수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    
    two[2] = 1;
    five[5] = 1;
    
    for (int i = 1; i <= N; i++) {
        if (i % 2 == 0) {
            two[i] = two[i/2] + 1;
        }else {
            two[i] = 0;
        }
        
        if (i % 5 == 0) {
            five[i] = five[i/5] + 1;
        }else {
            five[i] = 0;
        }
    }
    int twoSum = 0;
    int fiveSum = 0;
    for (int i = 1; i <= N; i++) {
        twoSum += two[i];
        fiveSum += five[i];
    }
    cout << min(twoSum, fiveSum);
}