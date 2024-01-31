#include <iostream>

using namespace std;

class monster_a {
public:
  // 컴파일러 또는 언어가 제공하는 기본 생성자 사용
  monster_a() = default;
  monster_a(int init_hp, int init_power)
    : hp(init_hp), power(init_power) {};
  int hp, power;
};

class monster_b {
public:
  // 아무 연산을 하지 않는 기본 생성자 정의
  monster_b() {};
  monster_b(int init_hp, int init_power)
    : hp(init_hp), power(init_power) {};
  int hp, power;
};

class monster_c {
public:
  // 매개변수 없는 기본 생성자 정의 하지 않음
  monster_c(int init_hp, int init_power)
    : hp(init_hp), power(init_power) {};
  int hp, power;
};

int main() {

  // 기본 생성자 사용하여 객체 생성
  monster_a mon_a{};

  // 아무 연산을 하지 않는 기본 생성자를 사용하여 객체 생성
  monster_b mon_b{};

  // 몬스터 C는 매개변수가 없는 기본 생성자가 없어
  // 아래 코드 처럼 객체가 생성이 안됩니다.
  //monster_c mon_c{};

  cout << "몬스터 A(" << mon_a.hp << ", " << mon_a.power << ")" << endl;
  cout << "몬스터 B(" << mon_b.hp << ", " << mon_b.power << ")" << endl;
}
