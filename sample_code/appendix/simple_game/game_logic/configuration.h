#pragma once
#include "const_int.h"

class configuration
{
public:
  static int get_move_speed() { return move_speed; };
  static void set_move_speed(int speed) { move_speed = speed; };
  static riding_menu_id get_current_ridigin_object() { return current_riding_object; };
  static void set_riding_object(riding_menu_id object) { current_riding_object = object; };
private:
  static int move_speed;
  static riding_menu_id current_riding_object;
};

