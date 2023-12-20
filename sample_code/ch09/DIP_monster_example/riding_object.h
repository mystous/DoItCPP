#pragma once
#include "interface.h"

class car : public IRiding_object {
public:
  virtual int check_energy() override;
  virtual void set_destination(int x, int y) override;
  virtual void run_to_destination() override;
};

class horse : public IRiding_object {
public:
  virtual int check_energy() override;
  virtual void set_destination(int x, int y) override;
  virtual void run_to_destination() override;
};

class motor_cycle : public IRiding_object {
public:
  virtual int check_energy() override;
  virtual void set_destination(int x, int y) override;
  virtual void run_to_destination() override;
};
