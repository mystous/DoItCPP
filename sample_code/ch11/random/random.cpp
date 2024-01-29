#include <iostream>
#include <random>

using namespace std;

int main() {
  mt19937_64 mt_rand;

  for (int i = 0; i < 10; i++) {
    cout << mt_rand() << endl;
  }

  return 0;
}
