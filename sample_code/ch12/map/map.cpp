#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
  map<string, int> scores;

  // 키-값 쌍 삽입
  scores.insert(make_pair("Bob", 85));
  scores.insert(make_pair("Jane", 90));
  scores.insert(make_pair("Tom", 70));

  // 맵 크기 출력
  cout << "map 크기: " << scores.size() << endl;

  // 특정 키에 해당하는 값 검색
  auto it = scores.find("Bob");
  if (it != scores.end()) {
    cout << "Bob의 점수 검색 결과: " << it->second << endl;
  }
  else {
    cout << "Bob의 점수는 저장되어 있지 않음" << endl;
  }
  cout << endl;

  // 특정 키에 해당하는 키-값 제거
  scores.erase("Bob");  //Bob 정보 제거

  // 맵 크기 출력
  cout << "Bob 정보 제거 후, map 크기: " << scores.size() << endl << endl;

  // 맵을 순회하며 모든 키와 값 출력
  cout << "---map 모든 원소 출력---" << endl;
  for (const auto& pair : scores) {
    cout << pair.first << ": " << pair.second << endl;
  }

  return 0;
}