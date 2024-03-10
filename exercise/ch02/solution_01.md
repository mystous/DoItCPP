#### 문제 1 C++ 표준 입출력
std::cout과 std::cin을 이용하여 이름을 입력받고, 이름이 포함된 환영 메시지를 출력하는 프로그램을 만들어 보세요.
<br/><br/>

---

#### 모범 답안 과 설명
##### 답안
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
  string name;

  // 이름 입력 받기
  cout << "이름을 입력하세요: ";
  cin >> name;

  // 환영 메시지 출력
  cout << "환영합니다, " << name << "님!" << endl;

  return 0;
}
```
##### 설명
프로그램에서 입력 및 출력을 위해 <iostream> 헤더를 포함하고, 문자열 처리를 위해 <string> 헤더를 포함합니다.</br>
사용자로부터 입력을 받을 때는 cin, 출력할 때는 cout을 사용합니다.</br>
문자열을 입력받기 위해 2장에서 살짝 소개한 string 형식의 변수 name도 만들었습니다. string 형식에 대해 더 알고 싶다면, '11-2 문자열 라이브러리'를 참고해주세요.

[문제로 돌아 가기](README.md "문제로 돌아 가기")
