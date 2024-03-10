#### 문제 1 벡터 다루기
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
  vector<int> numbers = { 2, 7, 1, 8, 3, 6, 4, 5, 9 };

  // 홀수를 제거하고 짝수만 남은 벡터 생성
  vector<int> evenNumbers;
  for (int num : numbers) {
    if (num % 2 == 0) {
      evenNumbers.push_back(num);
    }
  }

  // 결과 출력
  for (int num : evenNumbers) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
```

##### 설명
실행결과
```cpp
2 8 6 4
```

<li>vector<int> numbers = {2, 7, 1, 8, 3, 6, 4, 5, 9};
numbers라는 이름의 정수 벡터를 선언하고 초기화합니다. 초기값은 {2, 7, 1, 8, 3, 6, 4, 5, 9}입니다.</li>
<li>vector<int> evenNumbers;
evenNumbers라는 이름의 정수 벡터를 선언합니다. 홀수를 제거하고 짝수만 남은 값을 저장할 벡터입니다.</li>
<li>for (int num : numbers)
numbers 벡터를 순회하며 각 숫자를 num 변수에 저장합니다.</li>
<li>if (num % 2 == 0)
num 변수가 짝수인지 검사합니다. 짝수는 2로 나눈 나머지가 0입니다.</li>
<li>evenNumbers.push_back(num)
num 변수가 짝수라면 evenNumbers 벡터에 추가합니다.</li>
<li>for (int num : evenNumbers)
evenNumbers 벡터를 순회하며 각 숫자를 num 변수에 저장합니다.</li><br>

[문제로 돌아 가기](README.md "문제로 돌아 가기")
