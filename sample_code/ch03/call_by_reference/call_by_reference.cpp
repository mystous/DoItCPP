#include <iostream>

using namespace std;

// 매개변수를 레퍼런스 변수로 선언
void swap(int& ref_a, int& ref_b) {
  // 교환 전 a, b 값
  cout << "[swap func] before swap, ref_a: " << ref_a << "  ref_b : " << ref_b << endl;

  int temp = ref_a;
  ref_a = ref_b;
  ref_b = temp;

  // 교환 후 a, b 값
  cout << "[swap func] after swap, ref_a: " << ref_a << "  ref_b : " << ref_b << endl;
}

int main() {
  int a = 5;
  int b = 10;

  // swap 함수 호출 전 a, b 값
  cout << "[main] before swap, a: " << a << "  b: " << b << endl << endl;

  swap(a, b);

  // swap 함수 호출 후 a, b 값
  cout << endl << "[main] after swap, a: " << a << "  b: " << b << endl;

  return 0;
}
