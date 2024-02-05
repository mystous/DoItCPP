#include <iostream>

using namespace std;

class monster {
public:
  void create_monster() = delete;
  //void create_monster_() {}; // delete 키워드를 사용하지 않고 제거
};

int main() {
  monster monster_sample;

  // 아래 두 줄은 오류가 발생합니다.
  monster_sample.create_monster();
  monster_sample.create_monster_();
  return 0;
}