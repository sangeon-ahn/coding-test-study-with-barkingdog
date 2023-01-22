#include <iostream>
using namespace std;

int main(void) {
  int arr[10] = {3, 5, 7, 13, 18, 22, 36, 77, 103, 144};

  int left = 0;
  int right = 9;
  int mid = left + (right - left) / 2;
  
  while (left < right) {
    if (arr[mid] == 7) {
      cout << 1;
      return 1;
    }

    else if (arr[mid] > 7) {
      right = mid - 1;
      mid = left + (right - left) / 2;
    }

    else if (arr[mid] < 7) {
      left = mid + 1;
      mid = left + (right - left) / 2;
    }
  }
  cout << 0;
  return 0;
}