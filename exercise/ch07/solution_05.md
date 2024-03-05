#### 문제 5 객체지향 프로그래밍
이번 장에서 배운 내용을 바탕으로 몬스터 C를 프로그래밍해 보세요. 몬스터 C는 무적 타임이 적용되어 1분에 2초씩은 데미지를 입지 않는다고 가정하겠습니다. 몬스터 C의 특별 공격은 플레이어의 체력과 힘에 동시 데미지를 입힙니다. this 포인터를 이용해 멤버 함수 체이닝을 사용하세요.
<br/><br/>

---


#### 모범 답안
##### 답안
```cpp
#include <iostream>
using namespace std;

class character {
public:
  character() : hp(100), power(100) {};

  virtual void get_damage(int _damage) {
    reduce_data(hp, _damage);
  };

  void lose_power(int _lose) {
    reduce_data(power, _lose);
  };

  int get_hp() { return hp; };
  int get_power() { return power; };
  void set_hp(int _hp) { hp = _hp; };
  void set_power(int _power) { power = _power; };

protected:
  int hp;
  int power;
  void reduce_data(int& attribute, int _damage) {
    if (attribute == 0) { // 0 보다 클 때만 줄어 들음
      return;
    }

    attribute -= _damage;
    attribute = attribute < 0 ? 0 : attribute; // 결과가 0보다 작으면 0으로 설정
  };
};

//character 클래스를 상속 받은 player 클래스
class player : public character {
public:
  player() {};
  void attack(character& enemy) { enemy.get_damage(5); };
};

//기본 Monster 클래스
class monster_c : public character {
public:
  monster_c() : clock(60) {
    set_hp(1000);
  };
  monster_c& attack(player& target_player);
  monster_c& reduce_power(player& target_player);
  virtual void get_damage(int _damage) override;
  void ticktok(); // 수동으로 시간을 흐르게 함
private:
  int clock;
};

void monster_c::ticktok() { // 수동으로 시간을 흐르게 함
  clock++;
  clock %= 60;
}

void monster_c::get_damage(int _damage) {
  if (clock < 3) { // 1분 중 처음 2초간은 공격을 받지 않음
    return;
  }
  reduce_data(hp, _damage);
}
monster_c& monster_c::attack(player& target_player) {
  target_player.get_damage(1);
  return *this; // 체이닝을 위한 자기 자신 반환
}

monster_c& monster_c::reduce_power(player& target_player) {
  target_player.lose_power(1);
  return *this; // 체이닝을 위한 자기 자신 반환
}

void print_out(string title, monster_c mon, player user) {
  cout << title << endl;
  cout << "Monster C: hp(" << mon.get_hp() << "), power(" << mon.get_power() << ")" << endl;
  cout << "Player: hp(" << user.get_hp() << "), power(" << user.get_power() << ")" << endl;
}

int main()
{
  monster_c mon;
  player user;

  print_out("게임 시작 전", mon, user);

  for (int i = 0; i < 60; ++i) { // 반복문 1회 반복을 1초로 가정
    user.attack(mon);
    mon.attack(user).reduce_power(user).ticktok();
  }

  print_out("게임 종료 후", mon, user);

  return 0;
}
```

###### 실행결과
```
게임 시작 전
Monster C: hp(1000), power(100)
Player: hp(100), power(100)
게임 종료 후
Monster C: hp(710), power(100)
Player: hp(40), power(40)
```

##### 설명
monster_c 클래스는 charater의 get_damage 함수를 재정의 하여 2초간은 데이미지를 받지 않고 함수를 종료 합니다. 시간이 흐르는 함수나 라이브러리를 아직 배우지 않아 시간이 흐르는 함수는 수동으로 작성하고 호출합니다. 

(monster_c::ticktok()). monster_c 클래스의 attack, recude_power는 체이닝을 구현하기 위해서 함수가 종료 될 때 자기 자신을 반환하도록 코드가 작성이 되었습니다. 실제 실행은 60초(60번 반복) 동안 서로 공격을 한 후 남은 체력과 공격력을 보여줍니다. monster_c는 잔여 체력이 700이 아니라 710인 것을 확인할 수 있습니다.

[문제로 돌아 가기](README.md "문제로 돌아 가기")
