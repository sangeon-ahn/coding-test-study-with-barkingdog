#include <bits/stdc++.h>
using namespace std;

char arr[20];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int L, C;
    cin >> L >> C;
    
    for (int i = 0; i < C; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + C);
    
    vector<int> vec(C, 1);
    
    for (int i = 0; i < L; i++) {
        vec[i] = 0;
    }
    
    do {
        vector<char> temp;
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == 0) {
              temp.push_back(arr[i]);

              if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') cnt1++;
              else cnt2++;
            }
        }
        
        if (cnt1 >= 1 && cnt2 >= 2) {
            for (int i = 0; i < temp.size(); i++) {
                cout << temp[i];
            }
            cout << '\n';
        }
    } while (next_permutation(vec.begin(), vec.end()));
}