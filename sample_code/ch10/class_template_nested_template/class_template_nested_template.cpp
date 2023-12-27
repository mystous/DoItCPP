#include <iostream>

using namespace std;

template <typename Type1, typename Type2>
class data_package {
public:
  template <typename Type3>            // 바깥쪽 템플릿 매개변수 사용 
  class nested_class_data_package {    // 안쪽 클래스
  public:
    nested_class_data_package(Type3 data) : nested_class_data(data) {}
    Type3 get_element() { return nested_class_data; }
    Type3 nested_class_data;
  };

  template <typename Type4>    // 새 템플릿 매개변수 사용
  class nested_class {         // 안쪽 클래스
  public:
    nested_class(Type4 data) : nested_class_data(data) {}
    void print_out_element() {
      cout << "중첩 클래스 데이터: " << nested_class_data << endl;
    }
  private:
    Type4 nested_class_data;
  };

  data_package(Type1 first, Type2 second) : first(first), second(second),
                                            internal_data(second) {}

  void print_out_element() {
    cout << "첫 번째 요소: " << first <<
      ", 두 번째 요소: " << second << endl;
    cout << "중첩 클래스 요소: " << internal_data.get_element() << endl;
  }

private:
  Type1 first;
  Type2 second;
  nested_class_data_package<Type2> internal_data;   // 멤버 변수로 선언

};
int main() {
  data_package<string, int> template_inst1("문자열", 10);
  data_package<string, int>::nested_class<int> template_inst2(500);   // 객체로 선언

  cout << "중첩 클래스 첫 번째 범례" << endl;
  template_inst1.print_out_element();

  cout << endl << "중첩 클래스 두 번째 범례" << endl;
  template_inst2.print_out_element();
}