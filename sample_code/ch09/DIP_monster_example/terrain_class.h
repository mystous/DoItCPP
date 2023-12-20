#pragma once
#include <iostream>
#include <list>
#include "monster_class.h"

using namespace std;

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
