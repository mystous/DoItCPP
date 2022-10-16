#include <iostream>
#include <string>

using namespace std;

int main() {
  string str1("");
  cout << str1 << endl;

  cout << std::boolalpha;
  cout << str1.empty() << endl; // true or false 출력

  return 0;
}
