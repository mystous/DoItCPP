#include <iostream>
#include <random>
using namespace std;

class character {
public:
  character() {
    cout << "character 클래스 생성자" << endl;
  };
  ~character() {
    cout << "charactor 클래스 소멸자" << endl;
  }
};

class monster {
public:
  monster() {
    cout << "monster 클래스 생성자" << endl;
  };
  virtual ~monster() {
    //~monster() {
    cout << "monster 클래스 소멸자" << endl;
  };
};

//몬스터 A는 기본 Monster 클래스로부터 상속
class monster_a : public monster, character {
public:
  monster_a() : monster_a(10, 10) {
    cout << "monster_a 클래스 생성자" << endl;
  };

  monster_a(int x, int y) : location{ x, y } {
    cout << "monster_a 클래스 생성자 (매개변수 추가)" << endl;
  };

  void show_location() {
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