#### 문제 2 다중 상속 개념
다중 상속의 단점을 설명해 보세요. 그리고 몬스터 소스에서 다중 상속을 받는 클래스 한 가지를 선택하여 어그리게이션으로 변경해 보세요.
<br/><br/>

---


#### 모범 답안 과 설명
##### 답안
###### (08-1 참고)
클래스가 다양한 역할을 수행을 위하여 다중 상속을 하게 되면 거대 클래스(large class)가 됩니다. 클래스가 커지면 그만큼 속성과 기능이 많아지므로 사용하기가 어렵고 부모 클래스 중 일부가 변경되면 상속받은 모든 클래스를 다시 컴파일해야 하는데, 자식 클래스가 많거나 다양한 라이브러리에서 사용되면 변경 사항이 여러 곳에 영향을 주므로 바람직하지 않습니다.

다중 상속으로 거대 클래스가 되면 거대 클래스가 된 클래스는 작은 수정이 있을 때도 늘 수정하게 됩니다. 유지보수성을 높이기 위해서는 클래스는 최소한의 역할을 수행해야 하며, 가능한 논리적으로 한 종류의 역할을 해야 합니다.

##### 몬스터 클래스 수정 (ch07/op_overload_different_class/op_overload_different_class.cpp 수정)
```cpp
#include <iostream>
#include <string>

using namespace std;

class character {
public:
  character() : hp(100), power(100), location{ 0,0 }, level(1) {
  };
  void move(int x, int y) {};
  void move(int x[], int y[], int spot_count) {}
  void get_damage(int _damage) {};
  int get_hp() { return hp; };
  int get_level() { return level; };
  void set_level(int lv) { level = lv; };
  void set_hp(int new_hp) { hp = new_hp; };

protected:
  int hp;
  int power;
  int location[2];
  int level;
};

class player : public character {
public:
  player() {};
};

//기본 Monster 클래스
class monster {
public:
  void attack(player target_player) {};
  virtual void attack_special(player target_player);
};

void monster::attack_special(player target_player) {
  cout << "기본 공격 : 데미지 - 10 hp" << endl;
}

//몬스터 C는 기본 Monster 클래스로부터 상속
class monster_c : public monster {
public:
  //상속받은 함수 오버라이딩
  void attack_special(player target_player) override;
  void set_body(character* object) { body = object; };
  monster_c operator+(monster_c& operand);
  monster_c operator+(player& operand);
  void set_level(int level_value) { body->set_level(level_value); };
  void set_hp(int hp_value) { body->set_hp(hp_value); };
  int get_level() { return body->get_level(); };
  int get_hp() { return body->get_hp(); };
  character* return_body() { return body; };
  character* body = nullptr;
};

monster_c monster_c::operator+(monster_c& operand) {
  monster_c result_monster;
  result_monster.set_body(body);
  result_monster.set_level(body->get_level() + operand.get_level());
  return result_monster;
}

monster_c monster_c::operator+(player& operand) {
  monster_c result_monster;
  result_monster.set_body(body);
  result_monster.set_hp(body->get_hp() + operand.get_hp());
  return result_monster;
}

void monster_c::attack_special(player target_player) {
  cout << "강력 뇌전 공격 : 데미지 - 100 hp" << endl;
}

int main() {

  monster_c monster_c_obj1, monster_c_obj2;
  character body1, body2;

  monster_c_obj1.set_body(&body1);
  monster_c_obj2.set_body(&body2);
  monster_c_obj2.set_level(2);
  player player1;
  monster_c new_monster_c_obj = monster_c_obj1 + monster_c_obj2;

  cout << "Player 합체 전 몬스터C HP[" << new_monster_c_obj.get_hp()
    << "]" << endl;

  new_monster_c_obj = new_monster_c_obj + player1;

  cout << "Player 합체 후 몬스터C HP[" << new_monster_c_obj.get_hp()
    << "]" << endl;

  return 0;
}
```
#### 실행결과
```
Player 합체 전 몬스터C HP[100]
Player 합체 후 몬스터C HP[200]
```
실행결과가 수정 전과 동일한 것을 알 수 있습니다. monster_c 클래스는 이중 상속을 단일 상속으로 바꾸고 character 클래스를 어그리게이션으로 가지고 포함하었습니다.

[문제로 돌아 가기](README.md "문제로 돌아 가기")
