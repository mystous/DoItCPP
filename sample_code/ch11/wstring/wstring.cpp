#include <iostream>
#include <string>

using namespace std;

int main() {
  // setlocale 함수를 사용하여 프로그램의 로케일(locale)을 변경
  // LC_ALL은 '모든 로케일' 설정으로 지정을 의미함
  setlocale(LC_ALL, "");

  // wstring을 사용하여 유니코드 문자열을 초기화
  // L 접두사를 붙여 유니코드 문자열임을 나타냄
  wstring korString = L"안녕하세요";

  // wcout을 사용하여 유니코드 문자열을 출력
  // wcout은 유니코드 문자열을 출력하기 위한 wide character 출력 스트림
  wcout << korString << endl;

  return 0;
}