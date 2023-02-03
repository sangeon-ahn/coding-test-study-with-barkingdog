#include <bits/stdc++.h>
using namespace std;

int N;
int d[100010];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 1; i <= N; i++) {
    int a;
    cin >> a;
    
    d[i] = max(a, d[i - 1] + a);
  }

  cout << *max_element(d + 1, d + N + 1);
}