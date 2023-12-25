#include <iostream>

using namespace std;

int add(int x, int y) {   // add 함수 안에서만 유효
  return x + y;
}

int main() {
  int x, y;   // main 함수 안에서만 유효
  x = 1;
  y = 2;

  // x, y 값이 add 함수의 매개변수 x, y로 복사
  cout << "result : " << add(x, y) << endl;

  return 0;
}
