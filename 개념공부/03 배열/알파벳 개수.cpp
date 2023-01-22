#include <string>
#include <iostream>

using namespace std;

int arr[26]; // 전역변수로 선언하면 초기값 0으로 세팅된다.
int main(void) {
  string a;
  cin >> a;


  for (auto c:a) {
    arr[c - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    cout << arr[i] << ' ';
  }
}