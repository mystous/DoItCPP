#### 문제 3 클래스 템플릿
[문제 2]서 작성한 소스 코드를 활용해 클래스 템플릿을 만들어 보세요. is_equal 함수 대신 operator=를 오버로드해서 만들어 보기 바랍니다.
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
};

template<>
class data_package<string> {
public:
  data_package(string data) : member(data) {
    member.erase(remove_if(member.begin(), member.end(), ::isspace), member.end());
    std::transform(member.begin(), member.end(), member.begin(), tolower);
  };
  bool operator==(data_package<string> operand) {
    return member == operand.get_member() ? true : false;
  }
  string get_member() { return member; };
private:
  string member;
};

int main()
{
  data_package<bool> bool1(true), bool2(false);
  data_package<int> int1(33), int2(33);
  data_package<float> float1(2.3456987f), float2(2.3456983f);
  data_package<double> double1(342.345697), double2(342.345695);
  data_package<string> string1("Hello, World\tand new world"),
                       string2("Hello,World and New world");

  cout << "bool 비교: " << boolalpha << bool1.get_member() << " vs " << bool2.get_member() << " is - " << (bool1 == bool2) << endl;
  cout << "int 비교: " << int1.get_member() << " vs " << int2.get_member() << " is - " << (int1 == int2) << endl;
  cout.precision(8);
  cout << "float 비교: " << float1.get_member() << " vs " << float2.get_member() << " is - " << (float1 == float2) << endl;
  cout.precision(9);
  cout << "double 비교: " << double1.get_member() << " vs " << double2.get_member() << " is - " << (double1 == double2) << endl;
  cout << "string 비교: '" << string1.get_member() << "' vs '" << string2.get_member() << "' is - " << (string1 == string2) << endl;

  return 0;
}
```
#### 실행결과
```
bool 비교: true vs false is - false
int 비교: 33 vs 33 is - true
float 비교: 2.3456986 vs 2.3456984 is - true
double 비교: 342.345697 vs 342.345695 is - false
string 비교: 'Hello, World      and new world' vs 'Hello,World and New world' is - true
```
##### 설명
2번 문제와 변경된 부분은 함수 템플릿 대신 클래스 템플릿을 사용하고 '==' 연산자 오버라이딩 한 부분입니다.

비교 연산의 로직은 동일합니다. string 데이터의 경우 비교 함수에서 전처리를 하지 않고 클래스 생성자에서 전처리 하는 부분이 조금 다릅니다.

[문제로 돌아 가기](README.md "문제로 돌아 가기")
