#include <iostream>

using namespace std;

class monster {
public:
  void create_monster() = delete;
  //void create_monster_() {}; // delete 예약어를 사용하지 않고 제거된 함수
};

int main() {
  monster monster_sample;

  // TODO : 오류 메세지를 보기 위해서는 15, 16 번째 라인의 코멘트를 제거 하세요.
  //monster_sample.create_monster();
  //monster_sample.create_monster_();
  return 0;
}