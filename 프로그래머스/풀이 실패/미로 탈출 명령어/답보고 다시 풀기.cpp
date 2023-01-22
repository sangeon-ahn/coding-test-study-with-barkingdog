#include <bits/stdc++.h>
using namespace std;
/*
  dfs로 푼다. 왜냐하면 먼저 탐색해야 하는 부분이 d->l->r->u 순으로 분명하기 때문이다.
  파이썬은 문자열 비교할 때 부등호로 쉽게 바교하는데 c++은 안된다.
*/

int board[51][51];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char dir[4] = {'d', 'l', 'r', 'u'};
string answer = "z";

void dfs(int n, int m, int x, int y, int r, int c, string s, int count, int k) {
  // 불가능한 경우 컷.
  int dist = abs(r - x) + abs(c - y);

  // 도착했을 때 남은 횟수를 2로 나눈값이 1일 때
  if ((k - dist) % 2 == 1) return;

  // 카운트 + 거리 > k 일 때
  if (count + dist > k) return;

  // 도착했을 때.
  if (x == r && y == c && count == k) {
    answer = s;
    return;
  }

  for (int i = 0; i < 4; i++) {
    int nx = r + dx[i];
    int ny = c + dy[i];
    if (nx < 1 || nx > n || ny < 1 || ny > m) continue;

    // 문자열 비교
    string temp = answer;
    vector<string> v;
    v.push_back(answer);
    v.push_back(s + dir[i]);

    // sort 함수는 문자열을 오름차순해서 정렬해준다.
    sort(v.begin(), v.end());
    string temp2 = v[0];
    cout << v[0] << v[1] << '\n'; 
    if (!temp.compare(temp2)) continue;
    dfs(n, m, nx, ny, r, c, s+dir[i], count + 1, k);
  }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {

  // 거리가 더 멀면 불가능.
  int dist = abs(r - x) + abs(c - y);

  if (k < dist) {
    return "impossible";
  }


  // 도착했을 때 남은 횟수를 2로 나눈값이 1이면 불가능.
  if ((k - dist) % 2 == 1) return "impossible";

  dfs(n, m, x, y, r, c, "", 0, k);
  
  return answer;
}

int main() {
  string s = solution(3, 4, 2, 3, 3, 1, 5);
  cout << s;
}
