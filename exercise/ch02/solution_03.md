#### 문제 3 변수의 유효 범위와 형식 변환
다음 코드에서 컴파일 오류가 발생하는 부분이 있습니다. 위치와 원인을 설명해 보세요.
<br/><br/>

---

#### 모범 답안 과 설명
##### 답안
[컴파일 에러가 발생하는 부분]
```cpp
std::cout << "Inner Variable: " << inner_variable << std::endl;
```
변수 inner_variable은 {} 블록 내에서만 유효합니다.
{} 블록 밖에서 inner_variable을 사용하려고 하면 컴파일 에러가 발생합니다.
</br></br>
[해결방법]
```cpp
int outer_variable = 10;
{
	int inner_variable = 5;
	std::cout << "Inner Variable: " << inner_variable << std::endl;
	std::cout << "Outer Variable: " << outer_variable << std::endl;
}

// inner_variable을 블록 밖에서 다시 선언
int inner_variable = 100;

std::cout << "Inner Variable: " << inner_variable << std::endl;
```

##### 설명
inner_variable을 {} 블록 밖에서 사용하려면 블록 밖에서 다시 선언해야 합니다.
C++에서 변수의 유효 범위는 선언된 블록 안에만 국한됩니다.

[문제로 돌아 가기](README.md "문제로 돌아 가기")
