#include <iostream>
#include "weapon.h"

using namespace std;

void gun::reload_bullet() {
  cout << "탄창 교체" << endl;
}

bool gun::is_bullet_empty() {
  cout << "탄창에 남은 총알이 있는가?" << endl;
  return true; // 예제에서는 임의로 비었다고 가정함
}

void gun::shoot_weapon(void* target_plaery) {
  cout << "\"탕\"" << endl;
}

void machine_gun::reload_bullet() {
  cout << "대형 탄창 교체" << endl;
}

bool machine_gun::is_bullet_empty() {
  cout << "탄창에 남은 총알이 있는가?" << endl;
  return true; // 예제에서는 임의로 비었다고 가정함
}

void machine_gun::shoot_weapon(void* target_plaery) {
  cout << "\"두두두두두두\"" << endl;
}

void arrow::reload_bullet() {
  cout << "화살통 채우기" << endl;
}

bool arrow::is_bullet_empty() {
  cout << "화살통이 비였는가?" << endl;
  return true; // 예제에서는 임의로 비었다고 가정함
}

void arrow::shoot_weapon(void* target_plaery) {
  cout << "피이이잉" << endl;
}