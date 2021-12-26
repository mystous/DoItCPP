#include <iostream>
#include <algorithm>
#include <string>

void print_out_array(std::string pre, int(&array)[10])
{
  std::cout << pre;

  for (int i = 0; i < 10; ++i) {
    std::cout << array[i] << " , ";
  }
  std::cout << std::endl;
}

int main(void)
{
  int array[10] = { 7, 8, 2, 5, 3, 9, 0, 4, 1, 6 };

  std::sort(array, array + 10);
  print_out_array("정렬 후: ", array);

  return 0;
}