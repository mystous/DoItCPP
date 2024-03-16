#### 문제 2 상수 지정자 constexpr
constexpr을 사용하는 함수와 일반 함수를 사용하는 코드를 자유롭게 작성해 보세요. 그리고 constexpr 을 사용하지 않는 함수를 작성해서 2개의 함수 호출 시 전체 실행 시간의 차이를 비교해 보세요.
<br/><br/>

---


#### 모범 답안 과 설명
##### 답안
```cpp
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define COMPLEX_CALCU_CODE \
  int result = 0;\
  int truncation = 1024;\
\
  for (int j = 0; j < size; ++j) {\
    result += data_origin[j];\
    result %= truncation;\
  }\
\
  result = 1;\
  for (int j = 0; j < size; ++j) {\
    result *= data_origin[j];\
    result %= truncation;\
  }\
\
  return result\

constexpr int complex_calculation_constexpr(const int data_origin[], const int size) {
  COMPLEX_CALCU_CODE;
}

int complex_calculation(const int data_origin[], const int size) {
  COMPLEX_CALCU_CODE;
}

int main()
{
  constexpr int data_origin[300] = {
         34, 67, 23, 89, 45, 21, 78, 92, 31, 10, 88, 46, 53, 72, 15, 69, 80, 95, 2, 5,
         20, 37, 48, 60, 11, 99, 6, 55, 18, 43, 76, 14, 27, 33, 63, 3, 85, 41, 17, 26,
         9, 58, 64, 79, 93, 12, 30, 44, 68, 81, 1, 4, 7, 13, 16, 19, 22, 25, 28, 32,
         35, 38, 42, 47, 50, 54, 57, 61, 65, 70, 73, 77, 82, 86, 90, 94, 98, 8, 24, 29,
         36, 39, 49, 51, 56, 59, 62, 66, 71, 74, 75, 83, 84, 87, 91, 96, 97, 100, 40, 52,
         23, 58, 72, 45, 89, 67, 12, 39, 14, 95, 62, 34, 11, 78, 56, 90, 31, 84, 25, 47,
         98, 2, 76, 54, 41, 60, 82, 29, 17, 33, 51, 93, 4, 86, 73, 37, 15, 69, 99, 22,
         44, 68, 5, 80, 13, 30, 46, 61, 7, 91, 36, 50, 19, 85, 28, 63, 74, 3, 92, 40,
         57, 10, 83, 26, 48, 65, 75, 8, 94, 53, 38, 6, 81, 24, 49, 66, 77, 9, 97, 55,
         42, 18, 87, 27, 52, 64, 79, 1, 96, 59, 35, 20, 88, 21, 43, 70, 71, 16, 100, 60,
         32, 64, 98, 11, 49, 23, 77, 5, 33, 17, 58, 92, 39, 14, 73, 29, 86, 44, 50, 9,
         75, 41, 2, 68, 34, 80, 12, 56, 20, 47, 63, 31, 89, 26, 38, 95, 54, 10, 82, 28,
         45, 67, 13, 79, 25, 48, 61, 7, 93, 36, 52, 19, 84, 27, 43, 69, 76, 4, 94, 57,
         37, 6, 78, 22, 46, 65, 70, 8, 91, 51, 40, 15, 88, 24, 55, 72, 81, 3, 100, 53,
         30, 62, 99, 21, 59, 74, 83, 16, 98, 49, 32, 18, 85, 29, 60, 71, 90, 1, 97, 58 };

  int i = 0, result = 0;
  const int repeat_count = 1000000;

  time_point<chrono::high_resolution_clock> start = high_resolution_clock::now();

  for (i = 0; i < repeat_count; ++i) {
    result = complex_calculation(data_origin, 300);
  }

  time_point<chrono::high_resolution_clock> end = high_resolution_clock::now();
  milliseconds duration = duration_cast<milliseconds>(end - start);
  cout << "일반 함수 실행 시간: " << duration.count() << " 밀리세컨드" << endl;

  start = high_resolution_clock::now();

  for (i = 0; i < repeat_count; ++i) {
    constexpr int result_ = complex_calculation_constexpr(data_origin, 300);
  }

  end = high_resolution_clock::now();
  duration = duration_cast<milliseconds>(end - start);
  cout << "constexpr 함수 실행 시간: " << duration.count() << " 밀리세컨드" << endl;

  return 0;
}
```
###### 실행결과
```
일반 함수 실행 시간: 6950 밀리세컨드
constexpr 함수 실행 시간: 1 밀리세컨드
```
* 실행 결과는 컴퓨터마다 매우 다릅니다.

##### 설명
동일한 함수 코드를 사용하기 위하여 코드 블럭을 매크로 COMPLEX_CALCU_CODE로 정의 하여 두 함수에서 동시에 사용했습니다. 두 함수는 constexpr로 선언 여부를 제외하고는 모두 동일합니다.

확실한 차이를 보이기 위하여 함수 호출을 repeat_count 만큰 반복 하였습니다. constexpr로 선언된 함수는 컴파일 시점에 상수식으로 대체되기 때문에 수행 시간이 매우 짧은 것을 확인할 수 있습니다.

[문제로 돌아 가기](README.md "문제로 돌아 가기")
