#pragma once
#include <iostream>
#include <cmath>

const int forest_terrain_type = 0;
const int cyber_terrain_type = 1;
const int urban_terrain_type = 2;

const int monster_a_type = 0;
const int monster_b_type = 1;
const int monster_c_type = 2;

class character {
public:
  character() : hp(100), power(100) {};
  int get_hp() { return hp; }
  int get_power() { return power; }

protected:
  int hp;
  int power;
};

