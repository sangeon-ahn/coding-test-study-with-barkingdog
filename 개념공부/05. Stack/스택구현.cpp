#include <iostream>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x) {
  dat[pos] = x;
  pos++;
}

void pop() {
  if (pos != 0) pos--;
}

int top() {
  if (pos != 0) return dat[pos - 1];
}

void test() {

}

int main() {

}