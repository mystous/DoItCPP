#### 문제 2 C++17
C++17에서 새로 도입된 파일 시스템 라이브러리에 관한 자료를 찾아보세요.
<br/><br/>

---


#### 모범 답안 과 설명
##### 답안
C++17부터 STL에서 파일시스템 라이브러리(filesystem)를 사용할 수 있습니다. 이전까지는 운영체제별로 상이한 파일 시스템 라이브러리를 사용하거나 별도로 제공되는 파일I/O 표준 라이브러리(ex. POSIX)를 사용해야 했습니다. 그러나 STL의 파일시스템 라이브러리를 사용하면 파일/디렉터리의 생성, 삭제, 갱신 등의 가능하며 디렉터리의 내용을 순회하거나 파일의 특성을 확인하는 등의 작업을 할 수 있습니다.

무엇보다 STL을 사용하여 운영체제와 무관하게 사용할 수 있다는 점이 가장 큰 장점입니다. 

cppreference.com에서 상세한 표준 내용을 확인할 수 있습니다. [CPP레퍼런스 파일 시스템](https://en.cppreference.com/w/cpp/filesystem)

[문제로 돌아 가기](README.md "문제로 돌아 가기")
