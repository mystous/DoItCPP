#include <iostream>

using namespace std;

// 단항 왼쪽 폴드 표현식
template<typename... numbers>
double unary_left(numbers... num_list) {
  return (... / num_list );
}

// 단항 오른쪽 폴드 표현식
template<typename... numbers>
double unary_right(numbers... num_list) {
  return (num_list / ...);
}

// 이항 왼쪽 폴드 표현식
template<typename... numbers>
double binary_left(numbers... num_list) {
  return (10.0 / ... / num_list);
}

// 이항 오른쪽 폴드 표현식
template<typename... numbers>
double binary_right(numbers... num_list) {
  return (num_list / ... / 10.0);
}

int main() {

  cout << "단항 왼쪽 폴드 표현식: " << 
    unary_left(1.0, 2.0, 3.0, 4.0, 5.0, 6.0) << endl;

  cout << "단항 오른쪽 폴드 표현식: " <<
    unary_right(1.0, 2.0, 3.0, 4.0, 5.0, 6.0) << endl;

  cout << "이항 왼쪽 폴드 표현식: " <<
    binary_left(1.0, 2.0, 3.0, 4.0, 5.0, 6.0) << endl;

  cout << "이항 오른쪽 폴드 표현식: " <<
    binary_right(1.0, 2.0, 3.0, 4.0, 5.0, 6.0) << endl;

  return 0;
}