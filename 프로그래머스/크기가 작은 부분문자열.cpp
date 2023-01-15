#include <string>
#include <vector>
using namespace std;

int solution(string t, string p) {
  int count = 0;
  // strcmp 사용해서 문자열 비교하면 간단함.
  for (int i = 0; i < t.length() - p.length() + 1; i++) {
    bool isNot = false;

    for (int j = 0; j < p.length(); j++) {
      if ((int)t[i+j] > (int)p[j]) {
        isNot = true;
        break;
      };
    }

    if (!isNot) count += 1;
  }

  return count;
}

