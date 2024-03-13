#### 문제 3 리스코프 치환 원칙(LSP)
08장 되새김 문제 3번에서 작성한 커피 만들기 클래스의 의사코드에서 리스코프 치환 원칙이 잘 적용되었는지 코드를 지칭하여 기술해 보세요.
<br/><br/>

---


#### 모범 답안
##### [답안]
되새김 문제 8-03의 main 함수를 보겠습니다. 

```cpp
int main()
{
  self_serving self_coffee_shop;
  franchise coffee_love;
  small_shop our_coffe;
  vector<coffee_shop*> coffee_shop_list;

  self_coffee_shop.set_name("무인매장");
  coffee_shop_list.push_back(&self_coffee_shop);

  coffee_love.set_name("프랜차이즈");
  coffee_shop_list.push_back(&coffee_love);

  our_coffe.set_name("로컬 커피");
  coffee_shop_list.push_back(&our_coffe);

  for (auto&& shop : coffee_shop_list) {
    cout << endl << ">> " << shop->get_name() << " << " << endl;
    shop->order_coffee();
  }

  return 0;
}
```
3종류의 커피숍 객체를 만들어서 부모 클래스로 업케스팅해서 vector에 저장합니다. vector에 저장한 후 for문으로 업케스팅된 클래스 객체의 포인터로 order_coffee()를 호출하면 만들어진 객체의 함수가 호출이 됩니다. 리스코프 치환 원칙에 따라서 자식이 부모의 위치를 완벽히 치환하였습니다.

[문제로 돌아 가기](README.md "문제로 돌아 가기")
