#pragma once
#include "interface.h"
#include "base_classes.h"
#include "player_class.h"

//Monster 인터페이스
class monster : public IRoute, public IAttack {
public:
  int get_monster_type() { return monster_type; };
  virtual void set_location(int x, int y) override { location_x = x; location_y = y; };
  virtual int get_location(bool x) override { return x ? location_x : location_y; };

protected:
  int calculate_distance(int x, int y);
  character* target_player = nullptr;
  int monster_type;
  character monster_body;

private:
  int location_x;
  int location_y;
};

//몬스터 A는 추상 클래스 Monster 클래스로부터 상속
class monster_a : public monster {
public:
  monster_a() {
    monster_type = monster_a_type;
  };
  virtual void find_route(int x, int y) override;
  virtual bool attach_target(void* target_player) override;
  virtual void check_target(void* target_player) override;
  virtual void attack_special(void* target_player) override;
};


//몬스터 B는 추상 클래스 Monster 클래스로부터 상속
class monster_b : public monster {
public:
  monster_b() {
    monster_type = monster_b_type;
  };
  virtual void find_route(int x, int y) override;
  virtual bool attach_target(void* target_player) override;
  virtual void check_target(void* target_player) override;
  virtual void attack_special(void* target_player) override;
};


//몬스터 C는 추상 클래스 Monster 클래스로부터 상속
class monster_c : public monster {
public:
  monster_c() {
    monster_type = monster_c_type;
  };
  virtual void find_route(int x, int y) override;
  virtual bool attach_target(void* target_player) override;
  virtual void check_target(void* target_player) override;
  virtual void attack_special(void* target_player) override;
};

//Character factory
class character_factory
{
public:
  static void create_monster(const int terrain_type, int count);
  static void destroy_monster();
  static void create_terrain();
  static void destroy_terrain();
  static void create_npc();
  static void destory_npc();
  static monster* get_monster(int index);
  static int get_monster_count();
  static void initialize_monster();

private:
  static monster* create_monster(const int terrain_type, void* terrain_inst);
  static list<monster*> mon_list;
  static list<npc_object*> npc_list;
  static int mon_count;
  static void* terrain_inst[3];
};

list<monster*> character_factory::mon_list = {};
list<npc_object*> character_factory::npc_list = {};
int character_factory::mon_count = 0;
void* character_factory::terrain_inst[] = { nullptr, };
