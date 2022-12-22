#include <iostream>
using namespace std;
using ll = long long;

int func1(int a, int b, int m) {
  int val = 1;
  while(b--) val *= a;
  return val % m;
}

ll func2(ll a, ll b, ll m) {
  ll val = 1;
  while(b--) val = val * a % m;
  return val;
}

int main() {
  cout << func1(10, 3, 3);
  cout << func2(10, 3, 3);
}