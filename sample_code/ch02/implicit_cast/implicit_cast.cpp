#include <iostream>

using namespace std;

int main() {
  float float_value = 1.5f;   // 원본 데이터는 실수형 1.5

  double double_value = float_value;  // 숫자 승격: 데이터 유실 없음
  int int_value = float_value;        // 숫자 변환: 데이터 유실 발생

  cout << "float_value: " << float_value << endl;
  cout << "double_value: " << double_value << endl;
  cout << "int_value: " << int_value << endl;

  return 0;
}
