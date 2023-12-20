#include <iostream>
using namespace std;

//기본 Monster 클래스
class monster {
public:
  monster();
  //~monster();
  virtual ~monster();
private:
  int* dummy;
};

monster::monster() {
  cout << "monster() 생성자 호출" << endl;
  dummy = new int;
}

monster::~monster() {
  cout << "~monster() 소멸자 호출" << endl;
  delete dummy;
}

//몬스터 A는 기본 Monster 클래스로부터 상속
class monster_a : public monster {
public:
  monster_a();
  //~monster_a();
  virtual ~monster_a();
private:
  int* dummy_a;
};

monster_a::monster_a() {
  cout << "monster_a() 생성자 호출" << endl;
  dummy_a = new int;
}

monster_a::~monster_a() {
  cout << "~monster_a() 소멸자 호출" << endl;
  delete dummy_a;
}

int main() {
  // 자식 클래스 형으로 생성
  //monster_a* mon = new monster_a();

  // 부모 클래스로 업스케일 하여 생성
  monster* mon = new monster_a();

  delete mon;
  return 0;
}