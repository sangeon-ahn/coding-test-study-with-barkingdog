#include <bits/stdc++.h>
using namespace std;
int N, M;
int nums[10]; 
int idxes[10]; // idxes[i]: 순열의 i+1번째 숫자의 인덱스 위치, ex)idxes[2] = 3 이라면 순열의 3번째 숫자의 nums상에서 인덱스는 3이다. 
bool isUsed[10]; // isUsed[i]: nums의 i번째 숫자가 사용중인지를 나타냄. ex)isUsed[0] = true 이라면 nums의 0번째 숫자는 사용중.

void backtracking(int size) {
    if (size == M) {
        for (int i = 0; i < M; i++) {
            cout << nums[idxes[i]] << ' ';
        }        
        cout << '\n';
        return;
    }
    
    int temp = 0;
    int st = 0;
    if (size != 0) st = idxes[size - 1] + 1;
    
    for (int i = st; i < N; i++) {
        // 사용중이지 않고, 중복 순열이 아니고, 수열의 이전 수보다 다음 수가 될 숫자가 같거나 큰 경우만 진행
        if (!isUsed[i] && temp != nums[i]) {
            temp = nums[i];
            idxes[size] = i;
            isUsed[i] = true;
            backtracking(size + 1);
            isUsed[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    
    sort(nums, nums + N);
    
    backtracking(0);
}