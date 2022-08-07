#pragma once
#include <string>

__interface Icocos2d {
  virtual void set_sprite(void* sprite);
};

__interface IRoute {
  virtual void find_route(int x, int y) = 0;
  virtual void set_location(int x, int y) = 0;
  virtual int get_location(bool x) = 0;
};

__interface IAttack {
  virtual bool attach_target(void* target_player) = 0;
  virtual void check_target(void* target_player) = 0;
  virtual void attack_special(void* target_player) = 0;
};

__interface IWeapon {
  virtual void reload_bullet() = 0;
  virtual bool is_bullet_empty() = 0;
  virtual void shoot_weapon(void* target_plaery) = 0;
};

__interface IRiding_object {
  virtual int check_energy() = 0;
  virtual void set_destination(int x, int y) = 0;
  virtual void run_to_destination() = 0;
  virtual std::string get_object_name() = 0;
};