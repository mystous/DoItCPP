#include <iostream>

using namespace std;

template <typename T = int>   // 기본 형식 설정
class data_package {
public:
  data_package(T first) : first(first) {}
  void print_out_element() {
    cout << "클래스 템플릿 형식 매개 변수 값 : " << first << endl;
  }
private:
  T first;
};

int main() {
  data_package<> template_inst1(5);   // 기본 형식(여기서는 int)으로 지정
  data_package<string> template_inst2("클래스 템플릿 기본값");

  template_inst1.print_out_element();
  template_inst2.print_out_element();
}
