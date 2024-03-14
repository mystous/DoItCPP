![](../../images/exercise_title.png "되새김문제")

이번 장에서는 템플릿을 살펴보았습니다. 템플릿은 C++에서 활용도가 매우 높은 문법입니다. 익숙해 질때까지 시간이 조금 걸릴 수 있으므로 많은 연습이 필요합니다. 되새김 문제를 풀며 이번 장에서 배운 내용을 정리해 보세요.

### 문제 1 함수 템플릿 #1
템플릿을 사용해 다양한 데이터 형식의 값을 출력하는 함수를 만들어 보세요. print_data(T data) 형식으로 함수 템플릿을 만들어서 cout으로 “입력받은 값은 :”이라는 문장과 함께 입력받은 값을 출력하는 함수를 만들어 보세요.

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch10/solution_01.md "문제 1번 정답")
<br /><br />

### 문제 2 함수 템플릿 #2
템플릿을 이용해서 is_equal(T data1, T data2) 함수를 만들어 보세요. 이 함수 템플릿은 다음과 같은 규칙으로 data1, data2가 같은 값임을 판단합니다. 이외의 데이터 형식은 false를 반환합니다. is_equal 함수를 호출할 때 data1, data2에는 같은 데이터 형식의 값을 입력한다고 가정합니다.

<table>
  <tr>
    <td>데이터 형식</td>
    <td>같읕 값 판단 기준</td>
  </tr>
  <tr>
    <td>bool</td>
    <td>data1과 data2의 논릿값이 true나 false로 같을 때</td>
  </tr>
  <tr>
    <td>int</td>
    <td>data1 == data2 연산이 참일 때</td>
  </tr>
  <tr>
    <td>float</td>
    <td rowspan=2>data1 - data2 연산의 절댓값이 0.000001 이하일 때</td>
  </tr>
  <tr>
    <td>double</td>
  </tr>
  <tr>
    <td>string</td>
    <td>영문으로만 국한해서 빈칸과 문장 부호는 무시하고 대·소문자 구별 없이 문장 안에 모든 알파벳의 개수와 순서가 같을 때</td>
  </tr>
</table>

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch10/solution_02.md "문제 2번 정답")
<br /><br />

### 문제 3 클래스 템플릿
[문제 2]서 작성한 소스 코드를 활용해 클래스 템플릿을 만들어 보세요. is_equal 함수 대신 operator=를 오버로드해서 만들어 보기 바랍니다.

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch10/solution_03.md "문제 3번 정답")
<br /><br />

### 문제 4 프렌드 함수
[문제 3]에서 만든 클래스에 프렌드 함수를 추가해 보겠습니다. 추가할 프렌드 함수는 [문제 1]에서 만든 함수처럼 입력받은 클래스 템플릿 객체의 멤버 변수를 출력해 주는 기능을 합니다.

[모범 답안](https://github.com/mystous/DoItCPP/tree/main/exercise/ch10/solution_04.md "문제 4번 정답")
<br /><br />
