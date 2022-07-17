#include <iostream>

using namespace std;

int sum_int(int operand1, int operand2) {
  return operand1 + operand2;
}

constexpr int sum_int_constexpr(int operand1, int operand2) {
  return operand1 + operand2;
}

int main() {
  int var1 = sum_int(4, 5);
  int var2 = sum_int(var1, 10);
  int var3 = sum_int(var1, var2);

  constexpr int var11 = sum_int_constexpr(4, 5);
  constexpr int var12 = sum_int_constexpr(var11, 10);
  constexpr int var13 = sum_int_constexpr(var11, var12);

  return 0;
}
