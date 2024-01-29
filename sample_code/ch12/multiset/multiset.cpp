#include <iostream>
#include <set>

using namespace std;

int main() {
  multiset<int> myMultiset;

  // 값 삽입
  myMultiset.insert(5);
  myMultiset.insert(2);
  myMultiset.insert(5);   // 중복된 값도 저장됨

  // 특정 값의 개수 출력
  int count = myMultiset.count(5);
  cout << "저장되어 있는 5의 갯수: " << count << endl;

  // 멀티 세트를 순회하며 값 출력
  for (auto it = myMultiset.begin(); it != myMultiset.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;

  // 멀티 세트의 크기 출력
  int size = myMultiset.size();
  cout << "multiset 크기: " << size << endl;

  return 0;
}