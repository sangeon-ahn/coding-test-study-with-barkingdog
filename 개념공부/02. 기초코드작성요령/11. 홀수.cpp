#include <iostream>

using namespace std;

int odd_sum;
int num;
int min_odd_num = 99999999;
int odd_count;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 7; i++) {
    cin >> num;
    if (num % 2 == 1) {
      odd_sum += num;
      odd_count++;
      if (min_odd_num > num) min_odd_num = num;
    }
  }
  if (!odd_count) cout << -1;
  else cout << odd_sum << '\n' << min_odd_num;
}