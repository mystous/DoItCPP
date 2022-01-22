# Do It! C++ 입문 Coding Convention
**Do It! C++ 입문**에서 사용된 예제 소스 코드에 적용된 Conding Convention을 설명하는 페이지 입니다.
## Naming Rule
본서에서 작성된 예제 소스 코드는 C++ 표준 라이브러리활용이 많기 때문에 C++ 표준 라이브러리 Naming Rule을 따릅니다.

C++ 표준 라이브러리은 Naming Rule을 ***snake_case***를 사용합니다. 따라서 본서에서도 모든 예제 코드에서는 ***snake_case***를 사용합니다. 그리고 상수 매크로 등 C언어 규칙을 사용한 경우 ***SCREAMING_SNAKE_CASE***를 사용합니다.
### *snake_case*

- 예제
~~~cpp
const string new_gen_brand("신식 회사");
const string elec_brand("전기 발명가");

class car_model {
public:
  car_model(string brand, string model, string color) 
    : brand_name(brand), model_name(model), color_name(color)
  {};

  string get_brand() { return brand_name; };
  string get_model() { return model_name; };
  string get_color() { return color_name; };

private:
  string brand_name;
  string model_name;
  string color_name;
};
~~~
### *SCREAMING_SNAKE_CASE*

- 예제
~~~cpp
#define NEW_GEN_BRAND   "신식 회사"
#define ELEC_BRAND      "전기 발명가"
~~~
