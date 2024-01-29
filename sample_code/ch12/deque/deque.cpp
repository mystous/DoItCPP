#include <iostream>
#include <deque>

using namespace std;

int main() {
  deque<int> myDeque;

  // 덱 뒤쪽에 값 추가
  myDeque.push_back(2);
  myDeque.push_back(3);
  myDeque.push_back(4);

  // 덱 앞쪽에 값 추가
  myDeque.push_front(1);
  myDeque.push_front(0);

  // 덱 출력
  cout << "deque 출력: ";
  for (const int& value : myDeque) {
    cout << value << " ";
  }
  cout << endl;

  myDeque.pop_front();   // 첫 번째 요소 제거
  myDeque.pop_back();  // 마지막 요소 제거

  // 삭제 후 덱 출력
  cout << "삭제 후 deque 출력: ";
  for (const int& value : myDeque) {
    cout << value << " ";
  }
  cout << endl;

  // 덱 크기 확인
  cout << "deque 크기: " << myDeque.size() << endl;

  // 덱이 비었는지 확인
  cout << "deque이 비었는가? " << (myDeque.empty() ? "예" : "아니오") << endl;

  // 덱의 첫 번째와 마지막 원소 출력
  cout << "deque 첫 번째 원소: " << myDeque.front() << endl;
  cout << "deque 마지막 원소: " << myDeque.back() << endl;

  return 0;
}