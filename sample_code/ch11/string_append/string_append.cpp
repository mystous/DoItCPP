#include <iostream>
#include <string>

using namespace std;

int main() {
  string str1("Hello");
  str1.append(" World!");
  cout << str1 << endl;

  string str2("Hello");
  str2.append(" World!", 6, 1);
  cout << str2 << endl;

  return 0;
}
