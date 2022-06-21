#include <iostream>
#include <vector>

using namespace std;

void pointer_increasement_sample() {
  char data[32] = { };
  int i;

  for (i = 0; i < 32; ++i) {
    data[i] = 65 + i;
  }

  char* ptr_char = data;
  char display_char = ' ';
  int* ptr_int = (int*)data;

  for (i = 0; i < 4; ++i) {
    display_char = ptr_int[0];
    cout << i << " :  - " << *ptr_char << " , " << display_char << endl;
    ptr_char++;
    ptr_int++;
  }

  auto ptr_auto = data;

  for (i = 0; i < 4; ++i) {
    cout << i << " :  - " << ptr_auto[0] << endl;
    ptr_auto++;
  }
  cout << "ptr_auto: " << typeid(ptr_auto).name() << endl;
}

int main() {
  auto auto_var_1 = 10;
  auto auto_var_2 = 20.38;
  auto auto_var_3 = 0x10;
  auto auto_var_4 = 'A';
  auto auto_var_5 = "auto ÀÚ·áÇü";
  auto auto_var_6 = new vector<int>;

  cout << "auto_var_1: " << typeid(auto_var_1).name() << endl;
  cout << "auto_var_2: " << typeid(auto_var_2).name() << endl;
  cout << "auto_var_3: " << typeid(auto_var_3).name() << endl;
  cout << "auto_var_4: " << typeid(auto_var_4).name() << endl;
  cout << "auto_var_5: " << typeid(auto_var_5).name() << endl;
  cout << "auto_var_6: " << typeid(auto_var_6).name() << endl;

  delete auto_var_6;

  pointer_increasement_sample();
  return 0;
}