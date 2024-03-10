#### 문제 3 while 문으로 반복하기
while 반복문을 활용하여 1~10까지 숫자 중 짝수만 출력하는 프로그램을 만들어 보세요.
<br/><br/>

---

#### 모범 답안 과 설명
##### 답안
```cpp
#include <iostream>

using namespace std;

int main() {
  int number = 1;

  // while 반복문을 이용하여 1부터 10까지 짝수만 출력
  while (number <= 10) {
    if (number % 2 == 0) {
      cout << number << " ";
    }
    number++;
  }

  cout << endl;

  return 0;
}
```
##### 설명
<li>while 반복문을 사용하여 number 변수가 10보다 작거나 같을 때까지 반복합니다.</li>
<li>if 문을 사용하여 number 변수가 2로 나누어 떨어지는 짝수인지 판단합니다. 짝수인 경우 number 변수를 출력합니다.</li><br>

[문제로 돌아 가기](README.md "문제로 돌아 가기")
