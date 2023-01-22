#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// 내 풀이. 틀림.
// void func(int num) {
//   if (num == 4) cout << 'D';
//   else if (num == 3) cout << 'C';
//   else if (num == 2) cout << 'B';
//   else if (num == 1) cout << 'A';
//   else cout << 'E';
// }

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   int a[12];
//   int s1, s2, s3 = 0;

//   cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6] >> a[7] >> a[8] >> a[9] >> a[10] >> a[11];

//   for (int i = 0; i < 4; i++) {
//     if (a[i] == 1) s1++;
//   }

//   for (int i = 4; i < 8; i++) {
//     if (a[i] == 1) s2++;
//   }

//   for (int i = 8; i < 12; i++) {
//     if (a[i] == 1) s3++;
//   }

//   func(s1);
//   func(s2);
//   func(s3);
// }

// 바킹독 풀이.
int result, input;
string res = "DCBAE";
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 3; i++) {
    result = 0;
    for (int j = 0; j < 4; j++) {
      cin >> input;
      result += input;
    }
    cout << res[result] << '\n';
  }
}


// string res 로 선언된 문자열은 인덱스 접근이 가능하다.
// 그래서 1의 개수(등)를 센 다음에 그 값을 인덱스로 하는 값을 출력한다.
// 그리고 일반 int 변수도 전역으로 선언하면 0으로 초기화된다.
