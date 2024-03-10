#### 문제 3 어설션을 이용한 예외 처리
다음 코드를 바탕으로 assert를 이용해 예외 처리를 구현해 보세요.

```cpp
void divide(int a, int b) {
  // b가 0일 때 assert로 예외 처리
}

int main() {
  divide(10, 2);
  divide(5, 0);
  return 0;
}
```
<br/>

---

#### 모범 답안 과 설명
##### 답안
```cpp
void divide(int a, int b) {
  // b가 0인 경우 어설션을 이용하여 예외 처리
  assert(b != 0, "b는 0이 될 수 없습니다!");

  int result = a / b;
  std::cout << "결과: " << result << std::endl;
}

int main() {
  divide(10, 2); // 결과: 5 출력
  divide(5, 0); // 프로그램 종료, "b는 0이 될 수 없습니다!" 메시지 출력
  return 0;
}
```
##### 설명
<li>assert는 디버깅 도구이며, 릴리스 버전에서는 제거됩니다.</li>
<li>assert는 예외 처리보다 간단하지만, 예외 정보를 제공하지 못하고 프로그램을 종료하기 때문에 주의해야 합니다.</li><br>

[문제로 돌아 가기](README.md "문제로 돌아 가기")

