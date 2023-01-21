#include <bits/stdc++.h>
using namespace std;

const int MXN = 4000002;
vector<bool> seive(MXN, true);
vector<int> primes;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 2; i * i < MXN; i++) {
    if (!seive[i]) continue;
    for (int j = i * i; j < MXN; j += i) {
      seive[j] = false;
    }
  }

  for (int i = 2; i < MXN; i++) {
    if (seive[i]) primes.push_back(i);
  }
  primes.push_back(0);

  int target, st = 0, en = 1, ans = 0, tempSum = primes[0];
  cin >> target;

  while (true) {
    if (tempSum == target) {
      ans++;
      tempSum += primes[en++];
    }
    else if (tempSum < target) tempSum += primes[en++];
    else if (tempSum > target) tempSum -= primes[st++];
    
    if (en == primes.size()) { cout << en; break;}
  }

  cout << ans;
}