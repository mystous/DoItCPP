#include <iostream>

using namespace std;

string show_doll(string doll) {
  return "'" + doll + "' 안쪽에 ";
}

template<typename... dolls>
string find_doll(dolls... doll_list) {
 return (show_doll(doll_list) + ...);
}

int main() {
  cout << "첫번째 마트료시카 ";
  cout << find_doll(string("대형"), string("중형"), string("소형"));
  cout << "있습니다." << endl << endl;

  cout << "두번째 마트료시카 ";
  cout << find_doll(string("특대형"), string("대형"), string("중형"), string("소형"), string("극소형"));
  cout << "있습니다." << endl;

  return 0;
}