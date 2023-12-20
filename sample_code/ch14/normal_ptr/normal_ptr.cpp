#include <iostream>
#include <memory>

using namespace std;

class class_object {
public:
  class_object() {
    cout << "메모리가 할당 되었습니다." << endl;
  };
  ~class_object() {
    cout << "메모리가 해제 되었습니다." << endl;
  }
};

int main() {
  // 메모리 누수 발생
  class_object* normal_pointer = new class_object();

  return 0;
}