#### 문제 3 벡터에서 원소 찾기
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
<br/>

---

#### 모범 답안 과 설명
##### 답안
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

  // 사용자 입력값이 벡터에 포함되어 있는지 확인
  bool isFound = false;
  for (int num : numbers) {
    if (num == userInput) {
      isFound = true;
      break;
    }
  }

  // 결과 출력
  if (isFound) {
    cout << "입력한 숫자 " << userInput << "는 벡터에 포함되어 있습니다." << endl;
  }
  else {
    cout << "입력한 숫자 " << userInput << "는 벡터에 포함되어 있지 않습니다." << endl;
  }

  return 0;
}
```

##### 설명
실행결과
```cpp
찾고자 하는 숫자를 입력하세요: 5
입력한 숫자 5는 벡터에 포함되어 있습니다.
```

```cpp
찾고자 하는 숫자를 입력하세요: 0
입력한 숫자 0는 벡터에 포함되어 있지 않습니다.
```

isFound 변수를 사용하여 사용자 입력값이 벡터에 포함되어 있는지 여부를 추적합니다.
벡터를 순회하며 각 숫자를 사용자 입력값과 비교합니다.
일치하는 값을 찾으면 isFound 변수를 true로 설정하고 루프를 종료합니다.
루프가 종료된 후 isFound 변수를 확인하여 결과를 출력합니다.

[문제로 돌아 가기](README.md "문제로 돌아 가기")
