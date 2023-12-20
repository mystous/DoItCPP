#include <iostream>

using namespace std;
const int loop_count = 5;
const int change_count = 5;

class vending_machine {
public:
  vending_machine() : price{ 450, 390, 11340, 900, 150 } {};
  void stack_drink() {};

  void sale_using_lambda_with_this(int payments[], int changes[]) {
    for (int i = 0; i < loop_count; ++i) {
      cout << payments[i] << "원을 내고 " << price[i] << "원 짜리 음료를 선택했습니다." << endl;
      cout << "거슬러 받을 돈은 " << [&](int payment)->int {
        int change = payment - this->price[i];
        changes[0] = change / 1000;
        change %= 1000;
        changes[1] = change / 500;
        change %= 500;
        changes[2] = change / 100;
        change %= 100;
        changes[3] = change / 50;
        change %= 50;
        changes[4] = change / 10;
        return payment - this->price[i];
      }(payments[i]) << "입니다." << endl;
      cout << "천원 짜리 " << changes[0] << "개, 오백원 짜리 " << changes[1] << "개, 백원 짜리 " << changes[2] << "개, ";
      cout << "오십원 짜리 " << changes[3] << "개, 십원 짜리" << changes[4] << "개로 받습니다." << endl;
    }
  };
private:
  int price[loop_count];
};

int main() {
  vending_machine vending_machine_object = vending_machine();
  int payments[loop_count] = { 1000, 500, 15000, 1000, 200 };
  int changes[change_count] = { 0, };

  cout << endl << "람다 표현식에서 this 포인터 사용하기" << endl;
  cout << "--------------------------------------------------------------------" << endl;
  vending_machine_object.sale_using_lambda_with_this(payments, changes);
  return 0;
}
