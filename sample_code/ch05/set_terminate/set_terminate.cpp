#include <iostream>
#include <cstdlib>  // exit와 set_terminate 함수 사용을 위해 추가

using namespace std;

// 종료 처리 함수 
void myterminate() {
  cout << "myterminate called" << endl;
  exit(-1);      // 프로그램을 비정상적으로 종료
}

int main(void) {
  set_terminate(myterminate);    // 종료 처리 함수를 myterminate로 지정

  throw 1;    // 처리되지 않는 예외를 던짐

  return 0;   // 이 줄은 실행되지 않음, 위에서 예외가 던져졌기 때문
}