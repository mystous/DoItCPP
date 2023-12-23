#include <iostream>
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
  virtual void attack_special(player target_player);
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

int main() {
  player player_1;

  monster mother_monster;
  monster_a forest_monster;

  mother_monster.attack_special(player_1);

  monster* mon = &forest_monster;
  cout << endl << "부모 클래스로 업케스팅 후 공격" << endl;
  mon->attack_special(player_1);

  mon = &mother_monster;
  cout << endl << "부모 클래스로 공격" << endl;
  mon->attack_special(player_1);

  return 0;
}