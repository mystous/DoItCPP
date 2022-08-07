#pragma once

#include "interface.h"
#include "base_classes.h"
#include "player_class.h"
#include <list>
#include "cocos2d.h"
#include "const_int.h"
#include "monster_class.h"
#include "riding_object.h"

using namespace std;

//Game Logic factory
class game_logic_factory
{
public:
  static void create_monster(const int monster_type, int count, cocos2d::Scene* scene, cocos2d::Size visibleSize);
  static void destroy_monster();
  static void create_terrain(cocos2d::Scene* scene, cocos2d::Vec2 origin, cocos2d::Size visibleSize);
  static void destroy_terrain();
  static void create_player(cocos2d::Scene* scene, cocos2d::Vec2 origin, cocos2d::Size visibleSize, map<riding_menu_id, string>& riding_menu_map);
  static void destory_player();
  static monster* get_monster(int index);
  static int get_monster_count();
  static void initialize_monster(cocos2d::Scene* scene, cocos2d::Size visibleSize);

private:
  static monster* create_monster(const int monster_type, void* terrain_inst);
  static void* get_terrain_by_location(int x, int y);
  static void create_riding_object(cocos2d::Scene* scene, cocos2d::Vec2 origin, cocos2d::Size visibleSize, cocos2d::Sprite* parent, map<riding_menu_id, string>& riding_menu_map);
  static void destroy_riding_object();

  static list<monster*> mon_list;
  static player* user_player;
  static int mon_count;
  static void* terrain_inst[3];
  static void* riding_inst[3];
};
