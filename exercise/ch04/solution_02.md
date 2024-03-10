#### 문제 2 switch 문 활용하기
switch 문을 활용하여 사용자에게 1~7까지의 숫자 중 하나를 입력받아, 숫자에 해당하는 요일을 출력하는 프로그램을 만들어 보세요.
<br/><br/>

---

#### 모범 답안 과 설명
##### 답안
```cpp
#include <iostream>

using namespace std;

int main() {
  int day;

  // 사용자로부터 요일 번호 입력 받기
  cout << "1부터 7까지의 숫자를 입력하여 요일을 확인하세요: ";
  cin >> day;

  // switch 문을 이용하여 요일 출력
  switch (day) {
    case 1:
      cout << "월요일입니다." << endl;
      break;
    case 2:
      cout << "화요일입니다." << endl;
      break;
    case 3:
      cout << "수요일입니다." << endl;
      break;
    case 4:
      cout << "목요일입니다." << endl;
      break;
    case 5:
      cout << "금요일입니다." << endl;
      break;
    case 6:
      cout << "토요일입니다." << endl;
      break;
    case 7:
      cout << "일요일입니다." << endl;
      break;
    default:
      cout << "유효하지 않은 숫자입니다." << endl;
  }

  return 0;
}
```
##### 설명
<li>switch 문을 사용하여 day 변수의 값에 따라 해당 요일을 출력합니다.</li>
<li>default 케이스는 유효하지 않은 숫자가 입력되었을 때 처리합니다.</li><br>

[문제로 돌아 가기](README.md "문제로 돌아 가기")
