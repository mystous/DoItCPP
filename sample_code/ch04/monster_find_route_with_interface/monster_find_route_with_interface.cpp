#include <iostream>
#include <list>
using namespace std;

class character {
public:
  character() : hp(100), power(100) {};

protected:
  int hp;
  int power;
};

//character 클래스를 상속 받은 player 클래스
class player : public character {
public:
  player() {};
};

//Monster 인터페이스
__interface Imonster
{
public:
  virtual void find_route() = 0;
  virtual void attack_special(player target_player) = 0;
};

//몬스터 A는 추상 클래스 Monster 클래스로부터 상속
class monster_a : public Imonster {
public:
  virtual void attack_special(player target_player) override;
  virtual void find_route() override;
};

void monster_a::attack_special(player target_player) {
  cout << "인텡글 공격 : 데미지 - 15 hp" << endl;
}

void monster_a::find_route() {
  cout << "깊이 우선 탐색(DFS)" << endl;
}

//몬스터 B는 추상 클래스 Monster 클래스로부터 상속
class monster_b : public Imonster {
public:
  virtual void attack_special(player target_player) override;
  virtual void find_route() override;
};

void monster_b::attack_special(player target_player) {
  cout << "가상 공격 : 데미지 - 0 hp" << endl;
}


void monster_b::find_route() {
  cout << "너비 우선 탐색(BFS)" << endl;
}


//몬스터 C는 추상 클래스 Monster 클래스로부터 상속
class monster_c : public Imonster {
public:
  virtual void attack_special(player target_player) override;
  virtual void find_route() override;
};

void monster_c::attack_special(player target_player) {
  cout << "강력 뇌전 공격 : 데미지 - 100 hp" << endl;
}


void monster_c::find_route() {
  cout << "다익스트라 최단 경로 알고리즘" << endl;
}

void monster_routine(Imonster* mon, player target_player) {
  mon->find_route();
  mon->attack_special(target_player);
}

int main() {
  list<Imonster*> mon_list;
  monster_a first_mon;
  monster_b second_mon;
  monster_c third_mon;
  player target_player;

  mon_list.push_back(&first_mon);
  mon_list.push_back(&second_mon);
  mon_list.push_back(&third_mon);

  for (auto mon : mon_list) {
    monster_routine(mon, target_player);
  }

  return 0;
}