#include "terrain_class.h"

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
