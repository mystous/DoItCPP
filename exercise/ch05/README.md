![](../../images/exercise_title.png "되새김문제")

예외 처리는 프로그램에서 발생할 수 있는 예기치 못한 상황에 대처하는 중요한 작업입니다.
예외 처리의 기본 원리를 떠올리면서 다음 문제를 풀어 보세요.

### 문제 1 try, catch, throw 문 이해하기
다음 코드를 바탕으로 try, catch, throw 문을 이용해 예외를 처리해 보세요.
```cpp
int main() {
  int divisor = 0;

  // 여기에 예외 처리를 추가해 보세요.
  int result = 10 / divisor;
  std::cout << "결과: " << result << std::endl;
  return 0;
}
```

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch05/solution_01.md "문제 1번 정답")
<br /><br />

### 문제 2 예외 처리 생략과 실패 대응
다음 코드에서 try, catch 문으로 예외를 처리하고 생략된 예외와 실패에 대응하는 코드를 작성해 보세요.
```cpp
void process(int value) {
  // value가 음수인 경우 예외를 던지도록 처리
  // 예외가 발생하면 "예외 발생!" 출력, 발생하지 않으면 value 출력
}

int main() {
  process(10);
  process(-5);
  return 0;
}
```

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch05/solution_02.md "문제 2번 정답")
<br /><br />

### 문제 3 어설션을 이용한 예외 처리
다음 코드를 바탕으로 assert를 이용해 예외 처리를 구현해 보세요.

```cpp
void divide(int a, int b) {
  // b가 0일 때 assert로 예외 처리
}

int main() {
  divide(10, 2);
  divide(5, 0);
  return 0;
}
```

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch05/solution_03.md "문제 3번 정답")
<br /><br />

### 문제 4 예외 처리 실전 연습 1
사용자에게 월과 일을 입력받아 해당하는 날짜의 계절을 출력하는 프로그램을 만들어 보세요.<br>
• 3-5월까지는 봄, 6-8월까지는 여름, 9-11월까지는 가을, 12-2월까지는 겨울<br>
• 월과 일을 입력받을 때 범위를 벗어나는 경우 std::out_of_range 예외 발생<br>

출력 예시
```cpp
월을 입력하세요: 3
일을 입력하세요: 20
입력하신 날짜의 계절은 봄입니다.
```

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch05/solution_04.md "문제 4번 정답")
<br /><br />

### 문제 5 예외 처리 실전 연습 2
숫자 맞히기 게임을 만들고 있습니다. 게임은 다음과 같은 규칙으로 동작해야 합니다.<br>
1. 1부터 100까지 무작위 숫자를 생성합니다.
2. 사용자에게 숫자를 입력하도록 요청합니다.
3. 사용자가 입력한 숫자가 랜덤 숫자보다 크면 “너무 높아요!”, 작으면 “너무 낮아요!”라고 알려 줍니다.
4. 사용자가 랜덤 숫자를 맞힐 때까지 2~3번 과정을 반복합니다.
5. 사용자가 랜덤 숫자를 맞히면 “축하합니다!” 메시지를 출력합니다.  <br>

1번을 포함한 기본 코드는 다음처럼 구현했습니다.<br>
이제 여러분이 2번부터 5번까지 직접 코드를 작성해 보세요.<br>
만약 사용자가 범위를 벗어나는 숫자를 입력하면,<br>
“1부터 100 사이의 숫자를 입력해 주세요!”라는 메시지를 출력한 후 다시 숫자를 입력하도록 요청합니다.<br>
 

```cpp
#include <iostream>
#include <random>

int main() {
  // 1부터 100까지 랜덤 숫자 생성
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(1, 100);
  int answer = dist(gen);

  // 게임 시작
  bool is_correct = false;
  while (!is_correct) {
    try {
      // 정답 코드 작성 영역
    }
    catch (const std::exception& e) {
      // 예외 발생 시 메시지 출력
      std::cerr << e.what() << std::endl;
    }
  }

  return 0;
}
```

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch05/solution_05.md "문제 5번 정답")
<br /><br />
