#### 문제 5 범위 기반 for 문 초기화
범위 기반 for 문의 다양한 초기화 방법 중 R-value 참조를 사용하는 예를 직접 만들고, 예에서 R-value 참조를 사용해야 하는 이유를 설명해 보세요.
<br/><br/>

---


#### 모범 답안
##### 답안
```cpp
#include <iostream>
#include <vector>
#include <random>

using namespace std;

int get_random_index(int max) {
  static mt19937 generator(time(nullptr));
  uniform_int_distribution<int> distribution(0, max - 1);
  return distribution(generator);
}

std::string create_sentence() {
  vector<string> subjects = { "고양이가", "강아지가", "아빠가", "낯선 사람이", "경찰관이" };
  vector<string> verbs = { "들고 있다", "던졌다", "쳐다봤다", "달라고 했다", "가졌다" };
  vector<string> objects = { "배를", "책을", "핸드폰을", "컴퓨터를", "아이스크림을" };

  string subject = subjects[get_random_index(subjects.size())];
  string verb = verbs[get_random_index(verbs.size())];
  string object = objects[get_random_index(objects.size())];

  return subject + " " + object + " " + verb + ".";
}
int main() {

  for (auto&& sentences = vector<string>{ create_sentence(), create_sentence(), create_sentence() };
    auto & sentence : sentences) {
    cout << sentence << endl;
  }

    return 0;
}
```
###### 실행 결과
예시1
```
경찰관이 컴퓨터를 가졌다.
고양이가 책을 쳐다봤다.
낯선 사람이 책을 들고 있다.
```
예시2
```
아빠가 핸드폰을 던졌다.
경찰관이 배를 들고 있다.
낯선 사람이 책을 던졌다.
```
예시3
```
낯선 사람이 아이스크림을 쳐다봤다.
낯선 사람이 아이스크림을 들고 있다.
경찰관이 핸드폰을 달라고 했다.
```
* 실행 할 때마다 다른 문장이 vector에 저장되고 다른 문장이 출력됩니다.
##### 설명
범위 기반 for 문을 실행 하기 전에 for문에서 사용할 vector에 string을 저장합니다. 주어진 품사 더미에서 문장을 랜덤하게 생성해서 사용합니다. 초기화 구문으로 문장을 생성하면서 vector를 R-value로 저장합니다.

[문제로 돌아 가기](README.md "문제로 돌아 가기")
