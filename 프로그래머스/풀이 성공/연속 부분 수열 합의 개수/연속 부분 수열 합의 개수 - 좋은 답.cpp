#include <string>
#include <vector>
#include <set>

using namespace std;

/*
  굳이 elements X 2 배열을 만들지 않고, j % n으로 해당 인덱스 값을 구했다.
*/

int solution(vector<int> elements) {
  set<int> S;

  int n = elements.size();

  for (int i = 0; i < n; i++) {
    int sum = 0;

    for (int j = i; j < i + n; j++) {
      sum += elements[j % n];
      S.insert(sum);
    }
  }

  return S.size();
}