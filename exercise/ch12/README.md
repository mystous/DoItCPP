![](../../images/exercise_title.png "되새김문제")

이 장에서는 C++ 언어의 표준 라이브러리, 그중에서도 표준 템플릿 라이브러리에서 제공하는 다양한 컨테이너, 정렬, 검색 알고리즘 등 개발 현장에서 많이 사용하는 기능 위주로 살펴봤습니다.
표준 라이브러리에서는 이 외에도 다양한 기능을 제공하므로 표준 라이브러리의 헤더를 살펴보는 습관을 가지면 좋습니다.<br>
https://en.cppreference.com/w/cpp/header

이제 문제를 풀며 이번 장에서 배운 내용을 되새겨 보세요.


### 문제 1 벡터 다루기
다음 코드처럼 정수로 구성된 벡터가 주어졌을 때 홀수만 모두 제거하고 짝수만 남은 벡터를 출력하는 코드를 작성해 보세요.
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> numbers = { 2, 7, 1, 8, 3, 6, 4, 5, 9 };

  // 홀수를 제거하고 짝수만 남은 벡터를 출력하는 코드를 작성해 보세요.

  return 0;
}
```

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch12/solution_01.md "문제 1번 정답")
<br /><br />

### 문제 2 스택 다루기
다음 코드처럼 실수가 저장된 스택이 주어졌을 때 스택에서 가장 작은 값을 찾아 출력하는 코드를 작성해 보세요.
```cpp
#include <iostream>
#include <stack>

using namespace std;

int main() {
  stack<double> myStack;
  myStack.push(3.14);
  myStack.push(2.71);
  myStack.push(4.98);
  myStack.push(1.23);

  // 스택에서 가장 작은 값을 찾아 출력하는 코드를 작성해 보세요.

  return 0;
}
```

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch12/solution_02.md "문제 2번 정답")
<br /><br />

### 문제 3 벡터에서 원소 찾기
다음 코드처럼 정수로 구성된 벡터가 주어졌을 때 사용자에게 입력받은 숫자가 벡터에 포함되었는지를 출력하는 코드를 작성해 보세요.
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> numbers = { 3, 8, 1, 6, 2, 7, 5, 4, 9 };

  int userInput;
  cout << "찾고자 하는 숫자를 입력하세요: ";
  cin >> userInput;

  // 사용자 입력값이 벡터에 포함되었지를 출력하는 코드를 작성해 보세요.

  return 0;
}
```

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch12/solution_03.md "문제 3번 정답")
<br /><br />

### 문제 4 벡터 생성과 사용자 정의 데이터 형식 저장하기
이름, HP, MP 속성을 가지는 몬스터 구조체를 만들고, 벡터 컨테이너에 서로 다른 몬스터 객체 10마리를 저장합니다.
그리고 컨테이너에 저장된 모든 몬스터를 출력해 보세요.

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch12/solution_04.md "문제 4번 정답")
<br /><br />

### 문제 5 임의의 순서로 정렬하기
[문제 4]의 코드를 이어서 활용합니다. 
‘이름 > HP > MP’ 순으로 정렬하는 함수를 만들어 보세요. 
그리고 해당 함수가 잘 동작하는지 컨테이너에 저장된 몬스터들을 모두 출력해서 확인해 보세요.
 

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch12/solution_05.md "문제 5번 정답")
<br /><br />
