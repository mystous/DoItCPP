#include <iostream>

using namespace std;

template <typename Type1, typename Type2>
class data_package {
public:
  template<typename Type2>
  class nested_class_data_package {
  public:
    nested_class_data_package(Type2 data) : nested_class_data(data) {}
    Type2 get_element() { return nested_class_data; }
    Type2 nested_class_data;
  };

  template<typename Type3>
  class nested_class {
  public:
    nested_class(Type3 data) : nested_class_data(data) {}
    void print_out_element() {
      cout << "중첩 클래스 데이터: " << nested_class_data << endl;
    }
  private:
    Type3 nested_class_data;
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
  nested_class_data_package<Type2> internal_data;

};
int main() {
  data_package<string, int> template_inst1("문자열", 10);
  data_package<string, int>::nested_class<int> template_inst2(500);

  cout << "중첩 클래스 첫 번째 범례" << endl;
  template_inst1.print_out_element();

  cout << endl << "중첩 클래스 두 번째 범례" << endl;
    template_inst2.print_out_element();
}