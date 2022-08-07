#pragma once
#include <iostream>
#include <cmath>
#include "cocos2d.h"

constexpr int forest_terrain_type = 0;
constexpr int cyber_terrain_type = 1;
constexpr int urban_terrain_type = 2;

constexpr int monster_a_type = 0;
constexpr int monster_b_type = 1;
constexpr int monster_c_type = 2;


class sprite_object {
public:
  sprite_object() : cocos_sprite(nullptr) {};
  void set_sprite(cocos2d::Sprite* sprite) { cocos_sprite = sprite; };
protected:
  cocos2d::Sprite* cocos_sprite;
};

class character : public sprite_object {
public:
  character() : hp(100), power(100) {};
  int get_hp() { return hp; };
  int get_power() { return power; };
  void set_location(int x, int y) { location_x = x; location_y = y; cocos_sprite->setPosition(float(x), float(y)); };
  int get_location(bool x) { return x ? location_x : location_y; };
  void increase_power(int increase_number) { power += increase_number; };
  void increase_hp(int increase_number) { hp += increase_number; };

protected:
  int hp;
  int power;
  int location_x;
  int location_y;
};
