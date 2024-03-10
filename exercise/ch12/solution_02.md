#### 문제 2 스택 다루기
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
<br/>

---

#### 모범 답안 과 설명
##### 답안
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

  // 스택에서 가장 작은 값 찾기
  double minValue = myStack.top();
  while (!myStack.empty()) {
    double topValue = myStack.top();
    myStack.pop();
    if (topValue < minValue) {
      minValue = topValue;
    }
  }

  // 결과 출력
  cout << "스택에서 가장 작은 값: " << minValue << endl;

  return 0;
}
```

##### 설명
실행결과
```cpp
스택에서 가장 작은 값: 1.23
```

minValue 변수에 스택의 가장 위에 있는 값을 저장합니다.
스택이 비어질 때까지 반복합니다. 반복마다 스택의 가장 위에 있는 값을 topValue 변수에 저장합니다.
topValue 변수와 minValue 변수를 비교하고 더 작은 값을 minValue 변수에 저장합니다.
반복이 끝난 후 minValue 변수에는 스택에서 가장 작은 값이 저장됩니다.

[문제로 돌아 가기](README.md "문제로 돌아 가기")
