#include <iostream>

using namespace std;

int main() {
  int a = 0;    // a 최초 값 0
  int b = 0;    // b 최초 값 0
  int a_prefix;
  int b_postfix;

  a_prefix = ++a;     // a값을 1만큼 증가한 후에 a_prefix에 a값을 넣음
  b_postfix = b++;    // b값을 b_postfix에 넣은 후에 b값을 1만큼 증가함

  cout << "a = " << a << ", " << "a_prefix = " << a_prefix << endl;
  cout << "b = " << b << ", " << "b_postfix = " << b_postfix << endl;

  return 0;
}
