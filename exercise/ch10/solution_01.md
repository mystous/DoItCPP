### 문제 1 함수 템플릿 #1
템플릿을 사용해 다양한 데이터 형식의 값을 출력하는 함수를 만들어 보세요. print_data(T data) 형식으로 함수 템플릿을 만들어서 cout으로 “입력받은 값은 :”이라는 문장과 함께 입력받은 값을 출력하는 함수를 만들어 보세요.
<br/><br/>

---

#### 모범 답안
##### 답안
```cpp
#include <iostream>

using namespace std;

template<typename T>
void print_data(T data) {
  cout << "입력받은 값은 : " << data << endl;
}

int main()
{
  print_data("함수 템플릿 되새김 문제");
  print_data(10);
  print_data('A');
  return 0;
}
```
##### 실행결과
```
입력받은 값은 : 함수 템플릿 되새김 문제
입력받은 값은 : 10
입력받은 값은 : A
```
##### 설명
템플릿 매개변수를 선언 한 후에 인자로 입력된 값을 cout으로 출력합니다.
만약 cout으로 출력이 어려운 자료형이 입력되면 오류가 발생합니다.


[문제로 돌아 가기](README.md "문제로 돌아 가기")
