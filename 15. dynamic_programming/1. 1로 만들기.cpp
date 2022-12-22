#include <iostream>
#include <queue>
using namespace std;

int N;
int isNotOne = true;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  queue<pair<int, int>> Q;
  
  Q.push({N, 0});

  while (true) {
    int n = Q.front().first;
    int order = Q.front().second;
    Q.pop();

    if (n == 1) {
      cout << order;
      break;
    }
    
    int tmp_n;
    
    if (n % 3 == 0) {
      tmp_n = n / 3;

      if (tmp_n == 1) {
        cout << order + 1;
        break;
      } else {
        Q.push({tmp_n, order + 1});
      }
    }

    if (n % 2 == 0) {
      tmp_n = n / 2;

      if (tmp_n == 1) {
        cout << order + 1;
        break;
      } else {
        Q.push({tmp_n, order + 1});
      }
    }

    tmp_n = n - 1;
    if (tmp_n == 1) {
      cout << order + 1;
      break;
    } else {
      Q.push({tmp_n, order + 1});
    }
  }
}