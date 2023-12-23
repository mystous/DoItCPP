#pragma once

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

class IWeapon {
public:
  virtual void reload_bullet() = 0;
  virtual bool is_bullet_empty() = 0;
  virtual void shoot_weapon(void* target_plaery) = 0;
};

class IRiding_object {
public:
  virtual int check_energy() = 0;
  virtual void set_destination(int x, int y) = 0;
  virtual void run_to_destination() = 0;
};