#include <iostream>
using namespace std;

//기본 Monster 클래스
class monster {
public:
  monster();   // 생성자
  ~monster();  // 소멸자
private:
  int* dummy;
};

monster::monster() {
  cout << "monster() 생성자 호출" << endl;
  dummy = new int;
}

monster::~monster() {
  cout << "~monster() 소멸자 호출" << endl;
  delete dummy;   // 메모리 삭제
}

//몬스터 A는 기본 Monster 클래스로부터 상속
class monster_a : public monster {
public:
  monster_a();
  ~monster_a();
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
  monster* mon = new monster_a();    // 부모 클래스로 업캐스팅
  delete mon;
  return 0;
}