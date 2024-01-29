#include <iostream>
#include <list> 

using namespace std;

int main() {
  list<int> myList;

  // 리스트 뒤쪽에 값 추가
  myList.push_back(2);
  myList.push_back(3);
  myList.push_back(4);

  // 리스트 앞쪽에 값 추가
  myList.push_front(1);
  myList.push_front(0);

  // 리스트 출력
  cout << "리스트 출력: ";
  for (const int& value : myList) {
    cout << value << " ";
  }
  cout << endl;

  myList.pop_front();   // 첫 번째 요소 제거
  myList.pop_back();  // 마지막 요소 제거

  // 삭제 후 리스트 출력
  cout << "삭제 후 리스트 출력: ";
  for (const int& value : myList) {
    cout << value << " ";
  }
  cout << endl;

  // 리스트 크기 확인
  cout << "리스트 크기: " << myList.size() << endl;

  // 리스트가 비었는지 확인
  cout << "리스트가 비었는가? " << (myList.empty() ? "예" : "아니오") << endl;

  return 0;
}