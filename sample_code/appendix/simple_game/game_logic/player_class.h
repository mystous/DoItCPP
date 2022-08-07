#pragma once
#include "interface.h"
#include "base_classes.h"

//character 클래스를 상속 받은 player 클래스
class player : public character, public IRoute, public Icocos2d {
public:
  virtual void find_route(int x, int y) override;
  virtual void set_location(int x, int y) override { player_body.set_location(x, y); };
  virtual int get_location(bool x) override { return player_body.get_location(x); };
  virtual void set_sprite(void* sprite) override { player_body.set_sprite((cocos2d::Sprite*)sprite); };

  void set_weapon(IWeapon* new_weapon) { weapon = new_weapon; };
  void set_riding_object(IRiding_object* new_riding_object) { riding_object = new_riding_object; };
  void release_weapone() { weapon = nullptr; };
  void release_riding_object() { riding_object = nullptr; };
  void* get_weapon() { return weapon; };
  void* get_riding_object() { return riding_object; };
private:
  IWeapon* weapon = nullptr;
  IRiding_object* riding_object = nullptr;
  character player_body;
};
