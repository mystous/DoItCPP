#include <iostream>
#include <random>
using namespace std;

class monster {
public:
  monster() {
    cout << "monster 클래스 생성자" << endl;
  };
  ~monster() {
    cout << "monster 클래스 소멸자" << endl;
  };
};

//몬스터 A는 기본 Monster 클래스로부터 상속
class monster_a : public monster {
public:
  monster_a() {
    cout << "monster_a 클래스 생성자" << endl;
  };

  monster_a(int x, int y) : location{ x, y } {
    cout << "monster_a 클래스 생성자 (인자 추가)" << endl;
  };
  ~monster_a() {
    cout << "monster_a 클래스 소멸자" << endl;
  }

  void show_location() {
    cout << "위치(" << location[0] << " , " << location[1] << ")" << endl;
  };

private:
  int location[2];
};

int main() {
  monster* forest_monster = new monster_a();
  delete forest_monster;
  return 0;
}