#include <iostream>

using namespace std;

void func_throw() {
  cout << endl;
  cout << "func_throw() 함수 내부" << endl;
  cout << "throw -1" << endl;
  throw - 1;   // 정수 형식 예외 던지기
  cout << "after throw -1" << endl;
}

void func_2() {
  cout << endl;
  cout << "func_2() 함수 내부" << endl;
  cout << "func_throw() 호출" << endl;
  func_throw();
  cout << "after func_throw()" << endl;
}

void func_1() {
  cout << endl;
  cout << "func_1() 함수 내부" << endl;
  cout << "func_2() 호출" << endl;
  func_2();
  cout << "after func_2()" << endl;
}


int main() {
  cout << "main 내부" << endl;

  try {
    cout << "func_1() 호출" << endl;
    func_1();
  }
  catch (int exec) {   // 정수 형식 예외 받기
    cout << endl;
    cout << "catch " << exec << endl;
  }

  return 0;
}
