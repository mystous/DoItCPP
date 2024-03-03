#### 모범 답안 과 설명
##### 답안
```cpp
#include <iostream>

using namespace std;

int main() {
  int dan;

  // 사용자로부터 구구단 단수 입력 받기
  while (true) {
    cout << "1부터 9까지의 숫자를 입력하여 구구단을 출력하세요: ";
    cin >> dan;

    // 유효한 숫자 입력 확인 (1~9)
    if (dan >= 1 && dan <= 9) {
      break;
    }
    cout << "유효하지 않은 숫자입니다. 다시 입력하세요." << endl;
  }

  // for 반복문을 이용하여 해당 단수 구구단 출력
  for (int i = 1; i <= 9; i++) {
    cout << dan << " * " << i << " = " << dan * i << endl;
  }

  return 0;
}
```

##### 설명
<li>dan 변수를 선언하여 사용자로부터 1부터 9까지의 정수를 입력받습니다. 이 때 while 반복문을 사용하여 유효한 숫자가 입력될 때까지 반복합니다.</li>
<li>for 반복문을 사용하여 입력받은 단수에 해당하는 구구단을 출력합니다.</li>

