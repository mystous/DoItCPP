#include <iostream>
#include <set>

using namespace std;

int main() {
  set<int> mySet;
  mySet.insert(5);
  mySet.insert(2);
  mySet.insert(5);   // 중복된 값, 저장되지 않음!

  cout << "set 크기: " << mySet.size() << endl;

  return 0;
}
