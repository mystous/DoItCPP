#include <iostream>
#include <set>

using namespace std;

int main() {
  set<int> mySet;

  // 값 삽입
  mySet.insert(5);
  mySet.insert(2);
  mySet.insert(8);

  // 값 5가 세트에 있는지 확인
  if (mySet.find(5) != mySet.end()) {
    cout << "5는 set에 저장되어 있음" << endl;
  }

  // 세트를 순회하며 값 출력
  for (auto it = mySet.begin(); it != mySet.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;

  // 세트의 크기 출력
  int size = mySet.size();
  cout << "set 크기: " << size << endl;

  return 0;
}