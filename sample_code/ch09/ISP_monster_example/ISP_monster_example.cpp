#include <iostream>
#include <list>
#include <random>
#include <cmath>

using namespace std;

const int forest_terrain_type = 0;
const int cyber_terrain_type = 1;
const int urban_terrain_type = 2;

const int monster_a_type = 0;
const int monster_b_type = 1;
const int monster_c_type = 2;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dis(0, 99);
uniform_int_distribution<int> select(0, 2);

class character {
public:
  character() : hp(100), power(100) {};
  int get_hp() { return hp; }
  int get_power() { return power; }

protected:
  int hp;
  int power;
};

// 인터페이스로 사용할 추상 클래스 IRoute
class IRoute {
public:
  virtual void find_route(int x, int y) = 0;
  virtual void set_location(int x, int y) = 0;
  virtual int get_location(bool x) = 0;
};

// 인터페이스로 사용할 추상 클래스 IAttack
class IAttack {
public:
  virtual bool attach_target(character* target_player) = 0;
  virtual void check_target(character& target_player) = 0;
  virtual void attack_special(character& target_player) = 0;
};

//character 클래스와 추상 클래스 IRoute를 상속 받은 player 클래스
class player : public character, public IRoute {
public:
  player() {};
  virtual void find_route(int x, int y) override;
  virtual void set_location(int x, int y) override;
  virtual int get_location(bool x) override;
private:
  int location_x;
  int location_y;
};

void player::find_route(int x, int y) {
}

void player::set_location(int x, int y) {
  location_x = x;
  location_y = y;
}

int player::get_location(bool x) {
  if (x) {
    return location_x;
  }

  return location_y;
}

// IRoute,IAttack 두 추상 클래스를 상속 받아 정의한 몬스터 클래스
class monster : public IRoute, public IAttack {
public:
  int get_monster_type() { return monster_type; };
  virtual void set_location(int x, int y) override { location_x = x; location_y = y; };
  virtual int get_location(bool x) override { return x ? location_x : location_y; };

protected:
  int calculate_distance(int x, int y);
  character* target_player = nullptr;
  int monster_type;
  character monster_body;

private:
  int location_x;
  int location_y;
};

int monster::calculate_distance(int x, int y) {
  return (int)sqrt(pow(x - get_location(true), 2) + pow(y - get_location(false), 2));
}

class terrain {
public:
  virtual void allocate_monster(monster* mon) = 0;
  virtual void bost_monster(monster* mon) = 0;
  void set_start_location(int x, int y) { start_location_x = x; start_location_y = y; };
  void set_end_location(int x, int y) { end_location_x = x; end_location_y = y; };

protected:
  int terrain_type;
  void update_monster_list(monster* mon);

private:
  int start_location_x;
  int start_location_y;
  int end_location_x;
  int end_location_y;
  list<monster*> mon_list;

};

void terrain::update_monster_list(monster* mon) {
  mon_list.push_back(mon);
}

class forest_terrain : public terrain {
public:
  forest_terrain() {
    terrain_type = forest_terrain_type;
  };
  virtual void allocate_monster(monster* mon) override;
  virtual void bost_monster(monster* mon) override;
};

void forest_terrain::allocate_monster(monster* mon) {
  if (monster_a_type == mon->get_monster_type()) {
    update_monster_list(mon);
    cout << "Monster A를 숲에 배치 합니다." << endl;
  }
}

void forest_terrain::bost_monster(monster* mon) {
  if (monster_a_type == mon->get_monster_type()) {
    cout << "몬스터A가 숲에서는 힘이 더 강해 집니다." << endl;
  }
}

class cyber_terrain : public terrain {
public:
  cyber_terrain() {
    terrain_type = cyber_terrain_type;
  };
  virtual void allocate_monster(monster* mon) override;
  virtual void bost_monster(monster* mon) override;
};

void cyber_terrain::allocate_monster(monster* mon) {
  update_monster_list(mon);
  cout << "모든 종류의 Monster를 사이버 공간에 배치 합니다." << endl;
}

void cyber_terrain::bost_monster(monster* mon) {
  cout << "모든 몬스터가 사이버 공간에서는 속도가 빨라 집니다." << endl;
}

class urban_terrain : public terrain {
public:
  urban_terrain() {
    terrain_type = urban_terrain_type;
  };
  virtual void allocate_monster(monster* mon) override;
  virtual void bost_monster(monster* mon) override;
};

void urban_terrain::allocate_monster(monster* mon) {
  if (monster_a_type != mon->get_monster_type()) {
    update_monster_list(mon);
    cout << "Monster B, C를 도심에 배치 합니다." << endl;
  }
}

void urban_terrain::bost_monster(monster* mon) {
  if (monster_c_type == mon->get_monster_type()) {
    update_monster_list(mon);
    cout << "Monster C는 도심에 힘이 강해 집니다." << endl;
  }
}

class npc_object : public IRoute {
public:
  virtual void find_route(int x, int y) override;
  virtual void set_location(int x, int y) override;
  virtual int get_location(bool x) override;
private:
  int location_x;
  int location_y;
};

void npc_object::find_route(int x, int y) {
  cout << "정해진 구역에서만 돌아 다니기." << endl;
}

void npc_object::set_location(int x, int y) {
  location_x = x;
  location_y = y;
}

int npc_object::get_location(bool x) {
  if (x) {
    return location_x;
  }

  return location_y;
}

//Charater factory
class charater_factory
{
public:
  static void create_monster(const int terrain_type, int count);
  static void destroy_monster();
  static void create_terrain();
  static void destroy_terrain();
  static void create_npc();
  static void destory_npc();
  static monster* get_monster(int index);
  static int get_monster_count();
  static void initialize_monster();

private:
  static monster* create_monster(const int terrain_type, terrain* terrain_inst);
  static list<monster*> mon_list;
  static list<npc_object*> npc_list;
  static int mon_count;
  static terrain* terrain_inst[3];
};

list<monster*> charater_factory::mon_list = {};
list<npc_object*> charater_factory::npc_list = {};
int charater_factory::mon_count = 0;
terrain* charater_factory::terrain_inst[] = { nullptr, };

//몬스터 A는 추상 클래스 Monster 클래스로부터 상속
class monster_a : public monster {
public:
  monster_a() {
    monster_type = monster_a_type;
  };
  virtual void find_route(int x, int y) override;
  virtual bool attach_target(character* target_player) override;
  virtual void check_target(character& target_player) override;
  virtual void attack_special(character& target_player) override;
};

void monster_a::attack_special(character& target_player) {
  cout << "인텡글 공격 : 데미지 - 15 hp" << endl;
}

void monster_a::find_route(int x, int y) {
  cout << "타겟 찾아 가기 - 최단 거리 우선" << endl;
}

bool monster_a::attach_target(character* target_player) {
  player* target = (player*)target_player;
  if (calculate_distance(target->get_location(true), target->get_location(false)) < 30) {
    this->target_player = target_player;
    cout << "뒤따라 가면서 플레이어 쫓아 가기" << endl;
    return true;
  }

  return false;
}

void monster_a::check_target(character& target_player) {
  if (target_player.get_hp() < 40) {
    attack_special(target_player);
    return;
  }
}

//몬스터 B는 추상 클래스 Monster 클래스로부터 상속
class monster_b : public monster {
public:
  monster_b() {
    monster_type = monster_b_type;
  };
  virtual void find_route(int x, int y) override;
  virtual bool attach_target(character* target_player) override;
  virtual void check_target(character& target_player) override;
  virtual void attack_special(character& target_player) override;
};

void monster_b::attack_special(character& target_player) {
  cout << "가상 공격 : 데미지 - 0 hp" << endl;
}

void monster_b::find_route(int x, int y) {
  cout << "타겟 찾아 가기 - 최소 시간 우선" << endl;
}

bool monster_b::attach_target(character* target_player) {
  player* target = (player*)target_player;
  if (calculate_distance(target->get_location(true), target->get_location(false)) > 30) {
    this->target_player = target_player;
    cout << "위치 추적을 통해서 찾아 가기" << endl;
    return true;
  }

  return false;
}

void monster_b::check_target(character& target_player) {
  if (target_player.get_hp() < 10) {
    attack_special(target_player);
    return;
  }
}

//몬스터 C는 추상 클래스 Monster 클래스로부터 상속
class monster_c : public monster {
public:
  monster_c() {
    monster_type = monster_c_type;
  };
  virtual void find_route(int x, int y) override;
  virtual bool attach_target(character* target_player) override;
  virtual void check_target(character& target_player) override;
  virtual void attack_special(character& target_player) override;
};

void monster_c::attack_special(character& target_player) {
  cout << "강력 뇌전 공격 : 데미지 - 100 hp" << endl;
}

void monster_c::find_route(int x, int y) {
  cout << "타겟 찾아 가기 - 타겟 시선에 보이지 않도록" << endl;
}

bool monster_c::attach_target(character* target_player) {
  this->target_player = target_player;
  cout << "눈에 띄면 무조건 따라감" << endl;
  return true;
}

void monster_c::check_target(character& target_player) {
  attack_special(target_player);
}

int charater_factory::get_monster_count() {
  return mon_count;
}

monster* charater_factory::get_monster(int index) {
  monster* new_mon = nullptr;
  auto item = mon_list.begin();
  advance(item, index);
  new_mon = *item;

  return new_mon;
}

void charater_factory::initialize_monster() {
  create_monster(forest_terrain_type, 2);
  create_monster(cyber_terrain_type, 3);
  create_monster(urban_terrain_type, 1);
}

void charater_factory::create_terrain() {
  terrain_inst[0] = new forest_terrain();
  terrain_inst[1] = new cyber_terrain();
  terrain_inst[2] = new urban_terrain();

  for (auto object : terrain_inst) {
    object->set_start_location(dis(gen), dis(gen));
    object->set_end_location(dis(gen), dis(gen));
  }
}

void charater_factory::destroy_terrain() {
  for (auto inst : terrain_inst) {
    delete inst;
  }
}

void charater_factory::create_npc() {
  for (int i = 0; i < 10; ++i) {
    npc_object* npc = new npc_object();
    npc_list.push_back(npc);
  }
}
void charater_factory::destory_npc() {
}

monster* charater_factory::create_monster(const int terrain_type, terrain* terrain_inst) {
  monster* new_mon = nullptr;
  switch (terrain_type) {
  case forest_terrain_type:
    new_mon = new monster_a();
    break;
  case cyber_terrain_type:
    new_mon = new monster_b();
    break;
  case urban_terrain_type:
    new_mon = new monster_c();
    break;
  }

  terrain_inst->allocate_monster(new_mon);
  terrain_inst->bost_monster(new_mon);
  mon_list.push_back(new_mon);
  mon_count++;
  return new_mon;
}

void charater_factory::destroy_monster() {
  for (auto mon : mon_list) {
    delete mon;
  }
}

void monster_routine(monster* mon, player target_player) {
  mon->attach_target(&target_player);
  mon->find_route(target_player.get_location(true), target_player.get_location(false));
  mon->check_target(target_player);
}

void charater_factory::create_monster(const int terrain_type, int count) {
  monster* mon = nullptr;

  for (int i = 0; i < count; ++i) {
    mon = charater_factory::create_monster(terrain_type, terrain_inst[select(gen)]);
    mon->set_location(dis(gen), dis(gen));
  }
}

int main() {
  int mon_count, i;
  player target_player_dummy;

  target_player_dummy.set_location(dis(gen), dis(gen));
  charater_factory::create_terrain();
  charater_factory::initialize_monster();

  mon_count = charater_factory::get_monster_count();
  for (i = 0; i < mon_count; ++i) {
    cout << endl;
    monster_routine(charater_factory::get_monster(i), target_player_dummy);
  }

  charater_factory::destroy_monster();
  charater_factory::destroy_terrain();

  return 0;
}