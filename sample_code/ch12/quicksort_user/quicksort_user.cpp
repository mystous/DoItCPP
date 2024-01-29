#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Person {
  string name;   // 이름
  int age;       // 나이
  float height;	 // 키
  float weight;	 // 몸무게
};

void print_preson_all(vector<Person>& vec) {
  for (vector<Person>::iterator it = vec.begin(); it != vec.end(); it++) {
    cout << "이름: " << it->name << "\t > " << "나이: " << it->age << ", " << "키: " << it->height << ", " << "몸무게: " << it->weight << endl;
  }
}

// Person 구조체의 나이 비교(첫 번째 인자의 나이가 작으면 true)
bool compare(const Person& lhs, const Person& rhs) {
  return lhs.age < rhs.age;
}

int main() {
  Person p[5] = {
      {"Brain", 24, 180, 70},
      {"Jessica", 22, 165, 55},
      {"James", 30, 170, 65},
      {"Tom", 12, 155, 46},
      {"Mary", 18, 172, 62}
  };

  vector<Person> vec;
  vec.push_back(p[0]);
  vec.push_back(p[1]);
  vec.push_back(p[2]);
  vec.push_back(p[3]);
  vec.push_back(p[4]);

  cout << "-----정렬 전-----" << endl;
  print_preson_all(vec);
  cout << endl;

  // 사용자 정의 기준으로 정렬
  sort(vec.begin(), vec.end(), compare);

  cout << "-----정렬 후-----" << endl;
  print_preson_all(vec);

  return 0;
}
