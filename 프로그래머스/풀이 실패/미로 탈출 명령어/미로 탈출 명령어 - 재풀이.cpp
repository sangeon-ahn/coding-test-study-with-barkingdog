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

bool isValid(int nx, int ny, int n, int m) {
  return nx >= 1 && nx <= n && ny >= 1 && ny <= m;
}

void dfs(int n, int m, int x, int y, int r, int c, string s, int count, int k) {
  int dist = abs(r - x) + abs(c - y);

  // 카운트 + 남은 거리 > k 일 때 패스..
  if (count + dist > k) return;

  // 도착했을 때.
  if (x == r && y == c && count == k) {
    answer = s;
    return;
  }

  // 아직 도착 안했고 더 갈 수 있을 때,
  for (int i = 0; i < 4; i++) {
    if (isValid(x + dx[i], y + dy[i], n, m) && s < answer) {
      dfs(n, m, x + dx[i], y + dy[i], r, c, s + dir[i], count + 1, k);
    }
    // // 문자열 비교
    // string temp = answer;
    // vector<string> v;
    // v.push_back(answer);
    // v.push_back(s + dir[i]);

    // // sort 함수는 문자열을 오름차순해서 정렬해준다.
    // sort(v.begin(), v.end());
    // string temp2 = v[0];
    // cout << v[0] << v[1] << '\n'; 
    // if (!temp.compare(temp2)) continue;
    // dfs(n, m, nx, ny, r, c, s+dir[i], count + 1, k);
  }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {

  int dist = abs(r - x) + abs(c - y);

  // 거리가 더 멀면 불가능.
  if (k < dist) {
    return "impossible";
  }

  // 거리가 홀수면 k도 홀수여야 하고, 짝수면 k도 짝수여야 한다. 격자 구조에서, 거리가 3인데 k가 5인 경우, 2번만에 목적지 한칸 전까지 올 수 있고, 나머지 3번 중 2번은 왔다갔다 해서 제자리를 유지하고, 1번은 목적지로 이동하면 가능하다.
  // 하지만 k가 4면 이게 불가능하다.
  if ((k - dist) % 2 == 1) return "impossible";

  /*
    (n, m): 미로 크기
    (x, y): 출발 위치
    (r, c): 탈출 위치
    "": 초기 이동정보
    0: 이동한 횟수
    k: 이동해야할 횟수
  */
  dfs(n, m, x, y, r, c, "", 0, k);
  
  return answer;
}

int main() {
  string s = solution(3, 4, 2, 3, 3, 1, 5);
  cout << s;
}
