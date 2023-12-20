#include <iostream>
#include <list>
#include <random>

#include "interface.h"
#include "monster_class.h"
#include "player_class.h"
#include "terrain_class.h"
#include "weapon.h"
#include "riding_object.h"

using namespace std;

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