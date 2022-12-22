#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  stack<int> S;
  vector<int> V;
  int answer = 0;

  for (int i = 0; i < N; i++) {
    int height;
    cin >> height;
    V.push_back(height);
  }

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      // cout << answer;
      if (V[i] >= V[j]) answer++;
      else if (V[i] < V[j]) break;
    }
  }
  cout << answer;
}

// 바킹독 풀이
stack<int> s;
int n;
long long ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  long long h;
  while (n--) {
    cin >> h;
    while (!s.empty() && s.top() <= h) {
      s.pop();
    }
    ans += s.size();
    s.push(h);
  }
  cout << ans;
  return 0;
}