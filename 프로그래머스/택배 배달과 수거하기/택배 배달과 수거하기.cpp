#include <bits/stdc++.h>
using namespace std;

int cap = 2;
int n = 7;
vector<int> deliveries = {1, 0, 2, 0, 1, 0, 2};
vector<int> pickups = {0, 2, 0, 1, 0, 2, 0};

bool isAllZero(vector<int> v1, vector<int> v2) {
  int a = 0;
  for (int v: v1) {
    a += v;
  }
  for (int v: v2) {
    a += v;
  }

  return a == 0;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    // 배달할거와 수거할게 없을 때까지 계속.
    while (!isAllZero(deliveries, pickups)) {
      int remained_deliver = cap;
      int take_count = cap;

      int first_place_to_deliver;
      int first_place_to_take;

      bool is_first_deliver = true;
      bool is_first_take = true;

      // 배달해야할 수량을 센터에서 가장 먼 곳부터 파악한다.
      for (int i = deliveries.size() - 1; i >= 0; i--) {
        if (remained_deliver == 0) break;
        if (deliveries[i] == 0) continue;

        if (is_first_deliver) {
          is_first_deliver = false;
          first_place_to_deliver = i;
        }

        if (remained_deliver >= deliveries[i]) {
          remained_deliver -= deliveries[i];
          deliveries[i] = 0;
        }

        else if (remained_deliver < deliveries[i]) {
          deliveries[i] -= remained_deliver;
          remained_deliver = 0;
        }
      }

      // 수거해야 할 수량을 센터에서 가장 먼 곳부터 파악한다.
      for (int i = pickups.size() - 1; i >= 0; i--) {
        if (take_count == 0) break;
        if (pickups[i] == 0) continue;

        if (is_first_take) {
          is_first_take = false;
          first_place_to_take = i;
        }

        if (take_count >= pickups[i]) {
          take_count -= pickups[i];
          pickups[i] = 0;
        }

        else if (take_count < pickups[i]) {
          pickups[i] -= take_count;
          take_count = 0;
        }
      }

      answer += 2 * (max(first_place_to_deliver, first_place_to_take) + 1);
    }

    return answer;
}


int main() {
  cout << solution(cap, n, deliveries, pickups);
}
