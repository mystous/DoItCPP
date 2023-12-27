#include <iostream>

int main() {
  int i, j;

  std::cout << "Enter num_1: ";   // 문자열 출력
  std::cin >> i;   // 사용자에게 정수를 입력받아 i에 저장

  std::cout << "Enter num_2: ";   // 문자열 출력
  std::cin >> j;   // 사용자에게 정수를 입력받아 j에 저장

  std::cout << "num_1 + num_2 = " << i + j << std::endl;   // 두 수의 합 출력

  return 0;
}
