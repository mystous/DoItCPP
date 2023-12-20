#include <iostream>
#include <random>
using namespace std;

class character {
public:
  character() {
    cout << "character 클래스 생성자" << endl;
  };
};

class monster {
public:
  monster() {
    cout << "monster 클래스 생성자" << endl;
  };
};

//몬스터 A는 기본 Monster 클래스로부터 상속
class monster_a : public monster, character {
public:
  monster_a() {
    //cout << this << " monster_a 클래스 생성자" << endl;
    cout << "monster_a 클래스 생성자" << endl;
    monster_a(10, 10);
  };

  monster_a(int x, int y) : location{ x, y } {
    //cout << this << " monster_a 클래스 생성자 (인자 추가)" << endl;
    cout << "monster_a 클래스 생성자 (인자 추가)" << endl;
  };
  void show_location() {
    //cout << this << " 위치(" << location[0] << " , " << location[1] << ")" << endl;
    cout << "위치(" << location[0] << " , " << location[1] << ")" << endl;
  };

private:
  int location[2];
};

int main() {
  monster_a forest_monster;
  forest_monster.show_location();

  return 0;
}