#### 모범 답안 과 설명
##### 답안
```cpp
#include <iostream>

using namespace std;

// 몬스터 구조체
struct monster {
  string name; // 이름
  int hp; // 체력
  int attack; // 공격력
  int defense; // 방어력
  int speed; // 속도
};

// 몬스터 정보 출력 함수
void print_monster(monster monster) {
  cout << "---- 몬스터 정보 ----" << endl;
  cout << "이름: " << monster.name << endl;
  cout << "체력: " << monster.hp << endl;
  cout << "공격력: " << monster.attack << endl;
  cout << "방어력: " << monster.defense << endl;
  cout << "속도: " << monster.speed << endl;
}

int main() {
  // 몬스터 변수 생성
  monster slime = { "슬라임", 100, 10, 5, 10 };

  // 몬스터 정보 출력
  print_monster(slime);

  return 0;
}
```
##### 설명
<li>monster 구조체는 name, hp, attack, defense, speed 5가지 속성을 가집니다.</li>
<li>print_monster 함수는 monster 구조체 형식의 변수를 인자로 받아 각 속성의 값을 출력합니다.</li>
