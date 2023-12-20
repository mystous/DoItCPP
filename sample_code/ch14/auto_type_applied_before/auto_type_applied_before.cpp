#include <iostream>
#include <map>
#include <array>

using namespace std;

map<char, array<int, 4>> auto_type_example;
map<int, array<double, 3>> auto_type_example_2;

void build_map() {
  array<int, 4> array_a = { 1, 2, 3, 4 };
  auto_type_example.insert({'a', array_a});

  array<int, 4> array_b = { 11, 21, 31, 41 };
  auto_type_example.insert({ 'b', array_b });

  array<int, 4> array_c = { 12, 22, 32, 42 };
  auto_type_example.insert({ 'c', array_c });

  array<int, 4> array_d = { 13, 23, 33, 43 };
  auto_type_example.insert({ 'd', array_d });

  array<double, 3> array_e = { 3.0, 4.0, 5.0 };
  auto_type_example_2.insert({ 1, array_e});

  array<double, 3> array_f = { 3.1, 4.1, 5.1 };
  auto_type_example_2.insert({ 2, array_f });

  array<double, 3> array_g = { 3.2, 4.2, 5.2 };
  auto_type_example_2.insert({ 3, array_g });

  array<double, 3> array_h = { 3.3, 4.3, 5.3 };
  auto_type_example_2.insert({ 4, array_h });
}

int main() {
  build_map();

  map<char, array<int, 4>>::iterator iter;
  for (iter = auto_type_example.begin(); iter != auto_type_example.end(); iter++) {
    // 어떤 일 하기
  }

  map<int, array<double, 3>>::iterator iter2;
  for (iter2 = auto_type_example_2.begin(); iter2 != auto_type_example_2.end(); iter2++) {
    // 어떤 일 하기
  }

  // 오류 발생 부분
  //map<int, array<int, 4>>::iterator iter3;
  //for (iter3 = auto_type_example.begin(); iter3 != auto_type_example.end(); iter++) {
  //  // 어떤 일 하기
  //}


  for (auto& element : auto_type_example) {
    // 어떤 일 하기
  }

  return 0;
}