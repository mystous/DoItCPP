![](../../images/exercise_title.png "되새김문제")

예외 처리는 프로그램에서 발생할 수 있는 예기치 못한 상황에 대처하는 중요한 개념입니다.
이번에는 예외 처리의 기본 원리를 떠올리면서, 예외 처리 코딩에도 익숙해질 수 있는 간단한 문제들을 풀어보려고 합니다.
문제를 풀다가 구문 활용 방법이 잘 생각나지 않는다면, 앞의 설명을 다시 찾아봐도 좋습니다. 그럼 시작해 봅시다!

### 문제 1 Try, Throw, Catch 이해하기
아래 코드에서 try, throw, catch 구문을 활용하여 예외를 처리하세요.
```cpp
int main() {
  int divisor = 0;
  // 예외 처리를 추가해보세요
  int result = 10 / divisor;
  std::cout << "결과: " << result << std::endl;
  return 0;
}
```

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch05/solution_01.md "문제 1번 정답")
<br /><br />

### 문제 2 예외 처리 생략과 실패 대응
아래 코드에서 try, catch를 이용하여 예외를 처리하고, 생략된 예외를 실패 대응으로 처리하세요.
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
assert 를 이용하여 예외 처리를 간단히 구현해보세요.

```cpp
void divide(int a, int b) {
  // b가 0인 경우 어설션을 이용하여 예외 처리
}

int main() {
  divide(10, 2);
  divide(5, 0);
  return 0;
}
```

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch05/solution_03.md "문제 3번 정답")
<br /><br />
