#include "game_logic_factory.h"
#include "monster_class.h"
#include "base_classes.h"
#include "terrain_class.h"
#include "const_string.h"
#include "const_int.h"
#include <random>

using namespace std;
USING_NS_CC;

random_device rd;
mt19937 gen(rd());

list<monster*> game_logic_factory::mon_list = {};
int game_logic_factory::mon_count = 0;
void* game_logic_factory::terrain_inst[] = { nullptr, };
void* game_logic_factory::riding_inst[] = { nullptr, };
player* game_logic_factory::user_player = nullptr;

int game_logic_factory::get_monster_count() {
  return mon_count;
}

monster* game_logic_factory::get_monster(int index) {
  monster* new_mon = nullptr;
  auto item = mon_list.begin();
  advance(item, index);
  new_mon = *item;

  return new_mon;
}

void game_logic_factory::initialize_monster(cocos2d::Scene* scene, cocos2d::Size visibleSize) {
  create_monster(forest_terrain_type, 1, scene, visibleSize);
  create_monster(urban_terrain_type, 1, scene, visibleSize);
  create_monster(cyber_terrain_type, 1, scene, visibleSize);
}

void game_logic_factory::create_terrain(cocos2d::Scene* scene, cocos2d::Vec2 origin, cocos2d::Size visibleSize) {
  int terrain_width = visibleSize.width / 2;
  int terrain_height = visibleSize.height / 2;
  terrain* terrain_object = nullptr;

  terrain_inst[0] = new forest_terrain();
  terrain_inst[1] = new urban_terrain();
  terrain_inst[2] = new cyber_terrain();

  terrain_object = (terrain*)terrain_inst[0];
  terrain_object->set_start_location(0, terrain_height);
  terrain_object->set_end_location(terrain_width, 2 * terrain_height);

  terrain_object = (terrain*)terrain_inst[1];
  terrain_object->set_start_location(terrain_width, terrain_height);
  terrain_object->set_end_location(2 * terrain_width, 2 * terrain_height);

  terrain_object = (terrain*)terrain_inst[2];
  terrain_object->set_start_location(terrain_width, 0);
  terrain_object->set_end_location(2 * terrain_width, terrain_height);

  auto bg = Sprite::create(bg_img_string + png_extention_string);
  bg->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
  scene->addChild(bg);
}

void game_logic_factory::destroy_terrain() {
  for (auto inst : terrain_inst) {
    delete inst;
  }
}

void game_logic_factory::create_riding_object(cocos2d::Scene* scene, cocos2d::Vec2 origin, cocos2d::Size visibleSize, cocos2d::Sprite* parent, map<riding_menu_id, string>& riding_menu_map) {
  for (auto menu_item : riding_menu_map) {
    if (riding_menu_id::riding_unselect == menu_item.first) {
      continue;
    }
    auto riding_sprite = Sprite::create(menu_item.second + png_extention_string);
    riding_sprite->setPosition(parent->getContentSize().width / 2, 0);
    parent->addChild(riding_sprite, 0, (int)menu_item.first);
    riding_sprite->setVisible(false);

    void* new_object;
    switch (menu_item.first) {
    case riding_menu_id::riding_obj_car:
      new_object = new car();
      break;
    case riding_menu_id::riding_obj_horse:
      new_object = new horse();
      break;
    case riding_menu_id::riding_obj_motor_cycle:
      new_object = new motor_cycle();
      break;
    }

    ((sprite_object*)new_object)->set_sprite(riding_sprite);
    riding_inst[(int)menu_item.first - 1] = new_object;
  }
}

void game_logic_factory::destroy_riding_object() {
  car* car_object = (car*)riding_inst[(int)riding_menu_id::riding_obj_car - 1];
  horse* horse_object = (horse*)riding_inst[(int)riding_menu_id::riding_obj_horse - 1];
  motor_cycle* motor_cycle_object = (motor_cycle*)riding_inst[(int)riding_menu_id::riding_obj_motor_cycle - 1];

  delete car_object;
  delete horse_object;
  delete motor_cycle_object;
}

void game_logic_factory::create_player(cocos2d::Scene* scene, cocos2d::Vec2 origin, cocos2d::Size visibleSize, map<riding_menu_id, string>& riding_menu_map) {
  user_player = new player();

  auto player = Sprite::create(player_string + png_extention_string);
  if (nullptr != player) {
    uniform_int_distribution<int> x_dis(150, visibleSize.width - 150);
    uniform_int_distribution<int> y_dis(150, visibleSize.height - 150);

    user_player->set_sprite(player);
    user_player->set_location(x_dis(gen), y_dis(gen));
    scene->addChild(player, 0, player_string);
    create_riding_object(scene, origin, visibleSize, player, riding_menu_map);
  }
}

void game_logic_factory::destory_player() {
  destroy_riding_object();
  delete user_player;
}

monster* game_logic_factory::create_monster(const int monster_type, void* terrain_object) {
  monster* new_mon = nullptr;
  terrain* converted_terrain = (terrain*)terrain_object;
  switch (monster_type) {
  case monster_a_type:
    new_mon = new monster_a();
    break;
  case monster_b_type:
    new_mon = new monster_b();
    break;
  case monster_c_type:
    new_mon = new monster_c();
    break;
  }

  mon_list.push_back(new_mon);
  mon_count++;

  if (nullptr == converted_terrain) {
    return new_mon;
  }

  if (converted_terrain->allocate_monster(new_mon)) {
    converted_terrain->bost_monster(new_mon);
    return new_mon;
  }

  mon_list.pop_back();
  mon_count--;
  delete new_mon;
  return nullptr;
}

void game_logic_factory::destroy_monster() {
  for (auto mon : mon_list) {
    delete mon;
  }
}

void* game_logic_factory::get_terrain_by_location(int x, int y) {
  for (auto object : terrain_inst) {
    terrain* terrain_object = (terrain*)object;
    if (terrain_object->check_terrain_area(x, y)) {
      return object;
    }
  }

  return nullptr;
}

void game_logic_factory::create_monster(const int monster_type, int count, cocos2d::Scene* scene, cocos2d::Size visibleSize) {
  monster* mon = nullptr;
  uniform_int_distribution<int> x_dis(150, visibleSize.width - 150);
  uniform_int_distribution<int> y_dis(150, visibleSize.height - 150);

  array<string, 3> monster{ monster_01_string, monster_02_string, monster_03_string };
  auto sprite = Sprite::create(monster[monster_type] + png_extention_string);
  if (nullptr != sprite) {
    Vec2 position = Vec2(x_dis(gen), y_dis(gen));
    mon = game_logic_factory::create_monster(monster_type, get_terrain_by_location(position.x, position.y));

    if (nullptr == mon) {
      return;
    }
    mon->set_sprite(sprite);
    mon->set_location(position.x, position.y);
    scene->addChild(sprite, 0, monster[monster_type]);
  }
}