#### 문제 1 if 문 활용하기
if 문을 활용하여 사용자로부터 입력받은 숫자가 ‘양수’인지 ‘음수’인지를 판별하는 프로그램을 만들어 보세요. (0은 양수로 취급)
<br/><br/>

---

#### 모범 답안 과 설명
##### 답안
```cpp
#include <iostream>

using namespace std;

int main() {
  int number;

  // 사용자로부터 숫자 입력 받기
  cout << "숫자를 입력하세요: ";
  cin >> number;

  // if문을 이용하여 양수/음수 판별
  if (number >= 0) {
    cout << number << "는 양수입니다." << endl;
  }
  else {
    cout << number << "는 음수입니다." << endl;
  }

  return 0;
}
```
##### 설명
<li>if 문을 사용하여 number 변수가 0보다 큰지 작은지를 판별합니다.</li>
<li>number 변수가 0보다 크거나 같으면 "양수" 라고 출력하고, 0보다 작으면 "음수" 라고 출력합니다.</li><br>

[문제로 돌아 가기](README.md "문제로 돌아 가기")
