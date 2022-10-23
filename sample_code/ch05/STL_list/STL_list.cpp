#include <iostream>
#include <list> 

using namespace std;

int main() {
  list<int> my_list;

  // 원소 추가 
  my_list.push_back(2);
  my_list.push_back(3);
  my_list.push_back(4);
  my_list.push_front(1);
  my_list.push_front(0);

  list<int>::iterator iter = my_list.begin();

  cout << "1. 리스트 출력 : ";
  for (iter = my_list.begin(); iter != my_list.end(); iter++) {
    cout << *iter << ' '; // 원본 리스트: 0 1 2 3 4
  }
  cout << endl << endl;


  my_list.pop_front();
  my_list.pop_back();

  cout << "2. 삭제 후 리스트 출력 : ";
  for (iter = my_list.begin(); iter != my_list.end(); iter++) {
    cout << *iter << ' '; // 원소 삭제후 리스트: 1 2 3 
  }
  cout << endl << endl;

  cout << "3. 리스트 사이즈는? : " << my_list.size() << endl << endl;

  cout << "4. 리스트가 비어있는가? : " << my_list.empty() << endl << endl;

  cout << "5. 리스트 가장 처음에 있는 원소는? : " << my_list.front() << endl << endl;

  cout << "6. 리스트 가장 마지막에 있는 원소는? : " << my_list.back() << endl;

  return 0;
}
