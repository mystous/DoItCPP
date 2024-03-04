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
<li>delete[] arr은 arr이 가리키는 메모리를 해제합니다.</li>