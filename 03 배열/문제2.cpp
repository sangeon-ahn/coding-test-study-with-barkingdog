#include <iostream>

using namespace std;

int sampleArr[5] = {20, 40, 60, 80, 50}; 

int func1(int arr[], int N) {
  int sum = 100;
  int answer = 0;

  for (int i = 0; i < N - 1; i++) {
    int otherNumber = sum - arr[i];

    for (int j = i + 1; j < N; j++) {
      if (otherNumber == arr[j]) answer = 1;
    }
  }

  return answer;
}


// 바킹독 풀이 O(N)
int cache[101];
int func2(int arr[], int N) {
  for (int i = 0; i < N; i++) {
    if (cache[100 - arr[i]]) return 1;
    cache[arr[i]] = 1;
  }
  return 0;
}

int main() {
  int arr[2] = {50};
  cout << func2(arr, 1);
}
