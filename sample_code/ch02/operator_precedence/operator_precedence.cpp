#include <iostream>

using namespace std;

int main() {
  int a = 5, b = 2, c = 8;

  // 예제 1: 우선순위와 결합 법칙
  int result_1 = a + b * c;  // *가 +보다 우선순위가 높음 (결합 법칙: 좌측에서 우측으로)
  cout << "Result 1: " << result_1 << endl;

  // 예제 2: 괄호를 사용하여 우선순위 변경
  int result_2 = (a + b) * c;  // 괄호를 사용하여 +의 우선순위를 높임
  cout << "Result 2: " << result_2 << endl;

  // 예제 3: 복합 대입 연산자
  a += b * c;  // 복합 대입 연산자 (*가 +=보다 우선순위가 높음)
  cout << "Result 3: " << a << endl;

  // 예제 4: 논리 연산자와 조건부 연산자
  bool condition = true;
  int result_4 = (condition && a > b) ? a : b;  // condition && a > b는 condition && (a > b)와 동일함 (> 가 && 보다 우선순위가 높음)
  cout << "Result 4: " << result_4 << endl;

  return 0;
}
