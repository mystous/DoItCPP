#include <iostream>

using namespace std;

enum class weapon : int { gun, arrow, machine_gun };

class monster {
public:
  weapon weapon_type;
};

struct weapon_class {
  using enum weapon;
};

int main() {
  monster monster_obj;
  weapon_class weapon_obj;

  monster_obj.weapon_type = weapon::gun;
  monster_obj.weapon_type = weapon_obj.arrow;
  monster_obj.weapon_type = weapon_class::machine_gun;
 
  return 0;
}