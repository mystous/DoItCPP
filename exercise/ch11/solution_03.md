#### 문제 3 파일 시스템: 디렉터리 탐색
특정 디렉터리에 위치한 모든 텍스트 파일의 이름과 크기를 출력하는 프로그램을 작성해 보세요.
각 파일의 정보는 filesystem::file_size 함수를 이용하여 얻을 수 있습니다.
<br/><br/>

---

#### 모범 답안 과 설명
##### 답안
```cpp
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

using namespace std;
namespace fs = std::filesystem;

int main() {
  // 디렉터리 경로 설정
  fs::path dir_path = "my_folder";

  // 디렉터리 내 모든 파일 목록을 벡터에 저장
  vector<fs::path> files;
  for (const fs::directory_entry& entry : fs::directory_iterator(dir_path)) {
    if (entry.is_regular_file() && entry.path().extension() == ".txt") {
      files.push_back(entry.path());
    }
  }

  // 각 파일의 이름과 크기 출력
  for (std::vector<fs::path>::iterator it = files.begin(); it != files.end(); ++it) {
    fs::path file = *it;
    std::uintmax_t file_size = fs::file_size(file);
    cout << "파일 이름: " << file.filename() << endl;
    cout << "파일 크기: " << file_size << " 바이트" << endl << endl;
  }

  return 0;
}
```

##### 설명
실행결과
```cpp
파일 이름: "_test.txt"
파일 크기: 13 바이트
```

<li>dir_path 변수에 원하는 디렉터리 경로를 설정합니다. 여기서는 [문제2]에서 만든 my_folder 디렉터리를 검색하도록 하였습니다.</li>
<li>directory_iterator를 사용하여 디렉터리 내 모든 파일을 순회합니다.</li>
<li>is_regular_file() 함수를 사용하여 파일이 정규 파일인지 확인합니다.</li>
<li>path().extension() 함수를 사용하여 파일 확장자가 .txt인지 확인합니다.</li>
<li>files 벡터에 .txt 확장자를 가진 정규 파일의 경로를 저장합니다.</li>
<li>file_size() 함수를 사용하여 각 파일의 크기를 얻습니다.</li><br>

[문제로 돌아 가기](README.md "문제로 돌아 가기")
