#include <iostream>
#include <tuple>
#include <map>

using namespace std;

struct data_struct {
  int number;
  string sentence;
  float decimal;
};

int main() {
  int numbers[3] = { 1, 2, 3 };
  auto [number0, number1, number2] = numbers;
  cout << "배열의 구조적 바인딩" << endl;
  cout << numbers[0] << " : " << number0 << endl;
  cout << numbers[1] << " : " << number1 << endl;
  cout << numbers[2] << " : " << number2 << endl;

  struct data_struct struct_object { 20, "구조체", 10.5f };
  auto [number3, string0, decimal0] = struct_object;
  cout << endl << "구조체의 구조적 바인딩" << endl;
  cout << struct_object.number << " : " << number3 << endl;
  cout << struct_object.sentence << " : " << string0 << endl;
  cout << struct_object.decimal << " : " << decimal0 << endl;

  tuple<int, char, double> tuple_object{ 5, 'C', 20.1f };
  auto [number4, char1, decimal1] = tuple_object;
  cout << endl << "튜플의 구조적 바인딩" << endl;
  cout << get<0>(tuple_object) << " : " << number4 << endl;
  cout << get<1>(tuple_object) << " : " << char1 << endl;
  cout << get<2>(tuple_object) << " : " << decimal1 << endl;

  map<int, string> map_object;

  map_object.insert({ 0, "첫번째" });
  map_object.insert({ 1, "두번째" });
  map_object.insert({ 2, "세번째" });
  cout << endl << "맵의 구조적 바인딩" << endl;
  for (auto [number5, string1] : map_object) {
    cout << "[" << number5 << "] " << map_object[number5] << " : " << string1 << endl;
  }

  return 0;
}