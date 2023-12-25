#include <iostream>
#include <io.h>
#include <fcntl.h>

using namespace std;

int main() {
  wchar_t message_korean[] = L"반갑다 세계야!";      // 한국어 
  wchar_t message_chinese[] = L"你好，世界!";        // 중국어 
  wchar_t message_japanese[] = L"ハロー・ワール!";   // 일본어 
  wchar_t message_russian[] = L"Привет мир!";        // 러시아어

  cout << "Hello, world!" << endl;

  _setmode(_fileno(stdout), _O_U16TEXT); // 윈도우 콘솔 창 유니코드 출력 모드 설정

  wcout << message_korean << endl;
  wcout << message_chinese << endl;
  wcout << message_japanese << endl;
  wcout << message_russian << endl;

  return 0;
}
