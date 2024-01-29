#include <iostream>
#include <cmath>
#include <numbers>

using namespace std;

int main() {
  double x = 2;
  double y = 3;
  cout << "x = " << x << ", " << "y = " << y << endl;
  cout << "pow(x, y) = " << pow(x, y) << endl;
  cout << "sqrt(x) = " << sqrt(x) << endl;
  cout << "log(x) = " << log(x) << endl;
  cout << endl;

  x = 2.847;
  y = -3.234;
  cout << "x = " << x << ", " << "y = " << y << endl;
  cout << "ceil(x) = " << ceil(x) << ", ceil(y) = " << ceil(y) << endl;
  cout << "floor(x) = " << floor(x) << ", floor(y) = " << floor(y) << endl;
  cout << "round(x) = " << round(x) << ", round(y) = " << round(y) << endl;
  cout << "abs(x) = " << abs(x) << ", abs(y) = " << abs(y) << endl;
  cout << endl;

  cout << "PI = " << numbers::pi << endl;
  cout << "sin(PI/3) = " << sin(numbers::pi / 3) << endl;
  cout << "cos(PI/3) = " << cos(numbers::pi / 3) << endl;
  cout << "tan(PI/3) = " << tan(numbers::pi / 3) << endl;

  return 0;
}
