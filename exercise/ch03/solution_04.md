#### 문제 4 레퍼런스 변수
다음 코드는 컴파일 오류가 발생합니다. 그 이유를 설명해 보세요.<br>
```cpp
int &ref_invalid_value;
```
<br/>

---

#### 모범 답안 과 설명
##### 답안
ref_invalid_value는 레퍼런스 변수입니다.
레퍼런스 변수는 선언 시 반드시 초기화해야합니다.
초기화하지 않은 레퍼런스 변수는 유효하지 않은 값을 참조하게 되어 컴파일 오류가 발생합니다.

[해결방법]
레퍼런스 변수를 선언할 때 다른 변수를 참조하도록 초기화해야 합니다.
다음과 같이 초기화하면 컴파일 오류가 해결됩니다.
```cpp
int x = 10;
int &ref_valid_value = x; // x 변수를 참조하는 참조 변수 선언
```

##### 설명
<li>레퍼런스 변수는 별칭(alias)이라고도 생각할 수 있습니다.</li>
<li>레퍼런스 변수를 통해 접근하는 값은 실제로 참조하는 변수의 값을 변경합니다.</li>
<li>레퍼런스 변수는 상수 변수를 참조할 수 없습니다.</li>
<li>레퍼런스 변수는 포인터와 유사하지만, 포인터보다 사용하기 편리하고 안전합니다.</li><br>

[문제로 돌아 가기](README.md "문제로 돌아 가기")
