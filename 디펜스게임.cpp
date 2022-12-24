#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 우선순위 큐 몰랐을 때 풀이, 시간초과.
int solution(int n, int k, vector<int> enemy) {
    if (enemy.size() <= k) return enemy.size();

    int answer = 0;
    int arr[enemy.size()];

    for (int i = 0; i < enemy.size(); i++) {
      if (i < k) arr[i] = 0;
      else arr[i] = 1;
    }

    do {
      vector<int> v;
      int count = 0;
      int remain_num = n;

      for (int i = enemy.size() - 1; i >= 0; i--) {
        if (arr[i] == 0) {
          v.push_back(i);
        }
      }

      for (int i = 0; i < enemy.size(); i++) {
        if (v.size() && v.back() == i) {
          v.pop_back();
          count++;
        }

        else if (remain_num > enemy[i]) {
          remain_num -= enemy[i];
          count++;
        }

        else {
          break;
        }
      }

      answer = max(answer, count);
    } while (next_permutation(arr, arr + enemy.size()));

    return answer;
}

