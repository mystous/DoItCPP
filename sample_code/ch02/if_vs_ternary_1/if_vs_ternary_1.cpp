#include <iostream>

using namespace std;

int main() {
  int a = 7;
  int b = 5;
  int result;

  if (a > b)
    result = a;    // a > b가 true이면, result에 a값 저장
  else
    result = b;    // a > b가 false이면, result에 b값 저장

  cout << "result = " << result << endl;

  return 0;
}
