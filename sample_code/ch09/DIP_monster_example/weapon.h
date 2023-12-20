#pragma once
#include "interface.h"
class gun : public IWeapon {
public:
  virtual void reload_bullet() override;
  virtual bool is_bullet_empty() override;
  virtual void shoot_weapon(void* target_plaery)  override;
};

class machine_gun : public IWeapon {
public:
  virtual void reload_bullet() override;
  virtual bool is_bullet_empty() override;
  virtual void shoot_weapon(void* target_plaery)  override;
};

class arrow : public IWeapon {
public:
  virtual void reload_bullet() override;
  virtual bool is_bullet_empty() override;
  virtual void shoot_weapon(void* target_plaery) override;
};