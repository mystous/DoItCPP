#include <iostream>

using namespace std;

// 포인터 변수를 매개변수로 사용
void change_negative(int* _val) {
  if (*_val > 0)
  {
    *_val = -(*_val);
  }
}

int main() {
  int a = 3, b = -3;

  cout << "a : " << a << endl;
  cout << "b : " << b << endl;

  change_negative(&a);	// a 변수의 주솟값을 매개변수로 전달
  change_negative(&b);	// b 변수의 주솟값을 매개변수로 전달

  cout << "change_negative(a) : " << a << endl;
  cout << "change_negative(b) : " << b << endl;

  return 0;
}
