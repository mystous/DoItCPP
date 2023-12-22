#include <iostream> 
using namespace std;

class bank {
private:
  int safe; //금고 

public:
  bank() { safe = 0; };                 //기본 생성자  
  ~bank() {};
  void use_counter(int _in, int _out);  //입출금 창구 함수 
  void transfer_account(int safe);      // 계좌 변경 함수
  bank& deposit_interest(int interest); // 이자 입금
  bank& withdraw_utility(int utility);  // 공과금 출금
  bank& withdraw_tax(int tax);          // 세금 출금
  int get_safe() { return safe; };      // 금고 금액 반환
};

void bank::use_counter(int _in, int _out) {
  safe += _in;
  safe -= _out;
}

void bank::transfer_account(int safe) {
  this->safe = safe;
}

bank& bank::deposit_interest(int interest) {
  safe += interest;
  return *this;
}

bank& bank::withdraw_utility(int utility) {
  safe -= utility;
  return *this;
}

bank& bank::withdraw_tax(int tax) {
  safe -= tax;
  return *this;
}

int main() {
  bank rich_bank, global_bank, new_bank;
  rich_bank.use_counter(10, 10);
  global_bank.use_counter(20, 5);

  new_bank.transfer_account(global_bank.get_safe());
  cout << "New bank account total: " << new_bank.get_safe() << endl;

  new_bank.deposit_interest(10).withdraw_utility(1).withdraw_tax(2);
  cout << "New bank account total: " << new_bank.get_safe() << endl;

  return 0;
}
