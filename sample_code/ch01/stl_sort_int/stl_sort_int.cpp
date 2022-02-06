#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void print_out_array(string pre, int(&array)[10]) {
  cout << pre;

  for (int i = 0; i < 10; ++i) {
    cout << array[i] << " , ";
  }
  cout << endl;
}

int main(void) {
  int array[10] = { 7, 8, 2, 5, 3, 9, 0, 4, 1, 6 };

  sort(array, array + 10);
  print_out_array("정렬 후: ", array);

  return 0;
}