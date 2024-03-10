#### 문제 2 예외 처리 생략과 실패 대응
다음 코드에서 try, catch 문으로 예외를 처리하고 생략된 예외와 실패에 대응하는 코드를 작성해 보세요.
```cpp
void process(int value) {
  // value가 음수인 경우 예외를 던지도록 처리
  // 예외가 발생하면 "예외 발생!" 출력, 발생하지 않으면 value 출력
}

int main() {
  process(10);
  process(-5);
  return 0;
}
```
<br/>

---

#### 모범 답안 과 설명
##### 답안
```cpp
void process(int value) {
  try {
    // value가 음수인 경우 예외 발생
    if (value < 0) {
      throw std::runtime_error("음수 값을 처리할 수 없습니다!");
    }
    // 예외가 발생하지 않으면 value 출력
    std::cout << "value: " << value << std::endl;
  }
  catch (const std::runtime_error& e) {
    // 예외 발생 시 "예외 발생!" 출력
    std::cout << "예외 발생! : " << e.what() << std::endl;
  }
  catch (...) {
    // 예외 종류에 관계없이 실패 대응
    std::cout << "처리에 실패했습니다." << std::endl;
  }
}

int main() {
  process(10);  // value: 10 출력
  process(-5); // 예외 발생: 음수 값을 처리할 수 없습니다! 출력
  return 0;
}
```
##### 설명
<li>process() 함수에서 try-catch 구문을 사용하여 예외를 처리합니다.</li>
<li>std::runtime_error: 런타임 오류를 나타내는 예외 클래스입니다.</li>
<li>e.what(): 예외 메시지를 출력합니다.</li>
<li>catch (...): 마지막 catch 블록은 모든 예외를 처리합니다.</li><br>

[문제로 돌아 가기](README.md "문제로 돌아 가기")
