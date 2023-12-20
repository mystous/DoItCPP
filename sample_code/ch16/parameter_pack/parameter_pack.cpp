#include <iostream>

using namespace std;

template<typename doll>
void find_doll(doll doll_name) {
  cout << "'" << doll_name << "'(이)가 ";
}

template<typename doll, typename... dolls>
void find_doll(doll doll_name, dolls... doll_list) {
  find_doll(doll_list...);
  cout << "'" << doll_name << "' 안쪽에 ";
}

int main() {
  cout << "첫번째 마트료시카 ";
  find_doll("대형", "중형", "소형");
  cout << "있습니다." << endl << endl;
  
  cout << "두번째 마트료시카 ";
  find_doll("특대형", "대형", "중형", "소형", "극소형");
  cout << "있습니다." << endl;

  return 0;
}