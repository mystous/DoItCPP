#pragma once

__interface IRoute {
  virtual void find_route(int x, int y);
  virtual void set_location(int x, int y);
  virtual int get_location(bool x);
};

__interface IAttack {
  virtual bool attach_target(void* target_player);
  virtual void check_target(void* target_player);
  virtual void attack_special(void* target_player);
};

__interface IWeapon {
  virtual void reload_bullet();
  virtual bool is_bullet_empty();
  virtual void shoot_weapon(void* target_plaery);
};

__interface IRiding_object {
  virtual int check_energy();
  virtual void set_destination(int x, int y);
  virtual void run_to_destination();
};