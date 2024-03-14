#### 문제 2 함수 템플릿 #2
템플릿을 이용해서 is_equal(T data1, T data2) 함수를 만들어 보세요. 이 함수 템플릿은 다음과 같은 규칙으로 data1, data2가 같은 값임을 판단합니다. 이외의 데이터 형식은 false를 반환합니다. is_equal 함수를 호출할 때 data1, data2에는 같은 데이터 형식의 값을 입력한다고 가정합니다.

<table>
  <tr>
    <td>데이터 형식</td>
    <td>같읕 값 판단 기준</td>
  </tr>
  <tr>
    <td>bool</td>
    <td>data1과 data2의 논릿값이 true나 false로 같을 때</td>
  </tr>
  <tr>
    <td>int</td>
    <td>data1 == data2 연산이 참일 때</td>
  </tr>
  <tr>
    <td>float</td>
    <td rowspan=2>data1 - data2 연산의 절댓값이 0.000001 이하일 때</td>
  </tr>
  <tr>
    <td>double</td>
  </tr>
  <tr>
    <td>string</td>
    <td>영문으로만 국한해서 빈칸과 문장 부호는 무시하고 대·소문자 구별 없이 문장 안에 모든 알파벳의 개수와 순서가 같을 때</td>
  </tr>
</table>
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
bool is_equal(T operand1, T operand2) {
  return operand1 == operand2 ? true : false;
}

template<>
bool is_equal(bool operand1, bool operand2) {
  bool result_value = false;
  switch (operand1) {
  case true:
    if (true == operand2) {
      result_value = true;
    }
    break;
  case false:
    if (false == operand2) {
      result_value = true;
    }
    break;
  }
  return result_value;
}


template<>
bool is_equal(float operand1, float operand2  ) {
  return compare_floating_point(abs(operand1-operand2));
}

template<>
bool is_equal(double operand1, double operand2) {
  return compare_floating_point(abs(operand1 - operand2));
}

template<>
bool is_equal(string operand1, string operand2) {
  operand1.erase(remove_if(operand1.begin(), operand1.end(), ::isspace),operand1.end());
  operand2.erase(remove_if(operand2.begin(), operand2.end(), ::isspace), operand2.end());

  std::transform(operand1.begin(), operand1.end(), operand1.begin(), tolower);
  std::transform(operand2.begin(), operand2.end(), operand2.begin(), tolower);

  return operand1 == operand2 ? true : false;
}

int main()
{
  bool bool1 = true, bool2 = false;
  int int1 = 33, int2 = 33;
  float float1 = 2.3456987f, float2 = 2.3456983f;
  double double1 = 342.345697, double2 = 342.345695;
  string string1 = "Hello, World\tand new world",
    string2 = "Hello,World and New world";

  cout << "bool 비교: " << boolalpha << bool1 << " vs " << bool2 << " is - " << is_equal(bool1, bool2) << endl;
  cout << "int 비교: " << int1 << " vs " << int2 << " is - " << is_equal(int1, int2) << endl;
  cout.precision(8);
  cout << "float 비교: " << float1 << " vs " << float2 << " is - " << is_equal(float1, float2) << endl;
  cout.precision(9);
  cout << "double 비교: " << double1 << " vs " << double2 << " is - " << is_equal(double1, double2) << endl;
  cout << "string 비교: '" << string1 << "' vs '" << string2 << "' is - " << is_equal(string1, string2) << endl;


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
우선 범용적인 비교를 위한 is_euqal를 정의 합니다. int는 이 범용성을 담보하는 함수 템플릿으로 인스턴스화 됩니다.

bool형도 범용 템플릿을 사용해도 되지만 상세한 비교를 위하여 템플릿 특수화를 진행하였습니다. float, double, string 모두 템플릿 특수화를 진행합니다. float형, double형은 == 비교시 컴퓨터마다 다른 비교 결과를 내기 때문에 통상적인 1e-6 이하의 다름은 무시합니다.

string은 전처리를 하는 과정을 추가로 구현하였습니다. Whitespace 제거 후 모두 소문자로 변환하여 비교 합니다.

[문제로 돌아 가기](README.md "문제로 돌아 가기")
