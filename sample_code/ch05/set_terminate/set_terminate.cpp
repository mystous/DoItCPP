#include <iostream>
#include <exception>  

using namespace std;

// 종료 처리 함수 
void myterminate() {
  cout << "myterminate called" << endl;
  exit(-1);      // 프로그램 종료
}

int main(void) {
  set_terminate(myterminate);    // 종료 처리 함수 지정

  throw 1;    // 처리되지 않는 예외 발생

  return 0;
}
