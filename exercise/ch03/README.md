![](../../images/exercise_title.png "되새김문제")

이번 장에서는 C++ 언어의 문법을 살펴보았습니다. 특히 각종 자료형과 포인터, 메모리 등은 한 번에 이해하기 어려웠을지도 모릅니다. 문제를 풀다가 잘 생각이 나지 않는다면 해당 부분을 다시 찾아 보세요. 이 문제들을 막힘 없이 풀 수 있다면 그리고 그 원리를 이해했다면 C++ 언어의 기본 문법은 이해했다고 볼 수 있습니다.

### 문제 1 포인터 활용에 대한 기본 이해
아래 규칙을 따르는 간단한 프로그램을 만들고 실행해보세요. 이 문제를 풀어보면서 포인터와 메모리에 대한 이해를 확인할 수 있을 것입니다.
1.	크기가 5인 정수 배열을 동적으로 할당하고, 이를 가리키는 포인터를 선언하세요.
2.	동적으로 할당한 배열에 1부터 5까지의 값을 저장하세요.
3.	할당한 배열의 내용을 출력하세요.
4.	할당한 메모리를 해제하세요.

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch03/solution_01.md "문제 1번 정답")
<br /><br />

### 문제 2 구조체의 활용
5가지 속성을 가진 몬스터라는 구조체를 만들어 보세요. 해당 구조체 형식의 변수를 인자로 받아 출력하는 함수도 만들어 보고, 잘 동작하는지 main 함수에서 테스트해 보세요.

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch03/solution_02.md "문제 2번 정답")
<br /><br />

### 문제 3 동적 메모리 할당 이해
동적으로 할당한 메모리는 반드시 해제해야 합니다. 그 이유는 무엇일까요? 그렇다면 일반 변수는 메모리 해제 관리가 필요 없는 이유가 무엇일까요? 최대한 자세하게 서술해 보세요.

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch03/solution_03.md "문제 3번 정답")
<br /><br />

### 문제 4 레퍼런스 변수
다음 코드는 컴파일 오류가 발생합니다. 그 이유를 설명해 보세요. 
```cpp
int &ref_invalid_value;
```
[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch03/solution_04.md "문제 4번 정답")
<br /><br />

### 문제 5 변수, 레퍼런스, 포인터의 차이
값에 의한 호출, 참조에 의한 호출, 주소에 의한 호출의 차이를 서술해 보세요.

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch03/solution_05.md "문제 5번 정답")
