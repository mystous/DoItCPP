#include <iostream>

using namespace std;

void print() {
  // 함수 내부의 지역 변수
  int value = 10;

  cout << "print 함수 내부에서의 지역 변수 value: " << value << endl;
}

int main() {
  // main 함수 내부의 지역 변수
  int value = 5;

  cout << "main 함수 내부에서의 지역 변수 value: " << value << endl;

  // print 함수 호출
  print();

  // print 함수 호출 후에도 main 함수의 value에 영향을 주지 않음
  cout << "다시 main 함수 내부에서의 지역 변수 value: " << value << endl;

  return 0;
}
