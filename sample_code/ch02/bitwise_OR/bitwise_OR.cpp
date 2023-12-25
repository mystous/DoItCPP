#include <iostream>
#include <bitset>

using namespace std;

int main() {
  int a = 13;
  int b = 27;
  int c = a | b; // 비트 연산자 OR 사용

  cout << "a = " << bitset<8>(a) << " : " << a << endl;
  cout << "b = " << bitset<8>(b) << " : " << b << endl;
  cout << "c = " << bitset<8>(c) << " : " << c << endl;

  return 0;
}
