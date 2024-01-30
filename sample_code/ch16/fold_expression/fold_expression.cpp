#include <iostream>

using namespace std;

template<typename doll>
doll show_doll(doll doll_name) {
  return "'" + doll_name + "' 안쪽에 ";
}

template<typename... dolls>
string find_doll(dolls... doll_list) {
  // 폴드 표현식 사용
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