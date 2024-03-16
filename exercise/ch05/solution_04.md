#### 문제 4 예외 처리 실전 연습 1
사용자에게 월과 일을 입력받아 해당하는 날짜의 계절을 출력하는 프로그램을 만들어 보세요.
• 3-5월까지는 봄, 6-8월까지는 여름, 9-11월까지는 가을, 12-2월까지는 겨울
• 월과 일을 입력받을 때 범위를 벗어나는 경우 std::out_of_range 예외 발생

출력 예시
```cpp
월을 입력하세요: 3
일을 입력하세요: 20
입력하신 날짜의 계절은 봄입니다.
```
<br/>

---

#### 모범 답안 과 설명
##### 답안
```cpp
#include <iostream>
#include <stdexcept>

using namespace std;

string get_season(int month) {
  if (month >= 3 && month <= 5)
    return "봄";
  else if (month >= 6 && month <= 8)
    return "여름";
  else if (month >= 9 && month <= 11)
    return "가을";
  else // month가 12, 1, 2일 때
    return "겨울";
}

int main() {
  try {
    int month, day;

    cout << "월을 입력하세요: ";
    cin >> month;

    if (month < 1 || month > 12)
      throw out_of_range("월은 1부터 12까지의 정수여야 합니다.");

    cout << "일을 입력하세요: ";
    cin >> day;

    if (day < 1 || day > 31) // 간단히 최대 31일까지로 가정
      throw out_of_range("일은 1부터 31까지의 정수여야 합니다.");

    string season = get_season(month);
    cout << "입력하신 날짜의 계절은 " << season << "입니다." << endl;
  }
  catch (out_of_range& ex) {
    cerr << "예외 발생: " << ex.what() << endl;
  }

  return 0;
}
```

##### 설명
실행결과
```cpp
월을 입력하세요: 3
일을 입력하세요: 20
입력하신 날짜의 계절은 봄입니다.
```
실행결과
```cpp
월을 입력하세요: 14
예외 발생: 월은 1부터 12까지의 정수여야 합니다.
```
실행결과
```cpp
월을 입력하세요: 1
일을 입력하세요: 50
예외 발생: 일은 1부터 31까지의 정수여야 합니다.
```

<li>get_season 함수: 입력된 월에 따라 계절을 반환하는 함수입니다.</li>
<li>입력이 유효한 경우, get_season 함수를 호출하지만, 입력이 유효하지 않은 경우 std::out_of_range 예외를 던집니다.</li>
<li>std::out_of_range는 C++ 표준 라이브러리에서 제공하는 예외 클래스 중 하나로, 일반적으로 인덱스나 범위가 잘못된 경우에 사용됩니다.</li>
<li>stdexcept 헤더에는 여러 예외 클래스를 정의되어 있습니다. 대표적으로 std::out_of_range 예외 클래스가 있지요.</li>
<li>cerr은 C++ 표준 라이브러리에서 제공하는 표준 에러 출력 스트림입니다.<br>
일반적으로 프로그램에서 오류 메시지를 출력할 때 cerr을 사용하는 것이 좋습니다.<br>
왜냐하면 cerr은 버퍼링되지 않으므로 오류 메시지가 발생한 시점에 즉시 출력되어 프로그램이 비정상적으로 종료되었을 때 사용자에게 빠르게 정보를 제공할 수 있기 때문입니다.<br>
반면에 cout은 버퍼링되어 있을 수 있으므로 프로그램이 비정상적으로 종료되었을 때 cout에 있는 내용은 출력되지 않을 수 있습니다.<br>
따라서 예외 처리나 오류 처리를 할 때는 cerr을 사용하여 오류 메시지를 출력하는 것이 추천합니다.</li><br>

[문제로 돌아 가기](README.md "문제로 돌아 가기")

