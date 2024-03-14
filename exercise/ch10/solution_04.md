#### 문제 4 프렌드 함수
[문제 3]에서 만든 클래스에 프렌드 함수를 추가해 보겠습니다. 추가할 프렌드 함수는 [문제 1]에서 만든 함수처럼 입력받은 클래스 템플릿 객체의 멤버 변수를 출력해 주는 기능을 합니다.
<br/><br/>

---


#### 모범 답안 과 설명
##### 답안
```cpp
#include <iostream>
#include <cmath>
#include <cctype>
#include <string>
#include <algorithm>

using namespace std;

const double criteria_for_fp = 1e-6;

bool compare_floating_point(double value) {
  if (value <= criteria_for_fp) {
    return true;
  }

  return false;
}

template<typename T>
class data_package {
public:
  data_package(T data) : member(data) {};
  bool operator==(data_package& operand) {
    return member == operand.get_member() ? true : false;
  }
  T get_member() { return member; };
private:
  T member;
  friend void print_data(data_package &object) {
    cout << "Value(" << object.member << ")";
  };
};

template<>
class data_package<bool> {
public:
  data_package(bool data) : member(data) {};
  bool operator==(data_package<bool> operand) {
    bool result_value = false;
    bool operand_value = operand.get_member();
    switch (member) {
    case true:
      if (true == operand_value) {
        result_value = true;
      }
      break;
    case false:
      if (false == operand_value) {
        result_value = true;
      }
      break;
    }
    return result_value;
    return member == operand.get_member() ? true : false;
  }
  bool get_member() { return member; };
private:
  bool member;
  friend void print_bool(data_package<bool>& object) {
    cout << "Value(" << object.member << ")";
  };
};

template<>
class data_package<float> {
public:
  data_package(float data) : member(data) {};
  bool operator==(data_package<float> operand) {
    return compare_floating_point(abs(member - operand.get_member()));
  }
  float get_member() { return member; };
private:
  float member;
  friend void print_float(data_package<float>& object) {
    cout << "Value(" << object.member << ")";
  };
};

template<>
class data_package<double> {
public:
  data_package(double data) : member(data) {};
  bool operator==(data_package<double> operand) {
    return compare_floating_point(abs(member - operand.get_member()));
  }
  double get_member() { return member; };
private:
  double member;
  friend void print_double(data_package<double>& object) {
    cout << "Value(" << object.member << ")";
  };
};

template<>
class data_package<string> {
public:
  data_package(string data) : member(data) {
    raw_data = member;
    member.erase(remove_if(member.begin(), member.end(), ::isspace), member.end());
    std::transform(member.begin(), member.end(), member.begin(), tolower);
  };
  bool operator==(data_package<string> operand) {
    return member == operand.get_member() ? true : false;
  }
  string get_member() { return member; };
private:
  string member;
  string raw_data;
  friend void print_string(data_package<string>& object) {
    cout << "Value(" << object.raw_data << ")";
  };
};

int main()
{
  data_package<bool> bool1(true), bool2(false);
  data_package<int> int1(33), int2(33);
  data_package<float> float1(2.3456987f), float2(2.3456983f);
  data_package<double> double1(342.345697), double2(342.345695);
  data_package<string> string1("Hello, World\tand new world"),
    string2("Hello,World and New world");

  cout << "bool 비교: " << boolalpha;
  print_bool(bool1);
  cout << " vs ";
  print_bool(bool2);
  cout << " is - " << (bool1 == bool2) << endl;

  cout << "int 비교: ";
  print_data(int1);
  cout << " vs ";
  print_data(int2);
  cout << " is - " << (int1 == int2) << endl;

  cout.precision(8);
  cout << "float 비교: ";
  print_float(float1);
  cout << " vs ";
  print_float(float2);
  cout << " is - " << (float1 == float2) << endl;

  cout.precision(9);
  cout << "double 비교: ";
  print_double(double1);
  cout << " vs ";
  print_double(double2);
  cout << " is - " << (double1 == double2) << endl;
    
  cout << "string 비교: ";
  print_string(string1);
  cout << " vs ";
  print_string(string2);
  cout << "' is - "  << (string1 == string2) << endl;

  return 0;
}
```
#### 실행결과
```
bool 비교: Value(true) vs Value(false) is - false
int 비교: Value(33) vs Value(33) is - true
float 비교: Value(2.3456986) vs Value(2.3456984) is - true
double 비교: Value(342.345697) vs Value(342.345695) is - false
string 비교: Value(Hello, World and new world) vs Value(Hello,World and New world)' is - true
```
##### 설명
클래스 템플릿과 템플릿 특수화가 된 클래스 템플릿에 friend 함수를 추가 하였습니다. private 멤버 변수를 출력하는 함수 때문에 main() 함수의 흐름이 조금 변경되었습니다.

[문제로 돌아 가기](README.md "문제로 돌아 가기")
