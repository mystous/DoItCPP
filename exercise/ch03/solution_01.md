#### 문제 1 포인터 활용
다음 규칙을 따르는 간단한 프로그램을 만들고 실행해 보세요.
1. 크기가 5인 정수 배열을 동적으로 할당하고 이를 가리키는 포인터를 선언하세요.
2. 동적으로 할당한 배열에 1부터 5까지의 값을 저장하세요.
3. 할당한 배열의 내용을 출력하세요.
4. 할당한 메모리를 해제하세요.
<br/><br/>

---

#### 모범 답안 과 설명
##### 답안
```cpp
#include <iostream>

using namespace std;

int main() {
  // 1. 크기가 5인 정수 배열을 동적으로 할당하고, 이를 가리키는 포인터를 선언
  int* arr = new int[5];

  // 2. 동적으로 할당한 배열에 1부터 5까지의 값을 저장
  for (int i = 0; i < 5; i++) {
    arr[i] = i + 1;
  }

  // 3. 할당한 배열의 내용을 출력
  for (int i = 0; i < 5; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  // 4. 할당한 메모리를 해제
  delete[] arr;

  return 0;
}
```
##### 설명
<li>new int[5]는 크기가 5인 정수 배열을 동적으로 할당하고, 이를 가리키는 포인터를 반환합니다.</li>
<li>delete[] arr은 arr이 가리키는 메모리를 해제합니다.</li><br>

[문제로 돌아 가기](README.md "문제로 돌아 가기")
