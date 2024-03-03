![](../../images/exercise_title.png "되새김문제")

이번 장에서는 C++언어의 표준 라이브러리, 그 중 표준 템플릿 라이브러리(STL)를 살펴보았습니다.
다양한 컨테이너를 비롯하여 각종 정렬, 검색 알고리즘 등 정말 많이 사용하는 것들 위주로만 소개하였습니다.
앞으로 여러분이 프로그래밍을 하다가, ‘어랏, 이건 웬지 라이브러리로 있을 것 같은데…’ 라는 느낌이 들면, 먼저 표준 라이브러리의 헤더들을 살펴보는 습관을 가지기를 바랍니다. 
더 많은 표준 라이브러리의 헤더들은 아래 링크에서 살펴보길 추천합니다.
https://en.cppreference.com/w/cpp/header

이제 이번 장을 마무리하는 대표 문제들을 통해 배운 내용을 정리해보도록 합시다.
해당 문제들을 표준 라이브러리를 잘 활용해서 해결할 수 있다면, 어디서든 C++ 좀 다룰 줄 안다고 얘기해도 부끄럽지 않을 것입니다.


### 문제 1 벡터 다루기
다음과 같은 정수로 이루어진 벡터가 주어졌을 때, 홀수만 모두 제거하고 짝수만 남은 벡터를 출력하는 코드를 작성하세요.
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> numbers = { 2, 7, 1, 8, 3, 6, 4, 5, 9 };

  // TODO: 홀수를 제거하고 짝수만 남은 벡터를 출력하는 코드 작성

  return 0;
}
```

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch12/solution_01.md "문제 1번 정답")
<br /><br />

### 문제 2 스택 다루기
다음과 같은 실수들이 저장된 스택이 주어졌을 때, 스택에서 가장 작은 값을 찾아 출력하는 C++ 코드를 작성하세요.
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

  // TODO: 스택에서 가장 작은 값을 찾아 출력하는 코드 작성

  return 0;
}
```

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch12/solution_02.md "문제 2번 정답")
<br /><br />

### 문제 3 벡터에서 요소 찾기
다음과 같은 정수로 이루어진 벡터가 주어졌을 때, 사용자로부터 입력받은 숫자가 벡터에 포함되어 있는지 여부를 출력하는 C++ 코드를 작성하세요.
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

  // TODO: 사용자 입력값이 벡터에 포함되어 있는지 여부를 출력하는 코드 작성

  return 0;
}
```

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch12/solution_03.md "문제 3번 정답")
<br /><br />

### 문제 4 벡터 생성 및 사용자 정의 데이터 타입 저장하기
이름, HP, MP 몬스터 라는 구조체를 만들고, 벡터 컨테이너에 서로 다른 몬스터 객체 10마리를 저장합니다. 그리고 컨테이너에 저장된 모든 몬스터들을 출력해보세요. 

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch12/solution_04.md "문제 4번 정답")
<br /><br />

### 문제 5 임의의 순서로 정렬하기
문제 4의 코드를 이어서 활용합니다.
정렬우선 순위를 '이름 > HP > MP' 순으로 수행하는 함수를 만들어보세요. 
그리고 해당 함수가 잘 동작하는지 컨테이너에 저장된 몬스터들을 모두 출력해서 확인해봅시다. 
 

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch12/solution_05.md "문제 5번 정답")
<br /><br />
