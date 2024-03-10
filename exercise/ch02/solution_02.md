#### 문제 2 데이터 형식
0.5f 5u, 5L에 어울리는 각각의 변수를 선언하고 출력해 보세요.
<br/><br/>

---

#### 모범 답안 과 설명
##### 답안
```cpp
#include <iostream>

using namespace std;

int main() {
  // 0.5f에 어울리는 변수
  float float_num = 0.5f;
  cout << "float_num: " << float_num << endl;

  // 5u에 어울리는 변수
  unsigned int unsigned_num = 5u;
  cout << "unsigned_num: " << unsigned_num << endl;

  // 5L에 어울리는 변수
  long int long_num = 5L;
  cout << "long_num: " << long_num << endl;

  return 0;
}
```
##### 설명
<li>0.5f는 부동소수점 숫자입니다. float 타입 변수에 저장할 수 있습니다.</li>
<li>5u는 부호 없는 정수입니다. unsigned int 타입 변수에 저장할 수 있습니다.</li>
<li>5L는 긴 정수입니다. long int 타입 변수에 저장할 수 있습니다.</li><br>

[문제로 돌아 가기](README.md "문제로 돌아 가기")
