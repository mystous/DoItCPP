#include "riding_object.h"
#include <iostream>

using namespace std;

int car::check_energy() {
  cout << "연료 체크" << endl;
  return 30;
}

void car::set_destination(int x, int y) {
}

void car::run_to_destination() {
  cout << "부르르르릉" << endl;
}

int horse::check_energy() {
  cout << "체력 체크" << endl;
  return 30;
}

void horse::set_destination(int x, int y) {
}

void horse::run_to_destination() {
  cout << "다그닥 다그닥" << endl;
}

int motor_cycle::check_energy() {
  cout << "연료 체크" << endl;
  return 30;
}

void motor_cycle::set_destination(int x, int y) {
}

void motor_cycle::run_to_destination() {
  cout << "부다다다다" << endl;
}