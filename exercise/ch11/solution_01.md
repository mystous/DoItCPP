#### 문제 1 표준 문자열 라이브러리 활용
어떤 문자열이든지 문장 안에 있는 ‘고양이’를 ‘강아지’로 바꾸는 함수를 만들어 보세요.
그리고 해당 함수가 잘 동작하는지 메인 함수에서 확인하는 코드도 작성해 보세요.
<br/><br/>

---

#### 모범 답안 과 설명
##### 답안
```cpp
#include <iostream>
#include <string>

using namespace std;

string replace_cat_with_dog(string sentence) {
  // '고양이'를 찾을 위치
  size_t pos = 0;
  string str_cat = "고양이";
  size_t str_len = str_cat.length();

  // '고양이'를 찾을 때까지 반복
  while ((pos = sentence.find("고양이", pos)) != string::npos) {
    // '고양이'를 '강아지'로 바꿈
    sentence.replace(pos, str_len, "강아지");
    // 다음 '고양이'를 찾을 위치를 갱신
    pos += str_len;
  }

  return sentence;
}

int main() {
  string sentence1 = "오늘 고양이가 생선을 먹었다. 배가 부른 고양이는 기분이 좋다.";
  string sentence2 = "나는 고양이를 좋아한다. 하지만 우리집 고양이는 내가 간식줄 때만 찾아온다.";

  // '고양이'를 '강아지'로 바꾼 문장 출력
  cout << replace_cat_with_dog(sentence1) << endl;
  cout << replace_cat_with_dog(sentence2) << endl;

  return 0;
}
```

##### 설명
실행결과
```cpp
오늘 강아지가 생선을 먹었다. 배가 부른 강아지는 기분이 좋다.
나는 강아지를 좋아한다. 하지만 우리집 강아지는 내가 간식줄 때만 찾아온다.
```

<li>replace_cat_with_dog 함수는 문자열을 입력받아 '고양이'를 '강아지'로 바꾸고 변경된 문자열을 반환합니다.</li>
<li>find 함수를 사용하여 '고양이'를 찾고 replace 함수를 사용하여 '강아지'로 바꿉니다.</li><br>

[문제로 돌아 가기](README.md "문제로 돌아 가기")
