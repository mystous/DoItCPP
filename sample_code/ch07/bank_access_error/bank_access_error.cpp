#include <iostream> 

using namespace std;

class bank {
private:
  int safe;    // 금고 

public:
  bank();      // 기본 생성자  
  void use_counter(int _in, int _out);   // 입출금 창구 함수 
};

bank::bank() {
  safe = 1000;    // 은행 금고 초기 금액 설정 
  cout << "최초 금고 : " << safe << endl;
  cout << endl;
}

void bank::use_counter(int _in, int _out) {
  safe += _in;     // 입금 
  safe -= _out;    // 출금 

  cout << "입금 : " << _in << endl;
  cout << "출금 : " << _out << endl;
  cout << "금고 : " << safe << endl;
  cout << endl;
}

int main() {
  bank my_bank; // my_bank 인스턴스 생성
  my_bank.safe -= 100;    // private으로 지정된 금고에 직접 접근하여 인출 시도
  return 0;
}
