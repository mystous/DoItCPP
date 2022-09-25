#include <iostream>
#include <vector>

using namespace std;

typedef int terrain_type;
constexpr terrain_type forest_terrain_type = 0;
constexpr terrain_type cyber_terrain_type = 1;
constexpr terrain_type urban_terrain_type = 2;

class monster {
public:
  monster(terrain_type type) : monster_type(type) {};
private:
  terrain_type monster_type;
};

using create_monster_function = monster&&(*)(terrain_type);

template<typename T>
using monster_vector = vector<T>;

template <typename T> struct rebind
{
  typedef whatever<T> type; // to make it possible to substitue the whatever in future.
};

monster&& create_monster(terrain_type type) {
  return monster(type);
}

int main() {
  create_monster_function create_func = create_monster;
  monster_vector<monster*> monster_list;

  monster monster_a = create_func(cyber_terrain_type);
  monster_list.push_back(&monster_a);

  monster monster_b = create_func(forest_terrain_type);
  monster_list.push_back(&monster_b);

  monster monster_c = create_func(urban_terrain_type);
  monster_list.push_back(&monster_c);

  return 0;
}