#include <iostream>

using namespace std;

template <typename T = int>
class data_package {
public:
  data_package(T first) : first(first) {}
  template <typename C>
  friend void printout_friend_element(C& data_object);  // 프렌드 함수 선언
private:
  T first;
};

template <typename C>
void printout_friend_element(C& data_object) {    // 프렌드 함수 정의
  cout << "(friend 함수 템플릿 호출)  템플릿 형식 매개 변수 값 : "
    << data_object.first << endl;
}

int main() {
  data_package<> template_inst1(5);
  data_package<string> template_inst2("클래스 템플릿 기본값");

  printout_friend_element(template_inst1);
  printout_friend_element(template_inst2);
}