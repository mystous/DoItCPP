#include <iostream>
#include <list>
#include <random>
#include <cmath>

using namespace std;

const int forest_terrain = 0;
const int cyber_terrain = 1;
const int urban_terrain = 2;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dis(0, 99);

class character {
public:
  character() : hp(100), power(100), location_x(0), location_y(0) {};
  int get_hp() { return hp; }
  int get_power() { return power; }
  int get_location(bool x) { return x ? location_x : location_y; }
  void set_location(int x, int y) { location_x = x; location_y = y; }

protected:
  int hp;
  int power;
  int location_x;
  int location_y;
};

//character 클래스를 상속 받은 player 클래스
class player : public character {
public:
  player() {};
};

//Monster 인터페이스
class monster
{
public:
  // 템플릿 패턴을 위한 순수 가상 함수 구현
  virtual void find_route(player& target_player) = 0;
  virtual bool attach_target(player* target_player) = 0;
  virtual void check_target(player& target_player) = 0;
  virtual void attack_special(player& target_player) = 0;
  virtual void set_location(int x, int y) { monster_body.set_location(x, y); };
  virtual ~monster() {};

protected:
  int calculate_distance(player& target_player);
  character* target_player = nullptr;

private:
  character monster_body;
};

int monster::calculate_distance(player& target_player) {
  return (int)sqrt(pow(target_player.get_location(true) - monster_body.get_location(true), 2) +
    pow(target_player.get_location(false) - monster_body.get_location(false), 2));
}

//Monster factory
class monster_factory
{
public:
  static void create_monster(const int terrain_type, int count);
  static void destroy_monster();
  static monster* get_monster(int index);
  static int get_monster_count();
  static void initialize_monster();

private:
  static monster* create_monster(const int terrain_type);
  static list<monster*> mon_list;
  static int mon_count;
};

list<monster*> monster_factory::mon_list = {};
int monster_factory::mon_count = 0;

//몬스터 A는 추상 클래스 Monster 클래스로부터 상속
class monster_a : public monster {
public:
  // 템플릿 패턴 구현을 위한 순수 가상 함수 오버라이딩
  virtual void find_route(player& target_player) override;
  virtual bool attach_target(player* target_player) override;
  virtual void check_target(player& target_player) override;
  virtual void attack_special(player& target_player) override;
};

// 몬스터 A에 특화된 공격 정의
void monster_a::attack_special(player& target_player) {
  cout << "인텡글 공격 : 데미지 - 15 hp" << endl;
}

void monster_a::find_route(player& target_player) {
  cout << "타겟 찾아 가기 - 최단 거리 우선" << endl;
}

bool monster_a::attach_target(player* target_player) {
  if (calculate_distance(*target_player) < 30) {
    this->target_player = target_player;
    cout << "뒤따라 가면서 플레이어 쫓아 가기" << endl;
    return true;
  }

  return false;
}

void monster_a::check_target(player& target_player) {
  if (target_player.get_hp() < 40) {
    attack_special(target_player);
    return;
  }
}

//몬스터 B는 추상 클래스 Monster 클래스로부터 상속
class monster_b : public monster {
public:
  virtual void find_route(player& target_player) override;
  virtual bool attach_target(player* target_player) override;
  virtual void check_target(player& target_player) override;
  virtual void attack_special(player& target_player) override;
};

// 몬스터 B에 특화된 공격 정의
void monster_b::attack_special(player& target_player) {
  cout << "가상 공격 : 데미지 - 0 hp" << endl;
}

void monster_b::find_route(player& target_player) {
  cout << "타겟 찾아 가기 - 최소 시간 우선" << endl;
}

bool monster_b::attach_target(player* target_player) {
  if (calculate_distance(*target_player) > 30) {
    this->target_player = target_player;
    cout << "위치 추적을 통해서 찾아 가기" << endl;
    return true;
  }

  return false;
}

void monster_b::check_target(player& target_player) {
  if (target_player.get_hp() < 10) {
    attack_special(target_player);
    return;
  }
}


//몬스터 C는 추상 클래스 Monster 클래스로부터 상속
class monster_c : public monster {
public:
  virtual void find_route(player& target_player) override;
  virtual bool attach_target(player* target_player) override;
  virtual void check_target(player& target_player) override;
  virtual void attack_special(player& target_player) override;
};

// 몬스터 C에 특화된 공격 정의
void monster_c::attack_special(player& target_player) {
  cout << "강력 뇌전 공격 : 데미지 - 100 hp" << endl;
}

void monster_c::find_route(player& target_player) {
  cout << "타겟 찾아 가기 - 타겟 시선에 보이지 않도록" << endl;
}

bool monster_c::attach_target(player* target_player) {
  this->target_player = target_player;
  cout << "눈에 띄면 무조건 따라감" << endl;
  return true;
}

void monster_c::check_target(player& target_player) {
  attack_special(target_player);
}

int monster_factory::get_monster_count() {
  return mon_count;
}

monster* monster_factory::get_monster(int index) {
  monster* new_mon = nullptr;
  auto item = mon_list.begin();
  advance(item, index);
  new_mon = *item;

  return new_mon;
}

void monster_factory::initialize_monster() {
  create_monster(forest_terrain, 2);
  create_monster(cyber_terrain, 3);
  create_monster(urban_terrain, 1);
}

monster* monster_factory::create_monster(const int terrain_type) {
  monster* new_mon = nullptr;
  switch (terrain_type) {
  case forest_terrain:
    new_mon = new monster_a();
    break;
  case cyber_terrain:
    new_mon = new monster_b();
    break;
  case urban_terrain:
    new_mon = new monster_c();
    break;
  }

  mon_list.push_back(new_mon);
  mon_count++;
  return new_mon;
}

void monster_factory::destroy_monster() {
  for (auto mon : mon_list) {
    delete mon;
  }
}

void monster_factory::create_monster(const int terrain_type, int count) {
  monster* mon = nullptr;

  for (int i = 0; i < count; ++i) {
    mon = monster_factory::create_monster(terrain_type);
    mon->set_location(dis(gen), dis(gen));
  }
}

// 순수 가상 함수의 조합으로 흐름을 정의 하는 전역 함수
void monster_routine(monster* mon, player target_player) {
  mon->attach_target(&target_player);
  mon->find_route(target_player);
  mon->check_target(target_player);
}

int main() {
  int mon_count, i;
  player target_player_dummy;

  target_player_dummy.set_location(dis(gen), dis(gen));
  monster_factory::initialize_monster();

  mon_count = monster_factory::get_monster_count();
  for (i = 0; i < mon_count; ++i) { 
    cout << endl;
    // 몬스터 종류와 상관 없이 전체 몬스터를 순회 하면서 동일한 흐름을 실행
    cout << endl;
    monster_routine(monster_factory::get_monster(i), target_player_dummy);
  }

  monster_factory::destroy_monster();

  return 0;
}