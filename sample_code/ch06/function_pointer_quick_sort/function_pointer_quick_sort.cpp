#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct {
  int number;
  char alphabet;
} DATA, *LPDATA;

DATA data_element[5] = { {4, 'a'}, {1, 'c'}, {8, 'b'}, {2, 'z'}, {4, 'd'} };

int compare2(const void* operand1, const void* operand2) {
  LPDATA data1 = (LPDATA)operand1;
  LPDATA data2 = (LPDATA)operand2;

  return data1->alphabet - data2->alphabet;
}

int compare1(const void* operand1, const void* operand2) {
  LPDATA data1 = (LPDATA)operand1;
  LPDATA data2 = (LPDATA)operand2;

  return data1->number - data2->number;
}

void print() {
  for (int i = 0; i < 5 ; ++i) {
    cout << "{ " << data_element[i].number << " , " << data_element[i].alphabet << " }, ";
  }
  cout << endl;
}

int main() {
  
  cout << "정렬 전" << endl;
  print();

  qsort(data_element, 5, sizeof(DATA), compare1);
  cout << "숫자로 정렬" << endl;
  print();

  qsort(data_element, 5, sizeof(DATA), compare2);
  cout << "문자로 정렬" << endl;
  print();
  
  return 0;
}