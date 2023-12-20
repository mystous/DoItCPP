#include <iostream>
#include <list>
using namespace std;

class character {
public:
  character() : hp(100), power(100)
  {};
  void get_damage(int _damage) {};

protected:
  int hp;
  int power;
};

//Player 클래스
class player : public character {
public:
  player() {};
};

//기본 Monster 클래스
class monster {
public:
  monster() {};
  void attack(player target_player) {};
  virtual void attack_special(player target_player);
  virtual void attack_at_dawn() = 0;
};

void monster::attack_special(player target_player) {
  cout << "기본 공격 : 데미지 - 10 hp" << endl;
}

//몬스터 A는 기본 Monster 클래스로부터 상속
class monster_a : public monster, character {
public:
  //상속받은 함수 오버라이딩 
  virtual void attack_special(player target_player) override;
};

void monster_a::attack_special(player target_player) {
  cout << "인텡글 공격 : 데미지 - 15 hp" << endl;
}

//몬스터 B는 기본 Monster 클래스로부터 상속
class monster_b : public monster, character {
public:
  //상속받은 함수 오버라이딩
  virtual void attack_special(player target_player) override;
};

void monster_b::attack_special(player target_player) {
  cout << "가상 공격 : 데미지 - 0 hp" << endl;
}

//몬스터 C는 기본 Monster 클래스로부터 상속
class monster_c : public monster, character {
public:
  //상속받은 함수 오버라이딩
  virtual void attack_special(player target_player) override;
};

void monster_c::attack_special(player target_player) {
  cout << "강력 뇌전 공격 : 데미지 - 100 hp" << endl;
}

int main() {
  list<monster*> mon_list;

  monster_a first_monster;
  mon_list.push_back(&first_monster);

  monster_b second_monster;
  mon_list.push_back(&second_monster);

  monster_c third_monster;
  mon_list.push_back(&third_monster);

  for (auto item : mon_list) {
    item->attack_at_dawn();
  }

  return 0;
}