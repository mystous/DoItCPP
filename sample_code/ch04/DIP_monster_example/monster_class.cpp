#include "monster_class.h"
#include "base_classes.h"
#include "terrain_class.h"

int monster::calculate_distance(int x, int y) {
  return (int)sqrt(pow(x - get_location(true), 2) + pow(y - get_location(false), 2));
}

void monster_a::attack_special(void* target_player) {
  cout << "인텡글 공격 : 데미지 - 15 hp" << endl;
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
}

void monster_b::find_route(int x, int y) {
  cout << "타겟 찾아 가기 - 최소 시간 우선" << endl;
}

bool monster_b::attach_target(void* target_player) {
  player* target = (player*)target_player;
  if (calculate_distance(target->get_location(true), target->get_location(false)) > 30) {
    this->target_player = target_player;
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
}

void monster_c::find_route(int x, int y) {
  cout << "타겟 찾아 가기 - 타겟 시선에 보이지 않도록" << endl;
}

bool monster_c::attach_target(void* target_player) {
  this->target_player = target_player;
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

extern class character;
extern class character_factory;


