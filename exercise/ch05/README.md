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
