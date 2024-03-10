![](../../images/exercise_title.png "되새김문제")

이번 장에서는 C++ 프로그래밍의 기본 문법인 변수와 연산자를 알아보았습니다. 
프로그래밍에서 변수는 데이터를 저장하고 처리하는 데 사용되며, 연산자는 다양한 작업을 수행하는 데 도움이 됩니다. 
되새김 문제를 풀며 이번 장에서 배운 내용을 정리해 보세요.

### 문제 1 C++ 표준 입출력
std::cout과 std::cin을 이용하여 이름을 입력받고, 이름이 포함된 환영 메시지를 출력하는 프로그램을 만들어 보세요.

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch02/solution_01.md "문제 1번 정답")
<br /><br />

### 문제 2 데이터 형식
0.5f 5u, 5L에 어울리는 각각의 변수를 선언하고 출력해 보세요.

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch02/solution_02.md "문제 2번 정답")
<br /><br />

### 문제 3 변수의 유효 범위와 형식 변환
다음 코드에서 컴파일 오류가 발생하는 부분이 있습니다. 위치와 원인을 설명해 보세요.

```cpp
int outer_variable = 10;
{
  int inner_variable = 5;
  std::cout << "Inner Variable: " << inner_variable << std::endl;
  std::cout << "Outer Variable: " << outer_variable << std::endl;
}
std::cout << "Inner Variable: " << inner_variable << std::endl;
```

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch02/solution_03.md "문제 3번 정답")
<br /><br />

### 문제 4 키워드와 리터럴
다음처럼 이름이 있는 심벌릭(symbol) 상수는 L-value일까요? 답과 그 이유를 간단하게 설명해 보세요.
```cpp
const double PI = 3.14159;
```

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch02/solution_04.md "문제 4번 정답")
<br /><br />

### 문제 5 표현식과 연산자
다음 코드에서 문제가 발생할 수 있는 부분을 찾아 개선된 코드로 만들어 보세요.
```cpp
int a = 10, b = 3;
float result_1 = a / b;
```
[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch02/solution_05.md "문제 5번 정답")
