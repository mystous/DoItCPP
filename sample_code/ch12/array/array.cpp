#include <iostream>
#include <array>

using namespace std;

int main() {
  // 크기가 5인 std::array 생성
  array<int, 5> myArray;

  // 배열 초기화
  myArray = { 1, 2, 3, 4, 5 };

  // 배열 출력
  cout << "배열 출력: ";
  for (int i = 0; i < 5; i++) {
    cout << myArray[i] << " ";
  }
  cout << endl;

  // 배열 크기 출력
  cout << "배열 크기: " << myArray.size() << endl;

  // 배열의 첫 번째 요소 출력
  cout << "첫 번째 요소: " << myArray[0] << endl;

  // 배열의 두 번째 요소 변경
  myArray[1] = 10;

  // 변경된 배열 출력
  cout << "변경된 배열: ";
  for (int i = 0; i < 5; i++) {
    cout << myArray[i] << " ";
  }
  cout << endl;

  return 0;
}
