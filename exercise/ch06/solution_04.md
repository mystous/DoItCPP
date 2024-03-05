#### 문제 4 객체지향 설계 #1
[문제2]에서 설계한 진공 청소기 최상위 부모 클래스를 문법에 맞게 C++로 작성해 보세요.<br/><br/>

---


#### 모범 답안
##### 답안
```cpp
class vacuum_cleaner_parent {
protected:
  filter hepa_filter;
  suction main_suction_pipe;
  dust_collection dust_collect_device;
  dust_bag multiple_use_dust_bag;
};
```
#### 설명
최상위 클래스는 진공청송기가 가져야 할 기본적인 구조를 가지고 있습니다. 현재 설계된 구조는 모터는 하위 클래스에서 정의 하도록 되어 있어 최상위 클래스에는 모터는 제외되어 있습니다.

[문제로 돌아 가기](README.md "문제로 돌아 가기")
