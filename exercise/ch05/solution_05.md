#### 문제 5 예외 처리 실전 연습 2
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

---

#### 모범 답안 과 설명
##### 답안
```cpp
#include <iostream>
#include <random>
#include <stdexcept>
#include <limits>

using namespace std;

int main() {
  // 1부터 100까지 랜덤 숫자 생성
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dist(1, 100);
  int answer = dist(gen);

  // *count 변수는 문제와는 상관없지만, 게임의 재미를 위해 추가하였습니다.
  // *몇 번만에 숫자 맞히기를 성공하는지 카운트하기 위해 활용되는 변수입니다. :)
  int count = 0;

  // 게임 시작
  bool is_correct = false;
  while (!is_correct) {
    try {
      // 사용자에게 숫자 입력 요청
      ++count;
      cout << "숫자를 입력하세요: ";
      int guess;
      cin >> guess;

      // *숫자가 아닌 입력이 들어왔는지 확인하는 부분입니다.
      // *문제와는 상관없지만, 좀 더 어드밴스한 것을 원하는 독자분들을 위해 특별히 추가한 부분입니다. :)
      if (cin.fail()) {
        cin.clear(); // 입력 스트림의 상태를 초기화
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 버퍼 비우기
        throw invalid_argument("숫자를 입력해주세요!");
      }

      // 입력한 숫자가 범위를 벗어나는지 확인
      if (guess < 1 || guess > 100) {
        throw out_of_range("1부터 100 사이의 숫자를 입력해주세요!");
      }

      // 숫자 비교 후 메시지 출력
      if (guess > answer) {
        cout << "너무 높아요!" << endl << endl;
      }
      else if (guess < answer) {
        cout << "너무 낮아요!" << endl << endl;
      }
      else {
        cout << "축하합니다! 정답은 " << answer << "입니다." << endl;
        cout << count << "번 만에 맞추셨습니다. :)" << endl;
        is_correct = true;
      }
    }
    catch (const exception& e) {
      // 예외 발생 시 에러 메시지 출력
      cerr << e.what() << endl << endl;
    }
  }

  return 0;
}
```

##### 설명
실행결과
```cpp
숫자를 입력하세요: p
숫자를 입력해주세요!

숫자를 입력하세요: 1000
1부터 100 사이의 숫자를 입력해주세요!

숫자를 입력하세요: 100
너무 높아요!

숫자를 입력하세요: 1
너무 낮아요!

숫자를 입력하세요: 50
너무 낮아요!

숫자를 입력하세요: 75
너무 낮아요!

숫자를 입력하세요: 80
너무 낮아요!

숫자를 입력하세요: 85
너무 낮아요!

숫자를 입력하세요: 90
너무 낮아요!

숫자를 입력하세요: 95
너무 낮아요!

숫자를 입력하세요: 97
너무 낮아요!

숫자를 입력하세요: 98
축하합니다! 정답은 98입니다.
12번 만에 맞추셨습니다. :)
```

<li>random_device, mt19937, uniform_int_distribution을 사용하여 1부터 100까지의 랜덤 숫자를 생성합니다.<br>
관련 부분이 궁금하다면, 11-4 기타 유용한 함수를 난수 부분을 참고해주세요. </li>
<li>사용자가 입력한 숫자가 1부터 100 사이의 범위에 있는지 확인합니다.
범위를 벗어나는 경우 out_of_range 예외를 던지도록 하였습니다.</li>
<li>예외가 발생한 경우 cerr을 사용하여 에러 메시지를 출력합니다.</li>
<li>사용자가 숫자가 아닌 것을 입력하면 입력이 정상적인지 확인하는 코드를 특별히 추가해봤습니다.<br>
만약 사용자가 숫자가 아닌 입력을 했을 경우 cin.fail()을 사용하여 이를 감지하고, 적절한 예외를 던집니다.<br>
숫자가 아닌 입력이 발생한 경우 invalid_argument 예외를 던지도록 하였습니다.<br>
stdexcept 헤더에는 여러 예외 클래스를 정의되어 있으니, 둘러보고 필요한 부분은 선택하여 활용할 수 있도록 연습하는 것을 추천합니다.<br>
https://en.cppreference.com/w/cpp/header/stdexcept</li><br>

[문제로 돌아 가기](README.md "문제로 돌아 가기")
