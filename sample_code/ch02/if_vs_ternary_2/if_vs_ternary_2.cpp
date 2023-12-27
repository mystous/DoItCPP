#include <iostream>

using namespace std;

int main() {
  int a = 7;
  int b = 5;
  int result;

  result = a > b ? a : b;    // a > b 결과에 따라 result에 a 또는 b값 저장

  cout << "result = " << result << endl;

  return 0;
}
