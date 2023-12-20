#include <iostream>

using namespace std;

template <typename T = int>
class data_package {
public:
  data_package(T first) : first(first) {}
  void print_out_element() {
    cout << "클래스 템플릿 형식 매개 변수 값 : " << first << endl;
  }
  friend void printout_friend_element(data_package<T>& data_object) {
    cout << "(friend 클래스 템플릿 호출) 클래스 템플릿 형식 매개 변수 값 : " 
      << data_object.first << endl;
  }
private:
  T first;
};

int main() {
  data_package<> template_inst1(5);
  data_package<string> template_inst2("클래스 템플릿 기본값");

  printout_friend_element(template_inst1);
  printout_friend_element(template_inst2);
}