#include <iostream>

using namespace std;

class monster {
public:
  void create_monster() = delete;
  //void create_monster_() {}; // delete 예약어를 사용하지 않고 제거된 함수
};

int main() {
  monster monster_sample;

  // 아래 두 줄은 오류가 발생합니다.
  monster_sample.create_monster();
  monster_sample.create_monster_();
  return 0;
}