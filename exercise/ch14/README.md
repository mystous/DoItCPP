![](../../images/exercise_title.png "되새김문제")

이번 장에서는 모던 C++에 추가된 데이터 형식과 라이브러리를 알아보았습니다. 다음의 문제를 풀며 이번 장에서 배운 내용을 되새겨 보세요.

### 문제 1 자료형을 추론하는 auto
auto는 모던 C++의 작지만 영향력이 큰 변화 중 한 가지입니다. 도서 목록을 저장하고 불러올 수 있는 C++ 프로그램을 작성하면서 auto와 범위 기반 for 문을 사용해 보세요.

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch14/solution_01.md "문제 1번 정답")
<br /><br />

### 문제 2 상수 지정자 constexpr
constexpr을 사용하는 함수와 일반 함수를 사용하는 코드를 자유롭게 작성해 보세요. 그리고 constexpr 을 사용하지 않는 함수를 작성해서 2개의 함수 호출 시 전체 실행 시간의 차이를 비교해 보세요.

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch14/solution_02.md "문제 2번 정답")
<br /><br />

### 문제 3 constexpr와 const 비교
상수를 만드는 방식에는 constexpr과 const 두 가지가 있습니다. 두 방식의 차이를 독자 여러분이 생각하는 중요한 부분을 중심으로 비교해 보세요.

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch14/solution_03.md "문제 3번 정답")
<br /><br />

### 문제 4 정렬 만들어 보기
표준 라이브러리에서 정렬을 수행하는 sort 함수는 데이터를 비교하는 compare 함수를 콜백으로 입력받습니다. 비슷한 형식으로 여러분이 직접 정렬 알고리즘을 만들어 보세요. 이때 콜백 함수는 std::function을 사용합니다.

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch14/solution_04.md "문제 4번 정답")
<br /><br />

### 문제 5 RAII 디자인 패턴
RAII의 정의와 필요성에 대해서 설명해 보세요. 그리고 가비지 컬렉터와 비교해 어떤 장단점이 있는지 실제 사례를 들어 보세요.

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch14/solution_05.md "문제 5번 정답")
