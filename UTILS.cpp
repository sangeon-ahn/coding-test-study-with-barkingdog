#include <bits/stdc++.h>
using namespace std;

// 1. 문자열 delimiter로 나누기.
vector<string> split(string str, char delimiter) {
  string tmp;
  stringstream st(str);
  vector<string> result;

  while (getline(st, tmp, delimiter)) {
    result.push_back(tmp);
  }

  return result;
}

// 2. true: swap X, false: swap O.
bool compare(string s1, string s2) {
  return s1 < s2;
}

int main() {
  vector<string> v = {"A910", "145C"};
  sort(v.begin(), v.end(), compare);
  for (string s: v) {
    cout << s;
  }
}

// 3. set for문 돌리기
int main() {
  set<int> s;
  for (auto it = s.begin(); it != s.end(); it++) {
    cout << *it;
  }
}

// 4. map for문 돌리기
int main() {
  map<char, int> m;
  for (auto it = m.begin(); it != m.end(); it++) {
    cout << it->first;
    cout << it->second;
  }
}

// 5. 타입을 알아내는 방법
int main() {
  char c = '0';
  typeid(c); // char
}

// 6. pair를 sort로 정렬하면 앞에서부터 오름차순 정렬된다.
int main() {
  pair<int, int> arr[10];
  arr[0] = {2, 2};
  arr[1] = {1, 3};
  arr[2] = {1, 1};
  arr[3] = {1, 2};

  sort(arr, arr + 5);
  for (auto a: arr) {
    cout << a.first << ' ' << a.second << '\n';
  }
}

// 7. string에 char 더할 수 있다.
int main() {
  string a = "";
  cout << a + 'c';

  // "abc" + 'c'는 안된다.
}

// 8. isdigit(int c): 매개변수로 들어온 char 타입이 10진수 숫자로 변경이 가능하면 true, 아니면 false 반환

/*
  9. 거듭제곱 구할 때,
  b가 짝수: a^b = a^(2/b) * a^(2/b),
  b가 홀수: a^b = a^(2/b) * a^(2/b) * a
  이 두 식을 이용해서 재귀함수 형태로 a^b를 빠르게 구할 수 있다.
*/

// 10. 에라토스테네스의 체로 소수 구하기
const int MXN = 10000;
vector<bool> seive(MXN, true);
for (int i = 2; i * i < MXN; i++) {
    if (!seive[i]) continue;
    for (int j = i * i; j < MXN; j += i) {
      seive[j] = false;
    }
  }

// 11. map을 vector에 넣는 법
map<int, int> ma;
for(int i = 0; i < tangerine.size(); i++){
    ma[tangerine[i]]++;
}
vector<pair<int,int>> vec(ma.begin(), ma.end());

// 12. 두 수의 최대공약수 구하는 법
int gcd2(int a, int b)
{
	if (a % b == 0)
    	return b;
	else
    	return gcd2(b, a % b);
}

// 13. set에서 데이터 뽑는 법
int main() {
  set<int> s;
  s.insert(1);

  auto it = s.find(1);
  cout << *it;
}

// 14. pair 내림차순 정렬
vector<pair<int, int>> v;
sort(v.begin(), v.end(), greater<pair<int, int>>());

// 15. 조합 구하기. ex)5개 중 2개 고르기
    int weights[5] = {1, 2, 3, 4, 5};
    vector<int> v(5, 1);
    v[0] = 0;
    v[1] = 0;
    do {
        vector<int> temp;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 0) {
                temp.push_back(weights[i]);
            }
        }
    } while(next_permutation(v.begin(), v.end()));

// 16. 순열 구하기. ex) 두 자리가 있고, 각 자리는 3가지의 경우의 수가 있으므로,
  // 00 ~ 22까지 총 9개의 순열 생성
for (int j = 0; j < 9; j++) {
  int brute = j;
  vector<int> orders;

  for (int k = 0; k < 2; k++) {
      int idx = brute % 3;
      brute /= 3;
      orders.push_back(dist[idx]);
  }
}

// 17. 재귀 및 dfs
ll POW(ll a, ll b, ll m) {
  if (b == 1) return a % m;

  // a^b = a^(b/2) + a^(b/2)이다. 그래서 반쪽에 해당하는 val를 구한 후, val * val을 해준다.
  ll val = POW(a, b/2, m);
  val = val * val % m;
  
  // 짝수인 경우에는 구한 값을 바로 리턴하지만, b가 홀수면 한번 더 곱한걸 나누고 리턴한다.
  if (b % 2 == 0) return val;
  return val * a % m;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll a, b, c;

  cin >> a >> b >> c;
  cout << POW(a, b, c);
}

// 18. C++은 배열, 벡터의 -1 인덱스 접근이 안된다.

// 19. binary_search, lower_bound, upper_bound
int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  /*
    binary_search(from, to, value): from에서 to 사이의 수 중에 value가 있으면 true, 없으면 false 리턴.
    binary_search(arr, arr + 5, 3) = true;
    binary_search(arr, arr + 5, 6) = false;
  */ 

 /*
  lower_bound(from, to, value): from에서 to 사이의 수 중에 value와 같은 수 있으면 해당 수의 주소 반환. 없으면 value보다 다음으로 큰 수의 주소 출력.
  
  upper_bound(from, to, value): from에서 to 사이의 수 중에 value보다 다음으로 큰 수의 주소 출력.
 */
}

