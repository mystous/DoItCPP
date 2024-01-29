#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
  multimap<string, int> scores;

  // 멀티 맵에 원소(키-값 쌍) 삽입
  scores.insert(make_pair("Bob", 85));
  scores.insert(make_pair("Jane", 90));
  scores.insert(make_pair("Tom", 70));
  scores.insert(make_pair("Bob", 100));  // 중복 키 허용

  // 멀티 맵의 크기를 출력
  cout << "multimap 크기: " << scores.size() << endl;

  // 특정 키에 해당하는 원소의 개수 구하기
  int count = scores.count("Bob");
  cout << "저장되어 있는 Bob 점수의 갯수: " << count << endl;

  // 특정 키를 가진 원소의 범위 구하기
  auto range = scores.equal_range("Bob");
  if (range.first != scores.end()) {
    cout << "Bob의 모든 점수: ";
    for (auto it = range.first; it != range.second; ++it) {
      cout << it->second << " ";
    }
    cout << endl;
  }
  else {
    cout << "Bob의 점수는 저장되어 있지 않음" << endl;
  }
  cout << endl;

  // 특정 키에 해당하는 모든 원소 삭제
  scores.erase("Bob");  //Bob 정보 제거

  // 멀티 맵의 크기 출력
  cout << "Bob 정보 제거 후, multimap 크기: " << scores.size() << endl << endl;

  // 멀티 맵을 순회하며 모든 키와 값 출력
  cout << "---multimap 모든 원소 출력---" << endl;
  for (const auto& pair : scores) {
    cout << pair.first << ": " << pair.second << endl;
  }

  return 0;
}