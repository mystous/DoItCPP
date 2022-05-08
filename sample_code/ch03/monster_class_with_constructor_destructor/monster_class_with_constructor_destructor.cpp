#include <iostream>
#include <random>
using namespace std;

class character {
public:
  character(){
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
//class monster_a : public monster, character {
class monster_a : public monster {
public:
  //monster_a() {
   monster_a() : monster_a(10, 10) {
    //cout << this << " monster_a 클래스 생성자" << endl;
    cout << "monster_a 클래스 생성자" << endl;
    //monster_a(10, 10);
  };

  monster_a(int x, int y) : location{x, y} {
    //cout << this << " monster_a 클래스 생성자 (인자 추가)" << endl;
    cout << "monster_a 클래스 생성자 (인자 추가)" << endl;
  };
  virtual ~monster_a() {
  //~monster_a() {
    //cout << this << " monster_a 클래스 소멸자" << endl;
    cout << "monster_a 클래스 소멸자" << endl;
  }

  void show_location() {
    //cout << this << " 위치(" << location[0] << " , " << location[1] << ")" << endl;
    cout << "위치(" << location[0] << " , " << location[1] << ")" << endl;
  };

private:
  int location[2];
};

int main() {
  //character player;

  //monster_a forest_monster;
  //forest_monster.show_location();

  //monster_a wood_monster(10, 25);
  //wood_monster.show_location();

  monster *forest_monster = new monster_a();
  delete forest_monster;
  return 0;
}