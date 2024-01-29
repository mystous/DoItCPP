#include <iostream>
#include <string>
#include <filesystem> // 파일 시스템 헤더 파일
#include <fstream>    // 파일 입출력 헤더 파일

using namespace std;

namespace fs = filesystem;

int main() {
  // 1. 디렉터리 생성
  fs::create_directories("MyDirectory");

  // 2. 파일 생성 및 쓰기
  ofstream outFile("MyDirectory/myFile.txt");
  outFile << "Hello, FileSystem Library!" << endl;
  outFile.close();

  // 3. 디렉터리 내의 파일 확인
  cout << "Files in MyDirectory:\n";
  for (const fs::directory_entry& entry : fs::directory_iterator("MyDirectory")) {
    if (entry.is_regular_file()) {
      cout << entry.path().filename() << endl;
    }
  }

  // 4. 파일 읽기
  ifstream inFile("MyDirectory/myFile.txt");
  string line;
  while (getline(inFile, line)) {
    cout << line << endl;
  }
  inFile.close();

  // 5. 파일 및 디렉터리 삭제
  fs::remove_all("MyDirectory");

  return 0;
}
