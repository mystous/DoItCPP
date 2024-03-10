#### 문제 4 벡터 생성과 사용자 정의 데이터 형식 저장하기
이름, HP, MP 속성을 가지는 몬스터 구조체를 만들고, 벡터 컨테이너에 서로 다른 몬스터 객체 10마리를 저장합니다.
그리고 컨테이너에 저장된 모든 몬스터를 출력해 보세요.
<br/><br/>

---

#### 모범 답안 과 설명
##### 답안
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

// 몬스터 구조체 정의
struct Monster {
  string name;
  int HP;
  int MP;
};

// 랜덤한 몬스터 생성 함수
Monster generateRandomMonster(mt19937& gen) {
  // 랜덤한 이름과 HP, MP 생성
  vector<string> names = { "슬라임", "고블린", "오우거", "드래곤", "스켈레톤", "코볼트", "마법사", "악마", "페어리" };
  uniform_int_distribution<int> name_dist(0, names.size() - 1);
  uniform_int_distribution<int> HP_dist(50, 150);
  uniform_int_distribution<int> MP_dist(20, 70);

  string name = names[name_dist(gen)];
  int HP = HP_dist(gen);
  int MP = MP_dist(gen);

  // 생성된 몬스터 반환
  return { name, HP, MP };
}

int main() {
  // 랜덤 엔진 초기화
  random_device rd;
  mt19937 gen(rd());

  // 몬스터를 담을 벡터 생성
  vector<Monster> monsters;

  // 10마리의 몬스터 생성하여 벡터에 추가
  for (int i = 0; i < 10; ++i) {
    monsters.push_back(generateRandomMonster(gen));
  }

  // 벡터에 저장된 몬스터 정보 출력
  cout << "---몬스터 목록---" << endl;
  for (const auto& monster : monsters) {
    cout << "이름: " << monster.name << ", HP: " << monster.HP << ", MP: " << monster.MP << endl;
  }

  return 0;
}
```

##### 설명
실행결과
```cpp
---몬스터 목록---
이름: 악마, HP: 142, MP: 60
이름: 마법사, HP: 133, MP: 42
이름: 페어리, HP: 88, MP: 50
이름: 스켈레톤, HP: 104, MP: 39
이름: 마법사, HP: 81, MP: 43
이름: 코볼트, HP: 140, MP: 38
이름: 악마, HP: 65, MP: 56
이름: 스켈레톤, HP: 127, MP: 40
이름: 코볼트, HP: 101, MP: 36
이름: 코볼트, HP: 94, MP: 31
```

generateRandomMonster 함수에서 몬스터를 무작위로 만들어 냅니다.
names 벡터에 있는 몬스터 이름 중 하나를 무작위로 선택하고, HP_dist와 MP_dist를 사용하여 몬스터의 체력과 마나 역시 무작위로 생성합니다.
생성된 몬스터 정보를 Monster 구조체에 담아 반환합니다.

[문제로 돌아 가기](README.md "문제로 돌아 가기")
