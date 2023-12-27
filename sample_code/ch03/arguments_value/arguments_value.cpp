#include <iostream>

using namespace std;

void change_negative(int _val) {
  if (_val > 0) {
    _val = -_val;
  }
}

int main() {
  int a = 3, b = -3;

  cout << "a : " << a << endl;
  cout << "b : " << b << endl;

  change_negative(a);
  change_negative(b);

  cout << "change_negative(a) : " << a << endl;
  cout << "change_negative(b) : " << b << endl;

  return 0;
}
