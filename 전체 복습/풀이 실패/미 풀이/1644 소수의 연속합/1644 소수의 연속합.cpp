#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;
int arr[4000001];
int ans;
void getSosu(int n) {
  for (int i = 2; i <= n; i++) {
    arr[i] = i;
  }

  for (int i = 2; i <= sqrt(n); i++) {
    if (arr[i] == 0) continue;
    for (int j = 2 * i; j <= n; j += i) {
      arr[j] = 0;
    }
  }

  for (int i = 2; i <= n; i++) {
    if (arr[i] != 0) {
      v.push_back(i);
    }
  }
}

int getSum(int l, int r) {
  int sum = 0;

  for (int i = l; i <= r; i++) {
    sum += v[i];
  }

  return sum;
}

void getAnswer(int n) {
  // n보다 같거나 작은 소수들을 구한다.
  // 소수 구하는 법: 소수: 1과 자기 자신 외에 나눠지는게 없는 수. 
  getSosu(n);
  
  int left = 0;
  int right = 0;

  while (v[left] < n) {
    int sum = getSum(left, right);
    cout << sum << '\n';
    if (sum > n) left++;
    else if (sum < n) right++;
    else {
      ans++;
      right++;
    }
  }

  if (v[left] == n) ans++;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  
  getAnswer(N);
  cout << ans;
}