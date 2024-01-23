#include <iostream>
#include <string>
using namespace std;

class bank {
private:
  int safe; //금고
  string bank_name;

public:
  bank(string name) : bank_name(name) { safe = 0; };  //기본 생성자  
  ~bank() {};
  void use_counter(int _in, int _out);  //입출금 창구 함수
  void transfer_account(int safe);      // 계좌 변경 함수
  void reset_account();                 // 계좌 초기화
  int get_safe() { return safe; };      // 금고 금액 반환
};

void bank::use_counter(int _in, int _out) {
  safe += _in;
  safe -= _out;
  cout << bank_name << " 처리 - 입금: " << _in << ", 출금: " << _out << endl;
}

void bank::transfer_account(int safe) {
  this->safe = safe;
  cout << bank_name << "으로 계좌 이동: " << safe << endl;
}

void bank::reset_account() {
  this->safe = 0;
  cout << bank_name << " 계좌가 초기화 되었습니다." << endl;
}

int main() {
  bank rich_bank("부유한 은행"), global_bank("세계적 은행");
  rich_bank.use_counter(50, 10);

  global_bank.transfer_account(rich_bank.get_safe());
  rich_bank.reset_account();
  
  return 0;
}