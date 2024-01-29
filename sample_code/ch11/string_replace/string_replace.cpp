#include <iostream>
#include <string>

using namespace std;

int main() {
  string str = "Hello, world!";
  cout << "Original string: " << str << std::endl;

  // 문자열 일부분을 교체
  str.replace(7, 5, "C++");

  cout << "Replaced string: " << str << endl;
  return 0;
}
