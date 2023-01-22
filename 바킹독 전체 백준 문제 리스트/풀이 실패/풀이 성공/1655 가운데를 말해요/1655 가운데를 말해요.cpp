#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;
// N^2logN, N = 10만. O(N) or O(NlogN) 코드 작성해야 함.
// int check() {
//   int vSize = v.size();
  
//   if (vSize % 2 == 0) return v[vSize/2 - 1];
//   else return v[vSize/2];
// }

// int main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cin >> N;

//   for (int i = 0; i < N; i++) {
//     int a;
//     cin >> a;
//     v.push_back(a);
    
//     sort(v.begin(), v.end());
//     int result = check();
//     cout << result << '\n';
//   }
// }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  priority_queue<int, vector<int>> pq;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    pq.push(a);

    vector<int> v2;
    int size = pq.size();

    for (int i = 0; i < size / 2; i++) {
      v2.push_back(pq.top());
      pq.pop();
    }

    cout << pq.top() << '\n';
    
    for (int i = 0; i < v2.size(); i++) {
      pq.push(v2[i]);
    }
  }
}