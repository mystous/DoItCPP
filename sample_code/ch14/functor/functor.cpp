#include <iostream>

using namespace std;

struct bomb {
  void operator()() {
    cout << "꽝!" << endl;
  }

  void operator()(int range) {
    cout << "반경 " << range << "m내 플레이어 공격!" << endl;
  }
};

int main() {
  bomb mine;

  mine();
  mine(30);

  return 0;
}