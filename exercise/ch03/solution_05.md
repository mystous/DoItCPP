#### 모범 답안 과 설명
##### 답안
1. 값에 의한 호출: 함수 호출 시 인자의 값을 복사하여 함수 내에서 사용합니다.
2. 참조에 의한 호출: 함수 호출 시 인자의 주소를 복사하여 함수 내에서 사용합니다.
3. 주소에 의한 호출: 값에 의한 호출과 비슷하지만, 인자 값을 복사하는 대신 포인터를 사용하여 직접 값을 변경합니다.
</br>

##### 설명
코드 예시
```cpp
// 값에 의한 호출
void swap_value(int a, int b) {
  int temp = a;
  a = b;
  b = temp;
}

// 참조에 의한 호출
void swap_reference(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// 주소에 의한 호출 (C 언어)
void swap_address(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
```
