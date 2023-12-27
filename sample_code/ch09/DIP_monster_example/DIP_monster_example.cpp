#include <iostream>
#include <list>
#include <random>

using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dis(0, 99);
uniform_int_distribution<int> select(0, 2);

const int forest_terrain_type = 0;
const int cyber_terrain_type = 1;
const int urban_terrain_type = 2;

const int monster_a_type = 0;
const int monster_b_type = 1;
const int monster_c_type = 2;

/************* 추상 클래스 선언 영역 *************/
class IRoute {
public:
  virtual void find_route(int x, int y) = 0;
  virtual void set_location(int x, int y) = 0;
  virtual int get_location(bool x) = 0;
};

class IAttack {
public:
  virtual bool attach_target(void* target_player) = 0;
  virtual void check_target(void* target_player) = 0;
  virtual void attack_special(void* target_player) = 0;
};

// 인터페이스로 사용할 추상 클래스 IWeapon
class IWeapon {
public:
  virtual void reload_bullet() = 0;
  virtual bool is_bullet_empty() = 0;
  virtual void shoot_weapon(void* target_plaery) = 0;
};

// 인터페이스로 사용할 추상 클래스 IRiding_object
class IRiding_object {
public:
  virtual int check_energy() = 0;
  virtual void set_destination(int x, int y) = 0;
  virtual void run_to_destination() = 0;
};

/************* 클래스 선언 영역 *************/
class character {
public:
  character() : hp(100), power(100) {};
  int get_hp() { return hp; }
  int get_power() { return power; }

protected:
  int hp;
  int power;
};

//Monster 인터페이스
class monster : public IRoute, public IAttack {
public:
  int get_monster_type() { return monster_type; };
  virtual void set_location(int x, int y) override { location_x = x; location_y = y; };
  virtual int get_location(bool x) override { return x ? location_x : location_y; };

protected:
  int calculate_distance(int x, int y);
  void depence_strike_back(void* target_player);
  character* target_player = nullptr;
  int monster_type;
  character monster_body;

private:
  int location_x;
  int location_y;
};

//몬스터 A는 추상 클래스 Monster 클래스로부터 상속
class monster_a : public monster {
public:
  monster_a() {
    monster_type = monster_a_type;
  };
  virtual void find_route(int x, int y) override;
  virtual bool attach_target(void* target_player) override;
  virtual void check_target(void* target_player) override;
  virtual void attack_special(void* target_player) override;
};

//몬스터 B는 추상 클래스 Monster 클래스로부터 상속
class monster_b : public monster {
public:
  monster_b() {
    monster_type = monster_b_type;
  };
  virtual void find_route(int x, int y) override;
  virtual bool attach_target(void* target_player) override;
  virtual void check_target(void* target_player) override;
  virtual void attack_special(void* target_player) override;
};

//몬스터 C는 추상 클래스 Monster 클래스로부터 상속
class monster_c : public monster {
public:
  monster_c() {
    monster_type = monster_c_type;
  };
  virtual void find_route(int x, int y) override;
  virtual bool attach_target(void* target_player) override;
  virtual void check_target(void* target_player) override;
  virtual void attack_special(void* target_player) override;
};

class npc_object : public IRoute {
public:
  virtual void find_route(int x, int y) override;
  virtual void set_location(int x, int y) override;
  virtual int get_location(bool x) override;
private:
  int location_x;
  int location_y;
};

//Character factory
class character_factory
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
  static monster* create_monster(const int terrain_type, void* terrain_inst);
  static list<monster*> mon_list;
  static list<npc_object*> npc_list;
  static int mon_count;
  static void* terrain_inst[3];
};

//character 클래스를 상속 받은 player 클래스
class player : public character, public IRoute {
public:
  virtual void find_route(int x, int y) override;
  virtual void set_location(int x, int y) override;
  virtual int get_location(bool x) override;
  void set_weapon(IWeapon* new_weapon) { weapon = new_weapon; };
  void set_riding_object(IRiding_object* new_riding_object) { riding_object = new_riding_object; };
  void release_weapone() { weapon = nullptr; };
  void release_riding_object() { riding_object = nullptr; };
  void* get_weapon() { return weapon; };
  void* get_riding_object() { return riding_object; };
private:
  int location_x;
  int location_y;
  // 어그리게이션을 클래스를 통해 의존하지 않고 
  // 추상 클래스(인터페이스)를 통해 의존함
  IWeapon* weapon = nullptr;
  IRiding_object* riding_object = nullptr;
};

class car : public IRiding_object {
public:
  virtual int check_energy() override;
  virtual void set_destination(int x, int y) override;
  virtual void run_to_destination() override;
};

class horse : public IRiding_object {
public:
  virtual int check_energy() override;
  virtual void set_destination(int x, int y) override;
  virtual void run_to_destination() override;
};

class motor_cycle : public IRiding_object {
public:
  virtual int check_energy() override;
  virtual void set_destination(int x, int y) override;
  virtual void run_to_destination() override;
};

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

class forest_terrain : public terrain {
public:
  forest_terrain() {
    terrain_type = forest_terrain_type;
  };
  virtual void allocate_monster(monster* mon) override;
  virtual void bost_monster(monster* mon) override;
};

class cyber_terrain : public terrain {
public:
  cyber_terrain() {
    terrain_type = cyber_terrain_type;
  };
  virtual void allocate_monster(monster* mon) override;
  virtual void bost_monster(monster* mon) override;
};

class urban_terrain : public terrain {
public:
  urban_terrain() {
    terrain_type = urban_terrain_type;
  };
  virtual void allocate_monster(monster* mon) override;
  virtual void bost_monster(monster* mon) override;
};

class gun : public IWeapon {
public:
  virtual void reload_bullet() override;
  virtual bool is_bullet_empty() override;
  virtual void shoot_weapon(void* target_plaery)  override;
};

class machine_gun : public IWeapon {
public:
  virtual void reload_bullet() override;
  virtual bool is_bullet_empty() override;
  virtual void shoot_weapon(void* target_plaery)  override;
};

class arrow : public IWeapon {
public:
  virtual void reload_bullet() override;
  virtual bool is_bullet_empty() override;
  virtual void shoot_weapon(void* target_plaery) override;
};

/************* 정적 멤버 변수 초기화 *************/
list<monster*> character_factory::mon_list = {};
list<npc_object*> character_factory::npc_list = {};
int character_factory::mon_count = 0;
void* character_factory::terrain_inst[] = { nullptr, };

/************* 클래스 멤버 함수 정의 영역 *************/
int monster::calculate_distance(int x, int y) {
  return (int)sqrt(pow(x - get_location(true), 2) + pow(y - get_location(false), 2));
}

// 반격을 막아내는 함수, 무기와 탈 것은 모두 인터페이스(추상 클래스)로 처리 합니다.
// 인터페이스를 상속한 클래스가 무엇이던 이 함수는 변경되지 않습니다.
void monster::depence_strike_back(void* target_player) {
  player* target_player_inst = (player*)target_player;
  IWeapon* weapon = (IWeapon*)target_player_inst->get_weapon();
  IRiding_object* riding_object = (IRiding_object*)target_player_inst->get_riding_object();
  if (nullptr == weapon) {
    return;
  }

  if (weapon->is_bullet_empty()) {
    weapon->reload_bullet();
  }
  weapon->shoot_weapon(this);

  if (riding_object->check_energy() > 10) {
    riding_object->set_destination(get_location(true) + 30, get_location(false) + 30);
    riding_object->run_to_destination();
  }
}

void monster_a::attack_special(void* target_player) {
  cout << "인텡글 공격 : 데미지 - 15 hp" << endl;
  depence_strike_back(target_player);
}

void monster_a::find_route(int x, int y) {
  cout << "타겟 찾아 가기 - 최단 거리 우선" << endl;
}

bool monster_a::attach_target(void* target_player) {
  player* target = (player*)target_player;
  if (calculate_distance(target->get_location(true), target->get_location(false)) < 30) {
    this->target_player = (character*)target_player;
    cout << "뒤따라 가면서 플레이어 쫓아 가기" << endl;
    return true;
  }

  return false;
}

void monster_a::check_target(void* target_player) {
  player* target = (player*)target_player;
  if (target->get_hp() < 40) {
    attack_special(target_player);
    return;
  }
}

void monster_b::attack_special(void* target_player) {
  cout << "가상 공격 : 데미지 - 0 hp" << endl;
  depence_strike_back(target_player);
}

void monster_b::find_route(int x, int y) {
  cout << "타겟 찾아 가기 - 최소 시간 우선" << endl;
}

bool monster_b::attach_target(void* target_player) {
  player* target = (player*)target_player;
  if (calculate_distance(target->get_location(true), target->get_location(false)) > 30) {
    this->target_player = (character*)target_player;
    cout << "위치 추적을 통해서 찾아 가기" << endl;
    return true;
  }

  return false;
}

void monster_b::check_target(void* target_player) {
  player* target = (player*)target_player;
  if (target->get_hp() < 10) {
    attack_special(target_player);
    return;
  }
}

void monster_c::attack_special(void* target_player) {
  cout << "강력 뇌전 공격 : 데미지 - 100 hp" << endl;
  depence_strike_back(target_player);
}

void monster_c::find_route(int x, int y) {
  cout << "타겟 찾아 가기 - 타겟 시선에 보이지 않도록" << endl;
}

bool monster_c::attach_target(void* target_player) {
  this->target_player = (character*)target_player;
  cout << "눈에 띄면 무조건 따라감" << endl;
  return true;
}

void monster_c::check_target(void* target_player) {
  attack_special(target_player);
}


int character_factory::get_monster_count() {
  return mon_count;
}

monster* character_factory::get_monster(int index) {
  monster* new_mon = nullptr;
  auto item = mon_list.begin();
  advance(item, index);
  new_mon = *item;

  return new_mon;
}

void character_factory::initialize_monster() {
  create_monster(forest_terrain_type, 2);
  create_monster(cyber_terrain_type, 3);
  create_monster(urban_terrain_type, 1);
}

void character_factory::create_terrain() {
  terrain_inst[0] = new forest_terrain();
  terrain_inst[1] = new cyber_terrain();
  terrain_inst[2] = new urban_terrain();

  for (auto object : terrain_inst) {
    terrain* terrain_object = (terrain*)object;
    terrain_object->set_start_location(dis(gen), dis(gen));
    terrain_object->set_end_location(dis(gen), dis(gen));
  }
}

void character_factory::destroy_terrain() {
  for (auto inst : terrain_inst) {
    delete inst;
  }
}

void character_factory::create_npc() {
  nullptr;

  for (int i = 0; i < 10; ++i) {
    npc_object* npc = new npc_object();
    npc_list.push_back(npc);
  }
}
void character_factory::destory_npc() {
}

monster* character_factory::create_monster(const int terrain_type, void* terrain_inst) {
  monster* new_mon = nullptr;
  terrain* terrain_object = (terrain*)terrain_inst;
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

  terrain_object->allocate_monster(new_mon);
  terrain_object->bost_monster(new_mon);
  mon_list.push_back(new_mon);
  mon_count++;
  return new_mon;
}

void character_factory::destroy_monster() {
  for (auto mon : mon_list) {
    delete mon;
  }
}

void character_factory::create_monster(const int terrain_type, int count) {
  monster* mon = nullptr;

  for (int i = 0; i < count; ++i) {
    mon = character_factory::create_monster(terrain_type, terrain_inst[select(gen)]);
    mon->set_location(dis(gen), dis(gen));
  }
}

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

int car::check_energy() {
  cout << "연료 체크" << endl;
  return 30;
}

void car::set_destination(int x, int y) {
}

void car::run_to_destination() {
  cout << "부르르르릉" << endl;
}

int horse::check_energy() {
  cout << "체력 체크" << endl;
  return 30;
}

void horse::set_destination(int x, int y) {
}

void horse::run_to_destination() {
  cout << "다그닥 다그닥" << endl;
}

int motor_cycle::check_energy() {
  cout << "연료 체크" << endl;
  return 30;
}

void motor_cycle::set_destination(int x, int y) {
}

void motor_cycle::run_to_destination() {
  cout << "부다다다다" << endl;
}

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

void cyber_terrain::allocate_monster(monster* mon) {
  update_monster_list(mon);
  cout << "모든 종류의 Monster를 사이버 공간에 배치 합니다." << endl;
}

void cyber_terrain::bost_monster(monster* mon) {
  cout << "모든 몬스터가 사이버 공간에서는 속도가 빨라 집니다." << endl;
}

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

void terrain::update_monster_list(monster* mon) {
  mon_list.push_back(mon);
}

void gun::reload_bullet() {
  cout << "탄창 교체" << endl;
}

bool gun::is_bullet_empty() {
  cout << "탄창에 남은 총알이 있는가?" << endl;
  return true; // 예제에서는 임의로 비었다고 가정함
}

void gun::shoot_weapon(void* target_plaery) {
  cout << "\"탕\"" << endl;
}

void machine_gun::reload_bullet() {
  cout << "대형 탄창 교체" << endl;
}

bool machine_gun::is_bullet_empty() {
  cout << "탄창에 남은 총알이 있는가?" << endl;
  return true; // 예제에서는 임의로 비었다고 가정함
}

void machine_gun::shoot_weapon(void* target_plaery) {
  cout << "\"두두두두두두\"" << endl;
}

void arrow::reload_bullet() {
  cout << "화살통 채우기" << endl;
}

bool arrow::is_bullet_empty() {
  cout << "화살통이 비였는가?" << endl;
  return true; // 예제에서는 임의로 비었다고 가정함
}

void arrow::shoot_weapon(void* target_plaery) {
  cout << "피이이잉" << endl;
}

/************* 전역 함수 영역 *************/
void monster_routine(monster* mon, player target_player) {
  mon->attach_target(&target_player);
  mon->find_route(target_player.get_location(true), target_player.get_location(false));
  mon->check_target(&target_player);
}

int main() {
  int mon_count, i;
  player target_player;
  car riding_car;
  machine_gun m_gun;

  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dis(0, 99);

  target_player.set_riding_object(&riding_car);
  target_player.set_weapon(&m_gun);
  target_player.set_location(dis(gen), dis(gen));

  character_factory::create_terrain();
  character_factory::initialize_monster();

  mon_count = character_factory::get_monster_count();
  for (i = 0; i < mon_count; ++i) {
    cout << endl;
    monster_routine(character_factory::get_monster(i), target_player);
  }

  character_factory::destroy_monster();
  character_factory::destroy_terrain();

  return 0;
}