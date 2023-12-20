#include <iostream>

using namespace std;

void sum_int(int operand1, int operand2) {
  const int var11 = 10;
  const int var12 = operand1 + 10;
  const int var13 = operand1 + operand2;
  constexpr int var14 = 20;
  // 아래 코드는 동작하지 않습니다.
  //constexpr int var15 = operand1 + 15;
  //constexpr int var16 = operand1 + operand2;
}

int main() {
  const int var1 = 10;
  const int var2 = var1 + 10;
  const int var3 = var1 + var2;
  constexpr int var4 = 20;
  constexpr int var5 = var1 + 15;
  constexpr int var6 = var1 + var4;

  sum_int(var1, var4);
  return 0;
}