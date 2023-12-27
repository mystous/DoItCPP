#include <iostream>

using namespace std;

int main() {
  int i = 0;
  while (i < 0) { // 조건식이 거짓이므로 반복문은 전혀 실행되지 않는다.
    cout << "i is less than 0" << endl;
    i++;
  }

  int j = 0;
  do {
    cout << "j is less than 0" << endl;
    j++;
  } while (j < 0); // 조건식이 거짓이지만 반복문은 1회 실행된다.


  return 0;
}
