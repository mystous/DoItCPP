#### 문제 2 파일 시스템: 디렉터리 생성, 파일 생성 및 쓰기
실행 파일이 있는 곳의 하위 디렉터리에 my_folder/_test.txt 파일을 생성해 보세요.
_test.txt 파일에는 여러분의 영문 이름을 기록해 보세요.
<br/><br/>

---

#### 모범 답안 과 설명
##### 답안
```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

int main() {
  // 디렉터리 생성
  fs::create_directories("my_folder");

  // 파일 생성 및 쓰기
  ofstream output_file("my_folder/_test.txt");

  if (output_file.is_open()) {
    output_file << "_Your Name_\n";
    output_file.close();
    cout << "파일이 생성되고 이름이 기록되었습니다." << endl;
  }
  else {
    cerr << "파일을 열 수 없습니다." << endl;
  }

  return 0;
}
```

##### 설명
```cpp
파일이 생성되고 이름이 기록되었습니다.
```

<li>namespace fs = std::filesystem;
std::filesystem 네임스페이스에 별칭을 지정하여 편리하게 사용할 수 있도록 합니다.</li>
<li>fs::create_directories("my_folder");
현재 디렉터리에 my_folder라는 하위 디렉터리를 생성합니다. 이미 디렉터리가 존재하면 아무런 동작을 하지 않습니다.</li></li>
<li>ofstream output_file("my_folder/_test.txt");
my_folder 디렉터리에 _test.txt 파일을 생성하기 위해 파일 출력 스트림을 생성합니다.</li>
<li>if (output_file.is_open()) { ... } else { ... }
파일이 정상적으로 열렸는지 확인합니다. 열린 경우에는 파일에 이름을 기록하고 출력 스트림을 닫습니다. 열리지 않은 경우에는 에러 메시지를 출력합니다.</li>
<li>output_file << "_Your Name_\n";
파일에 _Your Name_이라는 문자열을 기록합니다. 여기서 _Your Name_은 여러분의 영문 이름으로 넣어보세요.</li><br>

[문제로 돌아 가기](README.md "문제로 돌아 가기")
