#pragma once
#include "interface.h"
#include "base_classes.h"
#include "const_string.h"

using namespace std;

class base_riding {
public:
  base_riding(string object_name) : name(object_name) {};
  string get_object_name() { return name; };
private:
  string name;
};

class car : public IRiding_object, public sprite_object {
public:
  car() : riding_body(riding_object_car) {};
  virtual int check_energy() override;
  virtual void set_destination(int x, int y) override;
  virtual void run_to_destination() override;
  virtual string get_object_name() override { riding_body.get_object_name(); };

private:
  base_riding riding_body;
};

class horse : public IRiding_object, public sprite_object {
public:
  horse() : riding_body(riding_object_horse) {};
  virtual int check_energy() override;
  virtual void set_destination(int x, int y) override;
  virtual void run_to_destination() override;
  virtual string get_object_name() override { riding_body.get_object_name(); };

private:
  base_riding riding_body;
};

class motor_cycle : public IRiding_object, public sprite_object {
public:
  motor_cycle() : riding_body(riding_object_motor_cycle) {};
  virtual int check_energy() override;
  virtual void set_destination(int x, int y) override;
  virtual void run_to_destination() override;
  virtual string get_object_name() override { riding_body.get_object_name(); };

private:
  base_riding riding_body;  
};
