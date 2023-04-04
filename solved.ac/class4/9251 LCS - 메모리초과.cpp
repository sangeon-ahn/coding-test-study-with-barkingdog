#include <bits/stdc++.h>
using namespace std;

string a, b;
/*
    방법 1: a에서 긴 수열부터 뽑아낸 후 바로 b로 만들 수 있는 지 확인
        => a에서 x길이의 수열 뽑아냄 -> b에서 x길이인 부분수열 전부 생성하면서 하나하나 비교. 굳이 바이너리 서치 하느라 logn만큼 사용할 필요 없음.
    방법 2: a, b에서 모든 수열 구한 후, a,b중 길이가 더 짧은 문자열의 부분수열을 택해서 이것중 가장 긴 부분수열부터 이진탐색. 
     => 이게 더 시간 많이걸림.
*/

vector<string> strings[1010];
int prev = 0;
bool vis[1010];
bool check(string candi) {
    if (vis[candi.size() + 1]) {
      strings[candi.size() + 1].clear();
      vis[candi.size()] = true;
      vis[candi.size() + 1] = false;
    }
    
    if (strings[candi.size()].size() == 0) {
        // 부분수열 만들기
        vector<int> vec;
        vec.assign(b.size(), 1);
        for (int i = 0; i < candi.size(); i++) {
            vec[i] = 0;
        }
        
        do {
            string temp = "";
            for (int i = 0; i < vec.size(); i++) {
                if (vec[i] == 0) temp += b[i];
            }
            strings[candi.size()].push_back(temp);
            if (candi == temp) {
                cout << temp.size();
                return true;
            }
        } while (next_permutation(vec.begin(), vec.end()));
        sort(strings[candi.size()].begin(), strings[candi.size()].end());
        return false;
    }
    
    else {
      bool result = binary_search(strings[candi.size()].begin(), strings[candi.size()].end(), candi);
      if (result) {
        cout << candi.size();
        return true;
      }
      return false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    if (a.size() > b.size()) {
      string t = a;
      a = b;
      b = t;
    }
    vis[a.size() + 1] = true;
    for (int i = a.size(); i > 0; i--) {
        vector<int> vec;
        vec.assign(a.size(), 1);
        
        for (int j = 0; j < i; j++) {
            vec[j] = 0;
        }
        
        do {
            string temp = "";
            for (int i = 0; i < vec.size(); i++) {
                if (vec[i] == 0) {
                    temp += a[i];
                }
            }
            
            bool res = check(temp);
            if (res) return 0;
        } while (next_permutation(vec.begin(), vec.end()));
    }
}