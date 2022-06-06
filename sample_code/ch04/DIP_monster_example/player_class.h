#pragma once
#include "interface.h"
#include "base_classes.h"

//character 클래스를 상속 받은 player 클래스
class player : public character, public IRoute {
public:
  virtual void find_route(int x, int y) override;
  virtual void set_location(int x, int y) override;
  virtual int get_location(bool x) override;
  void set_weapon(IWeapon* new_weapon) { weapon = new_weapon; };
  void set_riding_object(IRiding_object* new_riding_object) { riding_object = new_riding_object; };
  void release_weapone() { weapon = nullptr; };
  void release_riding_object() { riding_object = nullptr; };
  void* get_weapon() { return weapon; };
  void* get_riding_object() { return riding_object; };
private:
  int location_x;
  int location_y;
  IWeapon* weapon = nullptr;
  IRiding_object* riding_object = nullptr;
};

class npc_object : public IRoute {
public:
  virtual void find_route(int x, int y) override;
  virtual void set_location(int x, int y) override;
  virtual int get_location(bool x) override;
private:
  int location_x;
  int location_y;
};