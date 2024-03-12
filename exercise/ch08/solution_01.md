### 문제 1 클래스 객체 곱하기 연산자 오버로딩
몬스터 A, B, C를 진화하기 위해서 A, B, C를 곱하는 연산을 오버로딩해 보세요. A×B, A×C, B×A, B×C, C×A, C×B 각각 다른 형태로 진화하도록 만들어 보겠습니다. A×B와 B×A는 다른 형태의 진화입니다. 몬스터 사이에는 상생이 있어서 상생이 좋은 경우는 능력치가 더욱 향상되고, 상생이 좋지 않은 경우에는 진화에 실패합니다. 상생 관계는 다음 표와 같습니다.

||A|B|C|
|:---:|:---:|:---:|:---:|
|A|X2|X3|실패|
|B|X5|X2|실패|
|C|실패|X4|X2|

소스 코드로 구현할 때 한 가지 요구 사항이 있습니다. 흡수한 제물의 능력치를 빼앗는 것뿐만 아니라, 제물의 특수 능력을 사용할 수 있어야 합니다. 그런데 몬스터의 특수 능력은 몬스터 A, B, C가 상속받은 부모의 함수를 오버라이딩한 함수입니다. 제물을 흡수한 몬스터는 자신의 특수 능력과 제물의 특수 능력을 모두 사용 가능합니다. 제물은 컴포지션이나 어그리게이션으로 표현합니다.
<br/><br/>

---

#### 모범 답안
##### 답안
```cpp
#include <iostream>
#include <vector>
using namespace std;

class character {
public:
  character() : hp(100), power(100) {};

  int get_hp() { return hp; };
  int get_power() { return power; };
  void set_hp(int _hp) { hp = _hp; };
  void set_power(int _power) { power = _power; };

protected:
  int hp;
  int power;
};

class attack_ability {
public:
  enum class attack_type : int { forest = 0, urban, terrain, none = -1} ;
  virtual void attack() {};
protected:
  attack_type type = attack_type::none;
};

class forest_attack : public attack_ability {
public:
  forest_attack() { type = attack_type::forest; };
  virtual void attack() final { cout << "수풀 속 공격" << endl; } ;
};

class urban_attack : public attack_ability {
public:
  urban_attack() { type = attack_type::urban; };
  virtual void attack() final { cout << "복잡한 도심 공격" << endl; };
};

class terrain_attack : public attack_ability {
public:
  terrain_attack() { type = attack_type::terrain; };
  virtual void attack() final { cout << "공격의 다양한 지형 활용" << endl; };
};

class dummy_attack : public attack_ability {
public:
  dummy_attack() { type = attack_type::none; };
  virtual void attack() final { };
};

class monster : public character {
public:
  enum class  monster_type  { a, b, c };
  monster();
  virtual ~monster();
  void attack();
  monster* get_pointer() { return this; };
  monster_type get_type() { return type; };
  void set_alive(bool check) { alive = check; };
  void set_sacrifice(monster* target) { sacrifice = target; };
protected:
  vector<attack_ability*> attack_methods;
  monster_type type = monster_type::a;
  monster* sacrifice = nullptr;
  bool alive = true;

  friend static void merge(int multiplex, monster& mon, monster& target) {
    mon.set_hp(mon.get_hp() + multiplex * target.get_hp());
    mon.set_sacrifice(target.get_pointer());
    target.set_alive(false);
    switch (target.get_type()) {
    case monster::monster_type::a:
      if (nullptr == mon.attack_methods[(int)monster::monster_type::a]) {
        mon.attack_methods[(int)monster::monster_type::a] = new forest_attack;
      }
      break;
    case monster::monster_type::b:
      if (nullptr == mon.attack_methods[(int)monster::monster_type::b]) {
        mon.attack_methods[(int)monster::monster_type::b] = new urban_attack;
      }
      break;
    case monster::monster_type::c:
      if (nullptr == mon.attack_methods[(int)monster::monster_type::c]) {
        mon.attack_methods[(int)monster::monster_type::c] = new terrain_attack;
      }
      break;
    }
  };
};

class monster_a : public monster {
public:
  monster_a() {
    type = monster_type::a;
    attack_methods[(int)type] = new forest_attack;
  };
  monster_a& operator*(monster& target);
};

class monster_b : public monster {
public:
  monster_b() {
    type = monster_type::b;
    attack_methods[(int)type] = new urban_attack;
  };
  monster_b& operator*(monster& target);
};

class monster_c : public monster {
public:
  monster_c() {
    type = monster_type::c;
    attack_methods[(int)type] = new terrain_attack;
  };
  monster_c& operator*(monster& target);
};

monster_a& monster_a::operator*(monster& target) {
    switch (target.get_type()) {
    case monster_type::a:
      merge(2, *this, target);
      break;
    case monster_type::b:
      merge(3, *this, target); break;
    case monster_type::c:
      break;
    }
  return *this;
}

monster_b& monster_b::operator*(monster& target) {
  switch (target.get_type()) {
  case monster_type::a:
    merge(5, *this, target);
    break;
  case monster_type::b:
    merge(2, *this, target); break;
  case monster_type::c:
    break;
  }
  return *this;
}

monster_c& monster_c::operator*(monster& target) {
  switch (target.get_type()) {
  case monster_type::a:
    break;
  case monster_type::b:
    merge(4, *this, target); break;
  case monster_type::c:
    merge(2, *this, target);
    break;
  }
  return *this;
}
monster::monster() {
  for (int i = 0; i < 3; ++i) {
    attack_methods.push_back(nullptr);
  }
}

monster::~monster() {
  for (int i = 0; i < 3; ++i) {
    attack_ability *obj = attack_methods[i];

    if (nullptr != obj) {
      delete obj;
      attack_methods[i] = nullptr;
    }
  }
}
void monster::attack() {
  for (auto && attack_method : attack_methods) {
    if (nullptr == attack_method) {
      continue;
    }
    attack_method->attack();
  }
}

int main()
{
  monster_a mon_a, mon_a2, mon_a3, sc_mon_a;
  monster_b sc_mon_b;
  monster_c sc_mon_c;

  cout << "A : hp(" << mon_a.get_hp() << ")" << endl;
  mon_a = mon_a * sc_mon_b;
  cout << "A * B : hp(" << mon_a.get_hp() << ")" << endl;
  mon_a.attack();
  mon_a2 = mon_a2 * sc_mon_a;
  cout << "A * A : hp(" << mon_a2.get_hp() << ")" << endl;
  mon_a2.attack();
  mon_a3 = mon_a3 * sc_mon_c;
  cout << "A * C : hp(" << mon_a3.get_hp() << ")" << endl;
  mon_a3.attack();

  return 0;
}
```
##### 실행결과
```
A : hp(100)
A * B : hp(400)
수풀 속 공격
복잡한 도심 공격
A * A : hp(300)
수풀 속 공격
A * C : hp(100)
수풀 속 공격
```
##### 설명
함수와 클래스를 작게 만드려다 보니 소스 코드가 꽤 길어 졌습니다. 핵심적인 부분만 살펴 보도록 하겠습니다. monster 클래스를 상속 받은 monster_a, monster_b, monster_c는 operator*를 오버라이드하였습니다. 각각 본인 클래스를 반환해야 하기 때문에 부모 클래스로 부터 상속받지 않고 각자 오버라이드 합니다.

제물로 사용될 몬스터의 타입에 따라서 체력을 보충하고 제물이 가지고 있는 공격 기술을 공격 리스트에 추가합니다. 동일한 동작이 몇몇 변수가 다르게 동작하기 때문에 merge함수로 공용하 하였습니다. 

공격 방식도 클래스로 만들어서 몬스터가 모든 공격 방식을 순회 하면서 다형성을 통해 다른 공격이 실행되도록 하였습니다.

[문제로 돌아 가기](README.md "문제로 돌아 가기")
