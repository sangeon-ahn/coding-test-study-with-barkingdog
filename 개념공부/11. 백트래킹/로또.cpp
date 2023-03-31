#include <bits/stdc++.h>
using namespace std;

int k;
int nums[14];
bool isUsed[14];
int idxes[14];

void backtracking(int size) {
    if (size == 6) {
        for (int i = 0; i < 6; i++) {
            cout << nums[idxes[i]] << ' ';
        }
        cout << '\n';
        return;
    }

    int st = 0;
    if (size != 0) st = idxes[size - 1] + 1;
    for (int i = st; i < k; i++) {
      if (isUsed[i]) continue;
      idxes[size] = i;
      isUsed[i] = true;
      backtracking(size + 1);
      isUsed[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        cin >> k;
        if (k == 0) break;

        for (int i = 0; i < k; i++) {
            cin >> nums[i];
        }

        sort(nums, nums + k);

        backtracking(0);
        fill(nums, nums + 14, 0);
        fill(isUsed, isUsed+14, false);
        fill(idxes, idxes+14, 0);
        cout << '\n';
    }
}