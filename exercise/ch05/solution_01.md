#### 문제 1 try, catch, throw 문 이해하기
다음 코드를 바탕으로 try, catch, throw 문을 이용해 예외를 처리해 보세요.
```cpp
int main() {
  int divisor = 0;

  // 여기에 예외 처리를 추가해 보세요.
  int result = 10 / divisor;
  std::cout << "결과: " << result << std::endl;
  return 0;
}
```
<br/>

---

#### 모범 답안 과 설명
##### 답안
```cpp
int main() {
  try {
    int divisor = 0;
    // 0으로 나누려는 경우 예외 발생
    if (divisor == 0) {
      throw std::runtime_error("0으로 나눌 수 없습니다!");
    }
    int result = 10 / divisor;
    std::cout << "결과: " << result << std::endl;
  }
  catch (const std::runtime_error& e) {
    // 예외 발생 시 처리
    std::cout << "예외 발생: " << e.what() << std::endl;
  }
  return 0;
}
```
##### 설명
이전에는 등장하지 않았지만, std::runtime_error를 활용하는 법도 소개하고자 살짝 응용하여 답을 구성해보았습니다.

<li>try 블록: 예외가 발생할 가능성이 있는 코드를 감쌉니다.</li>
<li>throw 키워드: 예외를 발생시킵니다.</li>
<li>catch 블록: 특정 유형의 예외가 발생했을 때 처리 코드를 담습니다.</li>
<li>std::runtime_error: 런타임 오류를 나타내는 예외 클래스입니다.</li>
<li>e.what(): 예외 메시지를 출력합니다.</li><br>

[문제로 돌아 가기](README.md "문제로 돌아 가기")
