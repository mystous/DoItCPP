#include <iostream>

using namespace std;

int value = 1;   // 전역 변수

int main() {
  int value = -1;   // 지역 변수

  cout << value << endl;     // 지역 변수 출력
  cout << ::value << endl;   // 전역 변수 출력

  return 0;
}
