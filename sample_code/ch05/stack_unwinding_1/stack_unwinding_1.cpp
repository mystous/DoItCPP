#include <iostream>

using namespace std;

void func_throw() {
  cout << "func_throw()" << endl;
  cout << "throw -1" << endl;
  throw - 1;   // 정수 형식 예외 던지기
  cout << "after throw -1" << endl;
}

int main() {
  try {
    func_throw();
  }
  catch (int exec) {   // 정수 형식 예외 받기
    cout << "catch " << exec << endl;
  }

  return 0;
}
