#include <iostream>
#include <stack>
#include <vector>
using namespace std;


// 시간초과
// int main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   int N;
//   cin >> N;
//   stack<int> S;
//   vector<int> V;

//   for (int i = 0; i < N; i++) {
//     int top;
//     cin >> top;

//     while (!S.empty()) {
//       if (S.top() > top) {
//         cout << i - V.size() << ' ';
//         break;
//       }
//       else {
//         V.push_back(S.top());
//         S.pop();
//       }
//     }
//     if (S.empty()) cout << "0 ";

//     while (!V.empty()) {
//       S.push(V.back());
//       V.pop_back();
//     }

//     S.push(top);
//   }
// }

// 바킹독 풀이
#define X first
#define Y second

int N;
stack<pair<int, int>> tower;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  tower.push({100000001, 0});
  
  for (int i = 1; i <= N; i++) {
    int height;
    cin >> height;

    while (tower.top().first < height) {
      tower.pop();
    }
    cout << tower.top().second << "+ ";
    tower.push({height, i});
  }

}

// 스택에서 pop한걸 다시 스택에 안넣어도 되는 이유는 pop되는 조건이 현재 높이보다 낮은 경우에 pop시키는 거니까 그 이후에 들어오는 타워 높이가 만약 직전 타워의 높이보다 높은 경우에는 나머지 pop된 타워 높이가 다 그 타워보다 낮을거니까 안넣어도 되고, 직전 타워가 더 높으면 직전타워를 출력하면 되서 다시 넣어줄 필요가 없다.