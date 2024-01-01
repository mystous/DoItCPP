#include <iostream>

using namespace std;

int main() {
  try {
    int input;
    cout << "정수 중 하나를 입력해보세요 : ";
    cin >> input;

    // 입력받은 숫자가 양수이면
    if (input > 0) {
      cout << "throw 1" << endl;
      throw 1;   // 예외 1 발생(정수 형식 예외)
    }

    // 입력받은 숫자가 음수이면
    if (input < 0) {
      cout << "throw -1.0f" << endl;
      throw - 1.0f;   // 예외 1.0f 발생(부동소수점 형식 예외)
    }

    // 입력받은 숫자가 0이면
    if (input == 0) {
      cout << "throw Z" << endl;
      throw 'Z';   // 예외 Z 발생 (문자 형식 예외)
    }
  }
  catch (int a) {   // 정수 형식 예외 받기
    cout << "catch " << a << endl;
  }
  catch (...) {   // 처리되지 않은 나머지 예외 모두 받기
    cout << "catch all" << endl;
  }

  return 0;
}
