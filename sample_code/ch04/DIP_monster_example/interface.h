#pragma once

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