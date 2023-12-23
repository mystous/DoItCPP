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

//추상 클래스 Monster
class monster {
public:
  monster();             // 생성자
  virtual ~monster();    // 소멸자
  virtual void find_route() = 0;                            // 순수 가상 함수
  virtual void attack_special(player target_player) = 0;    // 순수 가상 함수
};

monster::monster() {
  cout << "Monster 부모 클래스 생성자" << endl;
}

monster::~monster() {
  cout << "Monster 부모 클래스 소멸자" << endl;
}

//몬스터 A는 추상 클래스 Monster 클래스로부터 상속
class monster_a : public monster {
public:
  virtual void attack_special(player target_player) override;
  virtual void find_route() override;   // 순수 가상 함수 오버라이드 선언
};

void monster_a::attack_special(player target_player) {
  cout << "인텡글 공격 : 데미지 - 15 hp" << endl;
}

// 추상 클래스의 순수 가상 함수 구현
void monster_a::find_route() {
  cout << "깊이 우선 탐색(DFS)" << endl;
}

//몬스터 B는 추상 클래스 Monster 클래스로부터 상속
class monster_b : public monster {
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
class monster_c : public monster {
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

// 전역 함수
void monster_routine(monster* mon, player target_player) {
  mon->find_route();
  mon->attack_special(target_player);
}

int main() {
  list<monster*> mon_list;
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