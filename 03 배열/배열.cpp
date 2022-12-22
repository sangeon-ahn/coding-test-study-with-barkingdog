/*
임의의 위치에 있는 원소를 확인/변경 = O(1)
원소를 끝에 추가 = O(1)
마지막 원소를 제거 = O(1)
임의의 위치에 원소를 추가/제거 = O(1)
*/

#include <iostream>
#include <string>

using namespace std;

void insert(int idx, int num, int arr[], int& len) {
  int temp[1000];
  
  for (int i = 0; i < len; i++) {
    if (i == idx) temp[i] = num;
    else temp[i] == arr[i];
  }

}

void erase(int idx, int arr[], int& len) {

}

void printArr(int arr[], int& len) {
  for (int i = 0; i < len; i++) cout << arr[i] << ' ';
  cout << "\n\n";
}

int main(void) {
  int arr[10] = {10, 50, 60, 30, 70, 20};
  int len = 6;
  insert(3, 60, arr, len);
  erase(4, arr, len);
}