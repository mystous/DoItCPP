#### 문제 5 임의의 순서로 정렬하기
[문제 4]의 코드를 이어서 활용합니다. 
‘이름 > HP > MP’ 순으로 정렬하는 함수를 만들어 보세요. 
그리고 해당 함수가 잘 동작하는지 컨테이너에 저장된 몬스터들을 모두 출력해서 확인해 보세요.
<br/><br/>

---

#### 모범 답안 과 설명
##### 답안
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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

// 몬스터 정렬 함수 (이름 > HP > MP 순)
bool compareMonsters(const Monster& lhs, const Monster& rhs) {
  if (lhs.name != rhs.name) {
    return lhs.name < rhs.name;
  }
  else if (lhs.HP != rhs.HP) {
    return lhs.HP > rhs.HP;
  }
  else {
    return lhs.MP > rhs.MP;
  }
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

  // 몬스터 정렬
  sort(monsters.begin(), monsters.end(), compareMonsters);

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
이름: 고블린, HP: 118, MP: 50
이름: 드래곤, HP: 139, MP: 33
이름: 마법사, HP: 118, MP: 45
이름: 스켈레톤, HP: 125, MP: 59
이름: 스켈레톤, HP: 117, MP: 43
이름: 스켈레톤, HP: 116, MP: 23
이름: 악마, HP: 124, MP: 54
이름: 오우거, HP: 112, MP: 68
이름: 페어리, HP: 99, MP: 49
이름: 페어리, HP: 91, MP: 28
```

compareMonsters 정렬함수는 아래 세가지 기준으로 두 몬스터를 비교하여 정렬 순서를 결정합니다.
1. 이름이 다르면 이름을 기준으로 정렬
2. 이름이 같으면 HP가 높은 몬스터가 앞쪽
3. HP도 같으면 MP가 높은 몬스터가 앞쪽

[문제로 돌아 가기](README.md "문제로 돌아 가기")
